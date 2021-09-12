---
title: Comment afficher un exemple de toutes les polices dans Microsoft Word
author: end2end
type: post
date: 2016-12-21T02:28:38+00:00
url: /comment-afficher-un-exemple-de-toutes-les-polices-dans-microsoft-word/
featured_image: /wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word-672x378.jpg
Snippet Title:
  - Downloadable content
Snippet:
  - |
    |
        <p>Downloads available in this article:</p>
        <div style="margin-bottom: 18px">
        <p class="nomarginbottom">Code:</p>
        <ul class="fa-ul">
        <li><a href="/download/2339/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2339" template="title"]</a></li>
        </ul>
        <p class="nomarginbottom">Exemple de polices:</p>
        <ul class="fa-ul">
        <li><a href="/download/2341/"><i class="fa-li fa fa-download" style="position: inherit;"></i>[download id="2341" template="title"]</a></li>
        </ul>
        </div>
        
hits:
  - 2008
categories:
  - Development
tags:
  - français
  - Microsoft Office
  - open source

---
# <span id="Introduction">Introduction</span>

À chaque fois que je travail en graphisme et que je dois ajouter du texte à une image, je me retrouve toujours avec le même problème: &#8220;Comment faire pour identifier rapidement la meilleure police pour mon affiche ?&#8221;

Je crois maintenant avoir finalement trouver la solution à ce problème.<!--more-->

Voici un script pour Microsoft Word qui permet de générer n&#8217;importe quelle exemple de texte avec toutes les polices de votre ordinateur.

# <span id="Comment_ca_fonctionne">Comment ça fonctionne ?</span>

Il suffit d&#8217;ouvrir Microsoft Word et d&#8217;exécuter le script téléchargeable. Celui-ci produira un document d&#8217;environ 65 pages avec votre exemple de texte dans toutes les polices disponibles.

# <span id="Fonctionnalites">Fonctionnalités</span>

La liste suivante décrit les fonctionnalités du script:

<li style="text-align: justify;">
  Détecte toutes les polices installées du système.
</li>
<li style="text-align: justify;">
  Donne un exemple de tous les styles pour chacune des polices soit:  Normal, Italique, Gras et Gras Italique.
</li>
<li style="text-align: justify;">
  Supporte vos propre exemples de texte. Si omis, le pangramme &#8220;<em>The quick brown fox jumps over the lazy dog</em>&#8221; est utilisé, soit l&#8217;équivalent anglophone de &#8220;<em>Voix ambiguë d&#8217;un cœur qui, au zéphyr, préfère les jattes de kiwis</em>&#8220;.
</li>

# <span id="Limitations">Limitations</span>

Le script a quelques limitations. Celles-ci sont plus bas:

## <span id="Possibilite_de_doublons">Possibilité de doublons</span>

Certaines police ne sont pas disponibles sous certain style. Par exemple, la police **_Wingdings_** n&#8217;offre pas de style _Gras_ (bien que le style _Italique_ soit disponible).

Malheureusement, le script ne permet pas de détecter les styles qui ne sont pas disponibles et affichera donc plusieurs fois le même résultats.

# <span id="Installation">Installation</span>

Le script peut-être utilisé de deux façons. Les sections suivantes expliquent chacune d&#8217;elle.

## <span id="Telecharger_le_script">Télécharger le script</span>

Télécharger le script sur votre ordinateur en utilisant le lien suivant  

	<a class="download-link" title="Version 1.0" href="http://www.end2endzone.com/download/2339/" rel="nofollow"> MsWordListInstalledFont.bas</a>.

Procédez avec les étapes suivantes pour installer le module téléchargé:

<li style="text-align: justify;">
  Ouvrir <em><strong>Microsoft Word</strong></em>.
</li>
<li style="text-align: justify;">
  Naviguer au menu <strong><em>Affichage</em></strong> du <strong><em>ruban</em></strong>.
</li>
<li style="text-align: justify;">
  Cliquer sur le bouton <em><strong>Macros</strong></em> pour ouvrir l&#8217;éditeur de macro Microsoft Visual Basic.<br /> <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg" rel="attachment wp-att-2356"><img loading="lazy" class="alignnone wp-image-2356 size-full" src="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg" alt="" width="50" height="85" /></a>
</li>
<li style="text-align: justify;">
  Entrer un nom de macro bidon. Par exemple &#8216;<em>police</em>&#8216;.
</li>
<li style="text-align: justify;">
  Cliquer sur le bouton <span class="button3D">Créer</span>.
</li>
<li style="text-align: justify;">
  Dans la fenêtre Projet, repérer les deux noeuds principaux soient <em><strong>Normal</strong></em> ou <em><strong>Project (Document1)</strong></em>.
</li>
<li style="text-align: justify;">
  Pour installer le script <strong>définitivement sur l&#8217;ordinateur</strong>, cliquer avec le bouton droit de la souris sur le noeud <em><strong>Normal</strong></em>.<br /> Sinon, pour installer le script <strong>uniquement dans ce fichier Word</strong> (*.docx), cliquer sur le noeud <em><strong>Project (Document1)</strong></em>.
</li>
<li style="text-align: justify;">
  Sélectionner l&#8217;option <em><strong>Importer un fichier&#8230;</strong></em>
</li>
<li style="text-align: justify;">
  Naviguer jusqu&#8217;à votre fichier téléchargé, sélectionnez-le et cliquer sur le bouton <span class="button3D">Ouvrir</span>.
</li>
<li style="text-align: justify;">
  Un nouveau noeud nommé <em><strong>Modules</strong></em> sera créer. Sous <strong><em>Modules</em></strong>, vous pourrez apercevoir le nouveau module: <em><strong>ListInstalledFont</strong></em>. <p>
    <div id="attachment_2355" style="width: 190px" class="wp-caption alignnone">
      <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg" rel="attachment wp-att-2355"><img aria-describedby="caption-attachment-2355" loading="lazy" class="size-full wp-image-2355" src="http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg" alt="ListInstalledFonts - Module installé sous Normal" width="180" height="197" srcset="http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal.jpg 180w, http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Module-installé-sous-Normal-137x150.jpg 137w" sizes="(max-width: 180px) 100vw, 180px" /></a>
      
      <p id="caption-attachment-2355" class="wp-caption-text">
        ListInstalledFonts &#8211; Module installé sous Normal
      </p>
    </div></li> 
    
    <li style="text-align: justify;">
      Cliquer sur le l&#8217;icône de sauvegarde ( <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg" rel="attachment wp-att-2360"><img loading="lazy" class="alignnone size-full wp-image-2360" src="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg" alt="microsoft-word-save-icon" width="16" height="16" /></a> ) pour sauvegarder le nouveau module.
    </li>
    <li style="text-align: justify;">
      Fermer l&#8217;éditeur de macro Microsoft Visual Basic.
    </li></ol> 
    
    <p>
      Le module est maintenant installé sur le système.
    </p>
    
    <h2>
      <span id="Copier_coller_le_script">Copier coller le script</span>
    </h2>
    
    <p>
      Certain fureteur ou antivirus ne permettent pas le téléchargement de module Microsoft Word (*.bas). L&#8217;option de téléchargement du module n&#8217;est donc pas possible. Dans ce cas, l&#8217;option copier-coller doit être utilisé.
    </p>
    
    <p>
      Pour ce faire, copier le code suivant dans le presse-papier :
    </p>
    
    <pre class="height-set:true height:400 lang:vb decode:true" title="ListInstalledFont - Microsoft Word Script" data-url="http://www.end2endzone.com/wp-content/uploads/2016/12/MsWordListInstalledFont.bas">sample code</pre>
    
    <p>
      Ensuite, suivez les étapes suivante:
    </p>
    
    <ol>
      <li style="text-align: justify;">
        Ouvrir <em><strong>Microsoft Word</strong></em>.
      </li>
      <li style="text-align: justify;">
        Naviguer au menu <strong><em>Affichage</em></strong> du <strong><em>ruban</em></strong>.
      </li>
      <li style="text-align: justify;">
        Cliquer sur le bouton <em><strong>Macros</strong></em> pour ouvrir l&#8217;éditeur de macro Microsoft Visual Basic.<br /> <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg" rel="attachment wp-att-2356"><img loading="lazy" class="alignnone wp-image-2356 size-full" src="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Menu-Macros-du-Ruban.jpg" alt="" width="50" height="85" /></a>
      </li>
      <li style="text-align: justify;">
        Entrer un nom de macro bidon. Par exemple &#8216;<em>police</em>&#8216;.
      </li>
      <li style="text-align: justify;">
        Cliquer sur le bouton <span class="button3D">Créer</span>.
      </li>
      <li style="text-align: justify;">
        Dans la fenêtre Projet, repérer les deux noeuds principaux soient <em><strong>Normal</strong></em> ou <em><strong>Project (Document1)</strong></em>.
      </li>
      <li style="text-align: justify;">
        Pour installer le script définitivement sur l&#8217;ordinateur, cliquer avec le bouton droit de la souris sur le noeud <em><strong>Normal</strong></em>.<br /> Sinon, pour installer le script <strong>uniquement dans ce fichier Word</strong> (*.docx), cliquer sur le noeud <em><strong>Project (Document1)</strong></em>.
      </li>
      <li style="text-align: justify;">
        Sélectionner l&#8217;option <strong><em>Insertion</em></strong>, puis <strong><em>Module</em></strong>.
      </li>
      <li style="text-align: justify;">
        Un nouveau module nommé <strong><em>Module1</em></strong> sera créé.
      </li>
      <li style="text-align: justify;">
        Dans la fenêtre <em><strong>Propriété &#8211; Module1</strong></em>, repérer la propriété <strong><em>Name</em></strong> du module dont la valeur est <em><strong>Module1</strong></em>.
      </li>
      <li style="text-align: justify;">
        Changer la valeur de la propriété pour la valeur <em><strong>ListInstalledFonts</strong></em>.
      </li>
      <li style="text-align: justify;">
        Coller le code dans la section de droite de l&#8217;éditeur. Le contenu du script devrait s&#8217;afficher.
      </li>
      <li style="text-align: justify;">
        Cliquer sur le l&#8217;icône de sauvegarde ( <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg" rel="attachment wp-att-2360"><img loading="lazy" class="alignnone size-full wp-image-2360" src="http://www.end2endzone.com/wp-content/uploads/2016/12/Microsoft-Word-Save-icon.jpg" alt="microsoft-word-save-icon" width="16" height="16" /></a> ) pour sauvegarder le nouveau module.
      </li>
      <li style="text-align: justify;">
        Fermer l&#8217;éditeur de macro Microsoft Visual Basic.
      </li>
    </ol>
    
    <p>
      Le module est maintenant installé sur le système.
    </p>
    
    <h1>
      <span id="Executer_le_script">Exécuter le script</span>
    </h1>
    
    <p>
      Procédez avec les étapes suivantes pour exécuter le module installé:
    </p>
    
    <ol>
      <li style="text-align: justify;">
        Ouvrir <em><strong>Microsoft Word</strong></em>.
      </li>
      <li style="text-align: justify;">
        Naviguer au menu <em><strong>Affichage</strong></em> du <em><strong>ruban</strong></em>.
      </li>
      <li style="text-align: justify;">
        Cliquer sur le bouton <em><strong>Macros</strong></em>. L&#8217;éditeur de macro Microsoft Visual Basic s’ouvrira.
      </li>
      <li style="text-align: justify;">
        Sélectionner la macro <em><strong>ListInstalledFonts</strong></em>. <p>
          <div id="attachment_2357" style="width: 560px" class="wp-caption alignnone">
            <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg" rel="attachment wp-att-2357"><img aria-describedby="caption-attachment-2357" loading="lazy" class="size-full wp-image-2357" src="http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg" alt="Éditeur de macro Microsoft Word - Macro ListInstalledFonts sélectionnée" width="550" height="371" srcset="http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée.jpg 550w, http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée-150x101.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/12/Éditeur-de-macro-Microsoft-Word-Macro-ListInstalledFonts-sélectionnée-300x202.jpg 300w" sizes="(max-width: 550px) 100vw, 550px" /></a>
            
            <p id="caption-attachment-2357" class="wp-caption-text">
              Éditeur de macro Microsoft Word &#8211; Macro ListInstalledFonts sélectionnée
            </p>
          </div></li> 
          
          <li style="text-align: justify;">
            Cliquer sur le bouton <span class="button3D">Exécuter</span> pour lancer l&#8217;exécution du script.
          </li>
          <li style="text-align: justify;">
            La fenêtre suivante s&#8217;ouvrira: <p>
              <div id="attachment_2354" style="width: 383px" class="wp-caption alignnone">
                <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg" rel="attachment wp-att-2354"><img aria-describedby="caption-attachment-2354" loading="lazy" class="size-full wp-image-2354" src="http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg" alt="ListInstalledFonts - Sélection d'un exemple de texte" width="373" height="158" srcset="http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte.jpg 373w, http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte-150x64.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/12/ListInstalledFonts-Sélection-dun-exemple-de-texte-300x127.jpg 300w" sizes="(max-width: 373px) 100vw, 373px" /></a>
                
                <p id="caption-attachment-2354" class="wp-caption-text">
                  ListInstalledFonts &#8211; Sélection d&#8217;un exemple de texte
                </p>
              </div></li> 
              
              <li style="text-align: justify;">
                Entrer un exemple de texte puis cliquer sur le bouton <span class="button3D">OK</span>. Laissez le champ vide et cliquer sur le bouton <span class="button3D">OK</span> pour utiliser le pangramme anglophone &#8220;<em>The quick brown fox jumps over the lazy dog</em>&#8220;.
              </li>
              <li style="text-align: justify;">
                Patientez environ 30 secondes pendant l&#8217;exécution du script.
              </li></ol> 
              
              <p>
                Le document sera complété avec votre exemple de texte pour chacune des polices installées sur votre ordinateur.
              </p>
              
              <h2>
                <span id="Exemple">Exemple</span>
              </h2>
              
              <p>
                Après l&#8217;exécution du script, vous obtiendrez un document complet:
              </p>
              
              <p>
                <div id="attachment_2350" style="width: 863px" class="wp-caption alignnone">
                  <a href="http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg" rel="attachment wp-att-2350"><img aria-describedby="caption-attachment-2350" loading="lazy" class="size-full wp-image-2350" src="http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg" alt="Exemple de d'affichage toutes les polices" width="853" height="480" srcset="http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word.jpg 853w, http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word-150x84.jpg 150w, http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word-300x169.jpg 300w, http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word-768x432.jpg 768w, http://www.end2endzone.com/wp-content/uploads/2016/12/Comment-affichier-une-liste-de-toutes-les-polices-dans-Microsoft-Word-672x378.jpg 672w" sizes="(max-width: 853px) 100vw, 853px" /></a>
                  
                  <p id="caption-attachment-2350" class="wp-caption-text">
                    Exemple de d&#8217;affichage toutes les polices
                  </p>
                </div>
              </p>
              
              <h1>
                <span id="Licence">Licence</span>
              </h1>
              
              <p class="pleasenote" data-pleasenote="true">
                Le script est disponible sous la licence LGPL. Seule la version anglophone de la licence est disponible.
              </p>
              
              <p>
                This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your option) any later version.
              </p>
              
              <p>
                This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License (LGPL-3.0) for more details.
              </p>
              
              <p>
                You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
              </p>
              
              <p>
                <strong>DISCLAIMER:</strong><br /> This software is furnished &#8220;as is&#8221;, without technical support, and with no warranty, express or implied, as to its usefulness for any purpose.
              </p>
              
              <h1>
                <span id="Telechargement">Téléchargement</span>
              </h1>
              
              <p>
                Vous pouvez télécharger le script en cliquant sur le lien de téléchargement suivant:
              </p>
              
              <p>
                <p>
                  <a class="aligncenter download-button" href="http://www.end2endzone.com/download/2339/" rel="nofollow"> Download &ldquo;MsWordListInstalledFont.bas&rdquo; <small>MsWordListInstalledFont.bas &ndash; Downloaded 1068 times &ndash; 3 KB</small> </a>
                </p>
              </p>