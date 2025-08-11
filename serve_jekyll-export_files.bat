@echo off
cls && hugo --minify build -D -c .\jekyll-export\_posts && hugo --minify -D -c .\jekyll-export\_posts server
