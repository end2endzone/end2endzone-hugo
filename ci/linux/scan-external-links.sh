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
pushd public/ >/dev/null
python3 -m http.server 8000 2>/dev/null & WEBSERVER_PID=$!
popd >/dev/null
sleep 5
echo "done."
echo "Web server's pid is $WEBSERVER_PID." 
echo

# Check that web server is still running.
./ci/linux/assert_web_server_is_running.sh

set +e  # Disable exit on error

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

set -e  # Re-enable exit on error

echo "lychee's exit code: $scan_result."
echo

# Terminate running site background process
./ci/linux/terminate_or_kill_pid.sh "$WEBSERVER_PID"
echo

# Exit disregarding lychess's previous errors.
exit 0
