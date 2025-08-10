@echo off
cls && hugo --minify build -c .\jekyll-export\_posts && hugo --minify -D -c .\jekyll-export\_posts server
