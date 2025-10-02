#!/bin/bash
set -e

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

# Build hugo site
hugo --minify build

# Copy more files from this project
cp .gitattributes public/
