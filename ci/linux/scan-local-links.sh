#!/bin/bash
set -euo pipefail

# cd to project base directory
cd "$(dirname "$0")"
cd ../..

# Check if a web server is already running on port 8000.
# Fail if port already listening.
./ci/linux/assert_web_server_not_running.sh

# Start python3 web server in a background process
echo "Starting web server..."
./ci/linux/run_site.sh & WEBSERVER_PID=$!
sleep 5
echo "done."
echo "Web server's pid is $WEBSERVER_PID." 
echo

# Check that web server is still running.
./ci/linux/assert_web_server_is_running.sh

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

echo "lychee's exit code: $scan_result."
echo

# Terminate running site background process
./ci/linux/terminate_or_kill_pid.sh "$WEBSERVER_PID"
echo

# Exit with lychee's exit code
exit $scan_result
