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
# Checking all links in files.
# Since we already validated local links,
# we are actually only checking external links.
# External links errors must be considerate as warnings, not errors.
lychee \
--verbose \
--include-fragments \
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

# Exit disregarding lychess's previous errors.
exit 0
