#!/bin/bash
set -euo pipefail

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

# Search for input directory
if [ ! -d public ]; then
    echo "ERROR: public/ directory not found. Hugo build failed."
    exit 1
fi

# Search for output directory
if [ ! -d /tmp/end2endzone.github.io ]; then
    echo "ERROR: /tmp/end2endzone.github.io/ directory not found. Site repository checkout failed."
    exit 1
fi

# Sync generated site to deployment repo
echo "Synchronising build directory to deploy directory..."
rsync -av --delete --exclude-from=ci/rsync-exclude.txt public/ /tmp/end2endzone.github.io/
echo "synchronisation complete."
