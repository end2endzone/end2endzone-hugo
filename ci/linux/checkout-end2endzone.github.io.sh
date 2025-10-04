#!/bin/bash
set -e

cd /tmp

export TARGET_DIR="/tmp/end2endzone.github.io"

# Cleanup
if [ -d "$TARGET_DIR" ]; then
  echo "Directory '$TARGET_DIR' exists. Deleting..."
  rm -rf "$TARGET_DIR"
  echo "Directory deleted."
else
  echo "Directory '$TARGET_DIR' does not exist. Nothing to delete."
fi

# Checkout
git clone "https://github.com/end2endzone/end2endzone.github.io.git"
