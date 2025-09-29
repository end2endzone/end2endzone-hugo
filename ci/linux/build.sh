#!/bin/bash

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

hugo --minify build
