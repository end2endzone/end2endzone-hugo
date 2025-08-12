---
title: Comment afficher un exemple de toutes les polices dans Microsoft Word
author: end2end
date: 2016-12-21T02:28:38+00:00
url: /comment-afficher-un-exemple-de-toutes-les-polices-dans-microsoft-word/
images:
  - src: /wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        Downloads available in this article:
        Code:
        * [[download id="2339" template="title"]](/download/2339/)
        Exemple de polices:
        * [[download id="2341" template="title"]](/download/2341/)
        
hits:
  - 2008
categories:
  - Development
tags:
  - français
  - Microsoft Office
  - open source

---
# Introduction

À chaque fois que je travail en graphisme et que je dois ajouter du texte à une image, je me retrouve toujours avec le même problème: "Comment faire pour identifier rapidement la meilleure police pour mon affiche ?"

Je crois maintenant avoir finalement trouver la solution à ce problème.
Voici un script pour Microsoft Word qui permet de générer n'importe quelle exemple de texte avec toutes les polices de votre ordinateur.

# Comment ça fonctionne ?

Il suffit d'ouvrir Microsoft Word et d'exécuter le script téléchargeable. Celui-ci produira un document d'environ 65 pages avec votre exemple de texte dans toutes les polices disponibles.

# Fonctionnalités

La liste suivante décrit les fonctionnalités du script:

* Détecte toutes les polices installées du système.
* Donne un exemple de tous les styles pour chacune des polices soit:  Normal, Italique, Gras et Gras Italique.
* Supporte vos propre exemples de texte. Si omis, le pangramme "_The quick brown fox jumps over the lazy dog_" est utilisé, soit l'équivalent anglophone de "_Voix ambiguë d'un cœur qui, au zéphyr, préfère les jattes de kiwis_".

# Limitations

Le script a quelques limitations. Celles-ci sont plus bas:

## Possibilité de doublons

Certaines police ne sont pas disponibles sous certain style. Par exemple, la police **_Wingdings_** n'offre pas de style _Gras_ (bien que le style _Italique_ soit disponible).

Malheureusement, le script ne permet pas de détecter les styles qui ne sont pas disponibles et affichera donc plusieurs fois le même résultats.

# Installation

Le script peut-être utilisé de deux façons. Les sections suivantes expliquent chacune d'elle.

## Télécharger le script

Télécharger le script sur votre ordinateur en utilisant le lien suivant  

	[ MsWordListInstalledFont.bas](http://www.end2endzone.com/download/2339/ "Version 1.0").

Procédez avec les étapes suivantes pour installer le module téléchargé:

* Ouvrir _**Microsoft Word**_.
* Naviguer au menu **_Affichage_** du **_ruban_**.
* Cliquer sur le bouton _**Macros**_ pour ouvrir l'éditeur de macro Microsoft Visual Basic.<br /> [![](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)
* Entrer un nom de macro bidon. Par exemple '_police_'.
* Cliquer sur le bouton Créer.
* Dans la fenêtre Projet, repérer les deux noeuds principaux soient _**Normal**_ ou _**Project (Document1)**_.
* Pour installer le script **définitivement sur l'ordinateur**, cliquer avec le bouton droit de la souris sur le noeud _**Normal**_.<br /> Sinon, pour installer le script **uniquement dans ce fichier Word** (*.docx), cliquer sur le noeud _**Project (Document1)**_.
* Sélectionner l'option _**Importer un fichier...**_
* Naviguer jusqu'à votre fichier téléchargé, sélectionnez-le et cliquer sur le bouton Ouvrir.
<li>
  Un nouveau noeud nommé _**Modules**_ sera créer. Sous **_Modules_**, vous pourrez apercevoir le nouveau module:&nbsp;_**ListInstalledFont**_. <p>
    <div id="attachment_2355" style="width: 190px" class="wp-caption alignnone">
      [![ListInstalledFonts - Module installé sous Normal](http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg)
      
      <p id="caption-attachment-2355" class="wp-caption-text">
        ListInstalledFonts - Module installé sous Normal
      </p>
    </div>
</li> 
    
    * Cliquer sur le l'icône de sauvegarde (&nbsp;[![microsoft-word-save-icon](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg)&nbsp;)&nbsp;pour sauvegarder le nouveau module.
    * Fermer l'éditeur de macro Microsoft Visual Basic.</ol> 
    
    Le module est maintenant installé sur le système.
    
    <h2>
      Copier coller le script
    </h2>
    
    Certain fureteur ou antivirus ne permettent pas le téléchargement de module Microsoft Word (*.bas). L'option de téléchargement du module n'est donc pas possible. Dans ce cas, l'option copier-coller doit être utilisé.
    
    Pour ce faire, copier le code suivant dans le presse-papier :
    
    {{< hightlight-static-file file="/static/wp-content/uploads/2016/12/MsWordListInstalledFont.bas" lang="vb" >}}
    
    Ensuite, suivez les étapes suivante:
    
    <ol>
      * Ouvrir _**Microsoft Word**_.
      * Naviguer au menu **_Affichage_** du **_ruban_**.
      * Cliquer sur le bouton _**Macros**_ pour ouvrir l'éditeur de macro Microsoft Visual Basic.<br /> [![](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)
      * Entrer un nom de macro bidon. Par exemple '_police_'.
      * Cliquer sur le bouton Créer.
      * Dans la fenêtre Projet, repérer les deux noeuds principaux soient _**Normal**_ ou _**Project (Document1)**_.
      * Pour installer le script définitivement sur l'ordinateur, cliquer avec le bouton droit de la souris sur le noeud _**Normal**_.<br /> Sinon, pour installer le script **uniquement dans ce fichier Word** (*.docx), cliquer sur le noeud _**Project (Document1)**_.
      * Sélectionner l'option **_Insertion_**, puis **_Module_**.
      * Un nouveau module nommé **_Module1_** sera créé.
      * Dans la fenêtre _**Propriété - Module1**_, repérer la propriété **_Name_** du module dont la valeur est _**Module1**_.
      * Changer la valeur de la propriété pour la valeur _**ListInstalledFonts**_.
      * Coller le code dans la section de droite de l'éditeur. Le contenu du script devrait s'afficher.
      * Cliquer sur le l'icône de sauvegarde (&nbsp;[![microsoft-word-save-icon](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg)&nbsp;)&nbsp;pour sauvegarder le nouveau module.
      * Fermer l'éditeur de macro Microsoft Visual Basic.
    </ol>
    
    Le module est maintenant installé sur le système.
    
    <h1>
      Exécuter le script
    </h1>
    
    Procédez avec les étapes suivantes pour exécuter le module installé:
    
    <ol>
      * Ouvrir _**Microsoft Word**_.
      * Naviguer au menu _**Affichage**_ du _**ruban**_.
      * Cliquer sur le bouton _**Macros**_. L'éditeur de macro Microsoft Visual Basic s’ouvrira.
      <li>
        Sélectionner la macro _**ListInstalledFonts**_. <p>
          <div id="attachment_2357" style="width: 560px" class="wp-caption alignnone">
            [![Éditeur de macro Microsoft Word - Macro ListInstalledFonts sélectionnée](http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg)
            
            <p id="caption-attachment-2357" class="wp-caption-text">
              Éditeur de macro Microsoft Word - Macro ListInstalledFonts sélectionnée
            </p>
          </div>
</li> 
          
          * Cliquer sur le bouton Exécuter pour lancer l'exécution du script.
          <li>
            La fenêtre suivante s'ouvrira: <p>
              <div id="attachment_2354" style="width: 383px" class="wp-caption alignnone">
                [![ListInstalledFonts - Sélection d'un exemple de texte](http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg)
                
                <p id="caption-attachment-2354" class="wp-caption-text">
                  ListInstalledFonts - Sélection d'un exemple de texte
                </p>
              </div>
</li> 
              
              * Entrer un exemple de texte puis cliquer sur le bouton OK. Laissez le champ vide et cliquer sur le bouton OK pour utiliser le pangramme anglophone "_The quick brown fox jumps over the lazy dog_".
              * Patientez environ 30 secondes pendant l'exécution du script.</ol> 
              
              Le document sera complété avec votre exemple de texte pour chacune des polices installées sur votre ordinateur.
              
              <h2>
                Exemple
              </h2>
              
              Après l'exécution du script, vous obtiendrez un document complet:
              
              <p>
                <div id="attachment_2350" style="width: 863px" class="wp-caption alignnone">
                  [![Exemple de d'affichage toutes les polices](http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg)](http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg)
                  
                  <p id="caption-attachment-2350" class="wp-caption-text">
                    Exemple de d'affichage toutes les polices
                  </p>
                </div>
              </p>
              
              <h1>
                Licence
              </h1>
              
              {{< pleasenote >}}
  Le script est disponible sous la licence LGPL. Seule la version anglophone de la licence est disponible.
{{< /pleasenote >}}

              
              This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.
              
              This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.
              
              You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
              
              **DISCLAIMER:**<br /> This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.
              
              <h1>
                Téléchargement
              </h1>
              
              Vous pouvez télécharger le script en cliquant sur le lien de téléchargement suivant:
              
              <p>
                <p>
                  [ Download "MsWordListInstalledFont.bas" MsWordListInstalledFont.bas - Downloaded 1068 times - 3 KB ](http://www.end2endzone.com/download/2339/)
                </p>
              </p>