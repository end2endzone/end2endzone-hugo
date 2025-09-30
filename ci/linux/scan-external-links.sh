#!/bin/bash

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

cd public

# Checking external links in files.

lychee \
--verbose \
--include-fragments \
"http://localhost:8000"
