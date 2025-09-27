#!/bin/bash

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

cd public

python3 -m http.server 8000
