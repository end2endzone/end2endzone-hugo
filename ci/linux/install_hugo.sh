#!/bin/bash
set -e
curl -L -O https://github.com/gohugoio/hugo/releases/download/v0.147.9/hugo_extended_0.147.9_linux-amd64.deb
dpkg -i hugo_extended_*_linux-amd64.deb
rm hugo_extended_*_linux-amd64.deb
