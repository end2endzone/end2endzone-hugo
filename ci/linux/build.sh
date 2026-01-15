#!/bin/bash
set -e

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

# Update go modules
hugo mod get -u

# Build hugo site
hugo --minify build

# Postbuild.
# Copy more files to output directory.
cp .gitattributes public/
