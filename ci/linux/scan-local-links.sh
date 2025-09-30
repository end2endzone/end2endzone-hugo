#!/bin/bash

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

cd public

# Checking local links in files. We only want to check local links
# and not look at the links pointing to the internet.
# The strategy is to exclude all links and then
# manually include links to http://localhost:8000 (which is the public directory 
# temporary hosted by a python web server) and links to
# https://end2endzone.github.io/ (some links are hardcoded).

lychee \
--verbose \
--include-fragments \
--exclude '.*' \
--include '^http?://localhost:8000/' \
--include '^https?://end2endzone\.github\.io/' \
"http://localhost:8000"
