@echo off
cls && hugo --minify build -D && hugo --minify -D server
