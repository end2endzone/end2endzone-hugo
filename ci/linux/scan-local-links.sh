#!/bin/bash

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

# Start python3 web server in a background process
echo "Starting web server..."
./ci/linux/run_site.sh & BG_PID=$!
sleep 5
echo "done."
echo "Web server's pid is $BG_PID." 
echo

echo "Validating with lychee..."
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

# Capture lychee exit code
scan_result=$?

echo "done."
echo "lychee's exit code: $scan_result."
echo

# Terminate running site background process
echo "Terminating pid $BG_PID..." 
kill -- -$BG_PID 2>/dev/null || true; kill "$BG_PID" 2>/dev/null || true; wait "$BG_PID" 2>/dev/null || true
echo "done."
echo

# Exit with lychee's exit code
exit $scan_result
