---
id: 2335
title: 'Comment afficher un exemple de toutes les polices dans Microsoft Word'
date: '2016-12-20T21:28:38+00:00'
author: wpadmin
layout: post
guid: 'http://www.end2endzone.com/?p=2335'
permalink: '/?p=2335'
'Snippet Title':
    - 'Downloadable content'
Snippet:
    - "<p>Downloads available in this article:</p>\n<div style=\"margin-bottom: 18px\">\n<p class=\"nomarginbottom\">Code:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/2339/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"2339\" template=\"title\"]</a></li>\n</ul>\n<p class=\"nomarginbottom\">Exemple de polices:</p>\n<ul class=\"fa-ul\">\n<li><a href=\"/download/2341/\"><i class=\"fa-li fa fa-download\" style=\"position: inherit;\"></i>[download id=\"2341\" template=\"title\"]</a></li>\n</ul>\n</div>\n"
hits:
    - '3224'
image: /wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg
categories:
    - Development
tags:
    - français
    - 'Microsoft Office'
    - 'open source'
---

# Introduction

À chaque fois que je travail en graphisme et que je dois ajouter du texte à une image, je me retrouve toujours avec le même problème: "Comment faire pour identifier rapidement la meilleure police pour mon affiche ?" Je crois maintenant avoir finalement trouver la solution à ce problème. Voici un script pour Microsoft Word qui permet de générer n'importe quelle exemple de texte avec toutes les polices de votre ordinateur.

# Comment ça fonctionne ?

Il suffit d'ouvrir Microsoft Word et d'exécuter le script téléchargeable. Celui-ci produira un document d'environ 65 pages avec votre exemple de texte dans toutes les polices disponibles.

# Fonctionnalités

La liste suivante décrit les fonctionnalités du script:

- Détecte toutes les polices installées du système.
- Donne un exemple de tous les styles pour chacune des polices soit: Normal, Italique, Gras et Gras Italique.
- Supporte vos propre exemples de texte. Si omis, le pangramme "*The quick brown fox jumps over the lazy dog*" est utilisé, soit l'équivalent anglophone de "*Voix ambiguë d'un cœur qui, au zéphyr, préfère les jattes de kiwis*".

# Limitations

Le script a quelques limitations. Celles-ci sont plus bas:

## Possibilité de doublons

Certaines police ne sont pas disponibles sous certain style. Par exemple, la police ***Wingdings*** n'offre pas de style *Gras* (bien que le style *Italique* soit disponible). Malheureusement, le script ne permet pas de détecter les styles qui ne sont pas disponibles et affichera donc plusieurs fois le même résultats.

# Installation

Le script peut-être utilisé de deux façons. Les sections suivantes expliquent chacune d'elle.

## Télécharger le script

Télécharger le script sur votre ordinateur en utilisant le lien suivant \[download id="2339" template="title"\]. Procédez avec les étapes suivantes pour installer le module téléchargé: 1. Ouvrir ***Microsoft Word***.
2. Naviguer au menu ***Affichage*** du ***ruban***.
3. Cliquer sur le bouton ***Macros*** pour ouvrir l'éditeur de macro Microsoft Visual Basic. [![](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)
4. Entrer un nom de macro bidon. Par exemple '*police*'.
5. Cliquer sur le bouton {{% windows-button3d %}}Créer{{% /windows-button3d %}}.
6. Dans la fenêtre Projet, repérer les deux noeuds principaux soient ***Normal*** ou ***Project (Document1)***.
7. Pour installer le script **définitivement sur l'ordinateur**, cliquer avec le bouton droit de la souris sur le noeud ***Normal***. Sinon, pour installer le script **uniquement dans ce fichier Word** (\*.docx), cliquer sur le noeud ***Project (Document1)***.
8. Sélectionner l'option ***Importer un fichier...***
9. Naviguer jusqu'à votre fichier téléchargé, sélectionnez-le et cliquer sur le bouton {{% windows-button3d %}}Ouvrir{{% /windows-button3d %}}.
10. Un nouveau noeud nommé ***Modules*** sera créer. Sous ***Modules***, vous pourrez apercevoir le nouveau module: ***ListInstalledFont***. \[caption id="attachment\_2355" align="alignnone" width="180"\][![ListInstalledFonts - Module installé sous Normal](https://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg) ListInstalledFonts - Module installé sous Normal\[/caption\]
11. Cliquer sur le l'icône de sauvegarde ( [![microsoft-word-save-icon](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg) ) pour sauvegarder le nouveau module.
12. Fermer l'éditeur de macro Microsoft Visual Basic.

Le module est maintenant installé sur le système.

## Copier coller le script

Certain fureteur ou antivirus ne permettent pas le téléchargement de module Microsoft Word (\*.bas). L'option de téléchargement du module n'est donc pas possible. Dans ce cas, l'option copier-coller doit être utilisé. Pour ce faire, copier le code suivant dans le presse-papier :

```
sample code
```

Ensuite, suivez les étapes suivante: 1. Ouvrir ***Microsoft Word***.
2. Naviguer au menu ***Affichage*** du ***ruban***.
3. Cliquer sur le bouton ***Macros*** pour ouvrir l'éditeur de macro Microsoft Visual Basic. [![](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg)
4. Entrer un nom de macro bidon. Par exemple '*police*'.
5. Cliquer sur le bouton {{% windows-button3d %}}Créer{{% /windows-button3d %}}.
6. Dans la fenêtre Projet, repérer les deux noeuds principaux soient ***Normal*** ou ***Project (Document1)***.
7. Pour installer le script définitivement sur l'ordinateur, cliquer avec le bouton droit de la souris sur le noeud ***Normal***. Sinon, pour installer le script **uniquement dans ce fichier Word** (\*.docx), cliquer sur le noeud ***Project (Document1)***.
8. Sélectionner l'option ***Insertion***, puis ***Module***.
9. Un nouveau module nommé ***Module1*** sera créé.
10. Dans la fenêtre ***Propriété - Module1***, repérer la propriété ***Name*** du module dont la valeur est ***Module1***.
11. Changer la valeur de la propriété pour la valeur ***ListInstalledFonts***.
12. Coller le code dans la section de droite de l'éditeur. Le contenu du script devrait s'afficher.
13. Cliquer sur le l'icône de sauvegarde ( [![microsoft-word-save-icon](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg) ) pour sauvegarder le nouveau module.
14. Fermer l'éditeur de macro Microsoft Visual Basic.

Le module est maintenant installé sur le système.

# Exécuter le script

Procédez avec les étapes suivantes pour exécuter le module installé: 1. Ouvrir ***Microsoft Word***.
2. Naviguer au menu ***Affichage*** du ***ruban***.
3. Cliquer sur le bouton ***Macros***. L'éditeur de macro Microsoft Visual Basic s’ouvrira.
4. Sélectionner la macro ***ListInstalledFonts***. \[caption id="attachment\_2357" align="alignnone" width="550"\][![Éditeur de macro Microsoft Word - Macro ListInstalledFonts sélectionnée](https://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg) Éditeur de macro Microsoft Word - Macro ListInstalledFonts sélectionnée\[/caption\]
5. Cliquer sur le bouton {{% windows-button3d %}}Exécuter{{% /windows-button3d %}} pour lancer l'exécution du script.
6. La fenêtre suivante s'ouvrira: \[caption id="attachment\_2354" align="alignnone" width="373"\][![ListInstalledFonts - Sélection d'un exemple de texte](https://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg) ListInstalledFonts - Sélection d'un exemple de texte\[/caption\]
7. Entrer un exemple de texte puis cliquer sur le bouton {{% windows-button3d %}}OK{{% /windows-button3d %}}. Laissez le champ vide et cliquer sur le bouton {{% windows-button3d %}}OK{{% /windows-button3d %}} pour utiliser le pangramme anglophone "*The quick brown fox jumps over the lazy dog*".
8. Patientez environ 30 secondes pendant l'exécution du script.

Le document sera complété avec votre exemple de texte pour chacune des polices installées sur votre ordinateur.

## Exemple

Après l'exécution du script, vous obtiendrez un document complet: \[caption id="attachment\_2350" align="alignnone" width="853"\][![Exemple de d'affichage toutes les polices](https://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg)](https://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg) Exemple de d'affichage toutes les polices\[/caption\]

# Licence

Le script est disponible sous la licence LGPL. Seule la version anglophone de la licence est disponible.

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version. This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details. You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA **DISCLAIMER:**This software is furnished "as is", without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.

# Téléchargement

Vous pouvez télécharger le script en cliquant sur le lien de téléchargement suivant: \[download id="2339" template="button"\]