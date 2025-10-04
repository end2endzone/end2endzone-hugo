#!/bin/bash
set -e

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

# Build hugo site
hugo --minify build

# Postbuild.
# Copy more files to output directory.
cp .gitattributes public/
