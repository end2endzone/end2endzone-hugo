@echo off
cls && hugo --minify build && hugo --minify -D server
