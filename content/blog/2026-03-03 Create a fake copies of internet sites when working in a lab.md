---
title: Create a fake copies of internet sites when working in a lab
author: end2end
date: 2026-03-03
categories:
  - Tutorial
tags:
  - Tutorial
toc: true
toc_default_close: true
draft: true
---



# Problem / Context

Development takes place inside a secure R&D lab where internet access is strictly forbidden due to confidentiality or regulatory requirements.

However many tools are designed with internet access in mind. Even if they provide a downloadable installation package for offline usage, these tools often requires an internet connection to download additionnal packages to function properly. In a lab environment without internet access these tools do not behaves properly.

Other times, tools requires internet for simple task such as to check if there is a new version available. Without an internet access, they sometimes wait multiple minutes until the verification times out. This makes the tool slow and painfull to use in a lab environment without internet access.



# Description

This document describes how to create a fake https server that uses self-signed certificates for faking internet access in an offline environment.

This document will create a local duplicate of the following URLs:
* https://imagemagick.org/archive/binaries/ImageMagick-7.1.2-15-portable-Q8-x64.7z
* https://www.7-zip.org/a/7z2600-x64.exe

At the time of this writing, the current IP of the hosts listed above is:
* imagemagick.org → 50.251.58.13
* www.7-zip.org → 49.12.202.237



# Architecture

Clean architecture recommendation:

| Domain          | Purpose           |
|-----------------|-------------------|
| imagemagick.org | fake site         |
| www.7-zip.org   | fake site         |
| 7-zip.org       | fake site         |
| pki.local       | CA infrastructure |

Configuration:
* Our domain certificates will be signed with our CA certificate.
* Our CA certificate will be hosted on domain `pki.local` (which is also fake and hosted on the same Apache httpd server)



# Common TLS/PKI acronyms and terminology

## CA - Certificate Authority
* A trusted entity that signs certificates.
* Uses its own private key to validate that a certificate is legitimate.
* Your CA signs CSRs to produce server certificates.

## CNF - Configuration File
* A plain‑text OpenSSL configuration file.
* Controls how keys, CSRs, and certificates are generated.
Examples:
* myCA.cnf → config for your CA
* 7zip.cnf → config for generating a CSR for a domain

## CSR - Certificate Signing Request
* A file containing:
  * the domain name(s)
  * the public key
  * optional SANs (Subject Alternative Names)
* Generated from a private key.
* Sent to a CA, which signs it to produce a certificate.
Relationship:  
Private Key → generates → CSR → signed by CA → produces → Certificate (.crt)

## CRT - Certificate
* The final signed certificate issued by the CA.
* Usually in PEM format, even if the extension is .crt.
* Contains:
  * public key
  * SANs
  * validity dates
  * CA signature

Relationship:  
CSR → signed by CA → produces → CRT

## CRL - Certificate Revocation List
A CRL is a digitally signed list, published by a Certificate Authority (CA), that identifies certificates that are no longer trusted before their normal expiration date. Certificates can be revoked for many reasons. Instead of waiting for the certificate to expire, the CA marks it as revoked and publishes that information in the CRL.


## PEM - Privacy Enhanced Mail (format)
* A file format used as a container, not a certificate type.
* Base64‑encoded text wrapped in:
```
-----BEGIN CERTIFICATE-----
...
-----END CERTIFICATE-----
```
Can contain:
* certificates (.pem)
* private keys (.key)
* CA bundles
* CSRs



# Workflow

Here's the workflow in order:

1. Generate private key for a domain  
   → file `domain.key`
2. Generate CSR using the key + CNF  
   → file `domain.csr`
3. CA signs the CSR using its own config (myCA.cnf)  
   → file `domain.crt`
4. Certificate is stored in PEM format  
   → `.crt` or `.pem` (same format, different naming convention)
5. Apache uses
   * `domain.crt` (certificate)
   * `domain.key` (private key)
   * `myCA.pem.crt` (CA certificate)



# Configuration steps

## Install Apache httpd web server

### Download
Download apache lounge / httpd :
* https://httpd.apache.org/
* Click on _Download_ link
* Click on [Files for Microsoft Windows](https://httpd.apache.org/docs/current/platform/windows.html#down).
* Click on [Apache Lounge](http://www.apachelounge.com/download/).
* Download url: https://www.apachelounge.com/download/VS18/binaries/httpd-2.4.66-260223-Win64-VS18.zip

### Extract to local directory
Use 7-zip to extract the zip file to `C:\`. The extraction process should create directory `C:\Apache24`.

## Update PATH
Add `C:\Apache24\bin` to PATH

or use the following command when you open a new command prompt:
```
set PATH=C:\Apache24\bin;%PATH%
```

## Create entries in Windows hosts file
Edit file `C:\Windows\System32\drivers\etc\hosts`.  
Add an entry that resolve to 127.0.0.1 for every web site you want to emulate.

For example::
```
127.0.0.1 imagemagick.org
127.0.0.1 www.7-zip.org
127.0.0.1 7-zip.org
127.0.0.1 pki.local
```

## Setup a new CA infrastructure


### Create Working Directory for the CA's database
```
mkdir C:\Apache24\workspace
cd /d C:\Apache24\workspace
mkdir my-local-ca-database
mkdir my-local-ca-database\newcerts
type nul > my-local-ca-database\index.txt
echo 01 > my-local-ca-database\serial
echo 01 > my-local-ca-database\crlnumber
```

### Create CA Config File
Create file `C:\Apache24\workspace\myCA.cnf`
```
[ ca ]
default_ca = CA_default

[ CA_default ]
dir               = ./my-local-ca-database
database          = $dir/index.txt
new_certs_dir     = $dir/newcerts
certificate       = ./myCA.pem
private_key       = ./myCA.key
serial            = $dir/serial
crlnumber         = $dir/crlnumber
default_md        = sha256
policy            = policy_any
default_days      = 3650
default_crl_days  = 3650
copy_extensions   = copy

[ policy_any ]
commonName = supplied

[ req ]
distinguished_name = dn

[ dn ]

[ v3_server ]
crlDistributionPoints = URI:http://pki.local/crl.pem
```


### Create a Root CA certificate
```
cd /d C:\Apache24\workspace
openssl genrsa -out myCA.key 2048
openssl req -x509 -new -nodes -key myCA.key -sha256 -days 3650 -out myCA.pem -subj "/CN=MyLocalCA"
```


### Copy Root CA certificate to Apache conf directory
myCA.pem → C:\Apache24\conf\


### Install CA in Windows
1. Start MMC.exe
2. File, Add/remove snap-in...
3. Select _Certificates_
4. Click on button _Add >_.
5. Select _Computer account_. Then _Next_.
6. Select _Local computer_. Then _Finish_.
7. Click OK
8. Expand "Certificates (Local Computer)" in left panel.
9. Open _Trusted Root Certification Autorities_.
10. Right-click on _Certificates_, select menu _All Tasks/Import..._.
11. Click _Next_.
12. Browse to C:\Apache24\workspace. Filter for _All Files_. Select file `myCA.pem` and click _Open_.
13. Click _Next_.
14. Select option _Place all certificates in the following store_ and validate that _Certificate Store_ is set to `Trusted Root Certification Authorities`.
15. Click _Next_.
16. Click _Finish_.
17. Validate that `MyLocalCA` is found in the list of certificates.

## Configure Apache for HTTPS
Edit file `C:\Apache24\conf\httpd.conf`:  
Uncomment the following lines:
  * `# LoadModule socache_shmcb_module modules/mod_socache_shmcb.so`
  * `# LoadModule ssl_module modules/mod_ssl.so`
  * `#Include conf/extra/httpd-ssl.conf`

Edit file `C:\Apache24\conf\extra\httpd-ssl.conf`:  
Comment the xml node `<VirtualHost _default_:443>`.
  * Add `#     ` in front of all lines from `<VirtualHost _default_:443>` up to `</VirtualHost>`.


## Create a new certificate for all fake domain

### Create a certificate for a domain

#### Create file a Configuration File

Create file `C:\Apache24\workspace\7zip.cnf`:
```
[ req ]
default_bits = 2048
prompt = no
default_md = sha256
req_extensions = req_ext
distinguished_name = dn

[ dn ]
CN = 7zip.org

[ req_ext ]
subjectAltName = @alt_names

[ alt_names ]
DNS.1 = www.7-zip.org
DNS.2 = 7-zip.org
```

This will produce a CSR with:
* CN = 7zip.org
* SAN = www.7-zip.org, 7-zip.org

The CN does not need to list all domains. Modern TLS clients ignore CN for hostname validation anyway.
The SAN extension is the authoritative source.


#### Generate Key + CSR
```
openssl genrsa -out 7zip.key 2048
openssl req -new -key 7zip.key -out 7zip.csr -config 7zip.cnf
```

#### Generate the private key
`openssl genrsa -out 7zip.key 2048`

#### Generate the CSR using your CSR config
`openssl req -new -key 7zip.key -out 7zip.csr -config 7zip.cnf`

#### Verify the CSR contains the correct SAN
`openssl req -in 7zip.csr -text -noout`

Look for the following in the output for a confirmation:
```
X509v3 Subject Alternative Name:
    DNS:www.7-zip.org, DNS:7-zip.org
```

#### Sign the CSR with your CA
`openssl ca -config myCA.cnf -in 7zip.csr -out 7zip.crt -extensions v3_server`

Output:
```
Using configuration from myCA.cnf
Check that the request matches the signature
Signature ok
The Subject's Distinguished Name is as follows
commonName            :ASN.1 12:'7zip.org'
Certificate is to be certified until Feb 22 15:54:27 2036 GMT (3650 days)
Sign the certificate? [y/n]:y


1 out of 1 certificate requests certified, commit? [y/n]y
Write out database with 1 new entries
Database updated
```

#### Verify the final certificate
`openssl x509 -in 7zip.crt -text -noout`

Look for the following in the output for a confirmation:
```
X509v3 Subject Alternative Name:
    DNS:www.7-zip.org, DNS:7-zip.org
```

#### Copy new files to Apache conf directory
7zip.crt → C:\Apache24\conf\
7zip.key → C:\Apache24\conf\

#### Modify Apache's HTTPS conf settings to expose the new domain
Edit file `C:\Apache24\conf\extra\httpd-ssl.conf`.
Add the following section:
```xml
<VirtualHost *:443>
    ServerName 7-zip.org
    ServerAlias www.7-zip.org

    DocumentRoot "C:/Apache24/htdocs/7-zip.org"

    SSLEngine on
    SSLCertificateFile "C:/Apache24/conf/7zip.crt"
    SSLCertificateKeyFile "C:/Apache24/conf/7zip.key"
    SSLCertificateChainFile "C:/Apache24/conf/myCA.pem"
</VirtualHost>
```

#### Create the directory structure in Apache's htdocs directory
```
cd /d C:\Apache24\htdocs
mkdir 7-zip.org\a
```

#### Add the fake downloadable exe file under the new directory structure

```
copy "%SystemRoot%\notepad.exe" C:\Apache24\htdocs\7-zip.org\a\7z2600-x64.exe
```

### Repeat for other domains
Repeat the steps `Create a certificate for a domain` for all other domains:
* `imagemagick.org`

That is:

* Create domain Configuration Files :
  * `C:\Apache24\workspace\imagemagick.cnf`:
    ```
    [ req ]
    default_bits = 2048
    prompt = no
    default_md = sha256
    req_extensions = req_ext
    distinguished_name = dn

    [ dn ]
    CN = imagemagick.org

    [ req_ext ]
    subjectAltName = @alt_names

    [ alt_names ]
    DNS.1 = imagemagick.org
    ```
* Execute commands such as :
  ```
  cd /d C:\Apache24\workspace
  openssl genrsa -out imagemagick.key 2048
  openssl req -new -key imagemagick.key -out imagemagick.csr -config imagemagick.cnf
  openssl genrsa -out imagemagick.key 2048
  openssl req -new -key imagemagick.key -out imagemagick.csr -config imagemagick.cnf
  openssl ca -config myCA.cnf -in imagemagick.csr -out imagemagick.crt -extensions v3_server
  ```
* Copy `*.crt` and `*.key` to `C:\Apache24\conf\` :
  ```
  imagemagick.crt → C:\Apache24\conf\
  imagemagick.key → C:\Apache24\conf\
  ```
* Add the following to `C:\Apache24\conf\extra\httpd-ssl.conf` :
  ```xml
  <VirtualHost *:443>
      ServerName imagemagick.org

      DocumentRoot "C:/Apache24/htdocs/imagemagick.org"

      SSLEngine on
      SSLCertificateFile "C:/Apache24/conf/imagemagick.crt"
      SSLCertificateKeyFile "C:/Apache24/conf/imagemagick.key"
      SSLCertificateChainFile "C:/Apache24/conf/myCA.pem"
  </VirtualHost>
  ```
* Create fake download files :
  * mkdir C:\Apache24\htdocs\imagemagick.org\archive\binaries
  * `C:\Apache24\htdocs\imagemagick.org\archive\binaries\ImageMagick-7.1.2-15-portable-Q8-x64.7z`


### Generate a new CRL
Since the CA has a new certificates in its database, export a new crl.pem:  
`openssl ca -config myCA.cnf -gencrl -out crl.pem`:

Output:
```
Using configuration from myCA.cnf
```

### Copy new crl.pem to Apache's htdocs
crl.pem → C:\Apache24\htdocs\

### Modify Apache config to server the CRL file
Edit the file `C:\Apache24\conf\httpd.conf`.  
Add the following:
```xml
# Serve http://pki.local/crl.pem
<VirtualHost *:80>
    ServerName pki.local

    DocumentRoot "C:/Apache24/htdocs"
    
    <Directory "C:/Apache24/htdocs">
        Require all granted
    </Directory>
</VirtualHost>
```

### Setup Apache fully qualified domain name (FQDN)

Apache wants to know the server's fully qualified domain name (FQDN) so it can use it for things like redirects, self‑referencing URLs, and log messages.

If Apache doesn't find a global ServerName directive, it falls back to whatever the OS returns for the hostname

Even though Apache is configured with `ServerName` inside a all `<VirtualHost>`, Apache still expects a global one.

Replace the line `#ServerName www.example.com:80` with `ServerName localhost:80` in file `conf\httpd.conf`.

Without the change, you get the following output error when running httpd.exe:
```
AH00558: httpd.exe: Could not reliably determine the server's fully qualified domain name, using ::1. Set the 'ServerName' directive globally to suppress this message
```

### Start Apache httpd server
httpd.exe




# Testing

## Check if CRL is served
```
curl http://pki.local/crl.pem
```
File should download.

SUCCESS!

## Check imagemagick.org https certificate
```
curl https://imagemagick.org/archive/binaries/imagemagick-7.1.2-15-portable-Q8-x64.7z --output foo-imagemagick.7z
```
File should download.

SUCCESS!

## Check 7zip.org and www.7-zip.org https certificate
```
curl https://7-zip.org/a/7z2600-x64.exe --output foo-7zip.exe
curl https://www.7-zip.org/a/7z2600-x64.exe --output foo-www7zip.exe
```
Bith files should download.

SUCCESS!



# Debugging:

## Skip certificate checks
Explaination: 
* option `-k` disables:
  * hostname verification
  * trust verification
  
  So even if the cert says DNS:something.else.com, it will still download.  
  Normal curl enforces hostname match.
* option `-v` enables verbose output.

`curl -vk https://www.7-zip.org/a/7z2600-x64.exe --output foo-www7zip.exe`

If Apache is configured to serve the file, you should see the following output.

Expected output:
```
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed  
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0* Host www.7-zip.org:443 was resolved.
* IPv6: (none)
* IPv4: 127.0.0.1
*   Trying 127.0.0.1:443...
* schannel: disabled automatic use of client certificate
* ALPN: curl offers http/1.1
* ALPN: server accepted http/1.1
* Connected to www.7-zip.org (127.0.0.1) port 443
* using HTTP/1.x
> GET /a/7z2600-x64.exe HTTP/1.1
> Host: www.7-zip.org
> User-Agent: curl/8.13.0
> Accept: */*
>
< HTTP/1.1 200 OK
< Date: Fri, 13 Mar 2026 13:56:38 GMT
< Server: Apache/2.4.66 (Win64) OpenSSL/3.6.1 
< Last-Modified: Fri, 30 May 2025 00:45:20 GMT
< ETag: "31000-6364fba95ed95"
< Accept-Ranges: bytes
< Content-Length: 200704
< Content-Type: application/x-msdownload
<
{ [89850 bytes data]
100  196k  100  196k    0     0  4924k      0 --:--:-- --:--:-- --:--:-- 5157k
* Connection #0 to host www.7-zip.org left intact
```


## Validate a CSR file:
`openssl req -in name.csr -text -noout`

Look for the following in the output:
```
X509v3 Subject Alternative Name:
    DNS:name.com
```


## Validate a CRT file:
`openssl x509 -in imagemagick.crt -text -noout`

Look for the following in the output:
```
X509v3 Subject Alternative Name:
    DNS:name.com
```


## Check that a certificate is signed by your CA:
`openssl verify -CAfile myCA.pem imagemagick.crt`

Expected output:
```
imagemagick.crt: OK
```


## Check that a certificate's issuer matches your CA's subject:
`openssl x509 -in imagemagick.crt -noout -issuer`

Expected output:
```
issuer=CN=MyLocalCA
```

Must match the output of command:  
`openssl x509 -in myCA.pem -noout -subject`

Expected output:
```
subject=CN=MyLocalCA
```


## Verify CRL --> CA chain:
`openssl verify -crl_check -CAfile myCA.pem -CRLfile crl.pem imagemagick.crt`

Expected output:
```
imagemagick.crt: OK
```


## Verify your traffic do not go through a proxy
`netsh winhttp show proxy`

Expected output:
```
Direct access (no proxy server).
```

In powershell:  
`[System.Net.WebRequest]::GetSystemWebProxy().GetProxy("http://pki.local")`

Expected output:
```
AbsolutePath   : /
AbsoluteUri    : http://pki.local/
LocalPath      : /
Authority      : pki.local
HostNameType   : Dns
IsDefaultPort  : True
IsFile         : False
IsLoopback     : False
PathAndQuery   : /
Segments       : {/}
IsUnc          : False
Host           : pki.local
Port           : 80
Query          :
Fragment       :
Scheme         : http
OriginalString : http://pki.local
DnsSafeHost    : pki.local
IdnHost        : pki.local
IsAbsoluteUri  : True
UserEscaped    : False
UserInfo       :
```

If your output is different than above, your system is configured with a proxy.



## Issue - The certificate chain was issued by an authority that is not trusted. SEC_E_UNTRUSTED_ROOT (0x80090325)

`curl https://www.7-zip.org/a/7z2600-x64.exe --output foo-7zip.exe`

Output:
```
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
curl: (60) schannel: SEC_E_UNTRUSTED_ROOT (0x80090325) - The certificate chain was issued by an authority that is not trusted.
More details here: https://curl.se/docs/sslcerts.html

curl failed to verify the legitimacy of the server and therefore could not
establish a secure connection to it. To learn more about this situation and
how to fix it, please visit the webpage mentioned above.
```

Explication:  
You probably did not imported myCA certificate as a Trusted Root Certification Authorities


## Issue - The certificate is revoked. CRYPT_E_REVOKED (0x80092010)
`curl https://www.7-zip.org/a/7z2600-x64.exe --output foo-7zip.exe`

Output:
```
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
curl: (35) schannel: next InitializeSecurityContext failed: CRYPT_E_REVOKED (0x80092010) - The certificate is revoked.
```

Explication:  
The certificate was revoked in the CA database, or the file `C:/Apache24/conf/7zip.crt` is outdated. You must :
* Regenerate a new certificate.
* Sign the certificate with the CA.
* Export a new `crl.pem` from the CA database's.
* Copy `crl.pem` to `C:\Apache24\htdocs\crl.pem`.


## Issue - The revocation function was unable to check revocation because the revocation server was offline. CRYPT_E_REVOCATION_OFFLINE (0x80092013)
`curl https://www.7-zip.org/a/7z2600-x64.exe --output foo-7zip.exe`

Output:
```
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0
curl: (35) schannel: next InitializeSecurityContext failed: CRYPT_E_REVOCATION_OFFLINE (0x80092013) - The revocation function was unable to check revocation because the revocation server was offline.
```

Explication:
* Curl is unable to reach your CRL.
* Check with command `curl -v http://pki.local/crl.pem` to see if the file can be served.
* Make sure you have a virtualhost for serving pki.local domain over http (not https).
* Check your proxy settings. Disable proxy for `pki.local` and your other domains:
  * Go to Windows _Settings_, _Network & Internet_, _Proxy_.
  * Under section "_Manual Proxy setup_", locate the text field "_Use the proxy server except for addresses that starts with the following entries_".
  * Add the following at the beginning: `127.0.0.1;*.local;`. You can also add this value to the registry key `[HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows\CurrentVersion\Internet Settings]`, and modify the _String Value_ named `ProxyOverride`.
