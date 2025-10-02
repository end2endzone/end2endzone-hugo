#!/bin/bash
set -euo pipefail

# Usage: ./terminate.sh <pid> [grace_seconds]
# Example: ./terminate.sh 12345 5

PID=${1:-}
GRACE=${2:-5}

# Validate PID argument
if [ -z "$PID" ]; then
  echo "usage: $0 <pid> [grace_seconds]" >&2
  exit 1
fi

# Must be a positive integer
if ! printf '%s\n' "$PID" | grep -Eq '^[0-9]+$'; then
  echo "error: pid must be a positive integer" >&2
  exit 1
fi

# Check process exists and we can signal it
if ! kill -0 "$PID" 2>/dev/null; then
  echo "error: no such process with PID $PID" >&2
  exit 2
fi

echo "Found process with PID $PID; sending SIGTERM."

# Try to terminate the whole process group first.
# Fall back to the pid itself otherwise.
if kill -- -"$PID" 2>/dev/null; then
  : # signaled process group
else
  kill -TERM "$PID" 2>/dev/null || true
fi

# Wait up to GRACE seconds for the pid to disappear
end=$((SECONDS + GRACE))
while kill -0 "$PID" 2>/dev/null && [ $SECONDS -lt $end ]; do
  sleep 0.1
done

# Check if pid is still running.
if kill -0 "$PID" 2>/dev/null; then
  echo "Process with PID $PID did not exit within ${GRACE}s; sending SIGKILL"
  if kill -- -"$PID" 2>/dev/null; then
    :
  else
    kill -KILL "$PID" 2>/dev/null || true
  fi
else
  echo "Process with PID $PID requested to exit gracefully."
fi

# Attempt to reap if this shell started the process.
# Ignore errors if not a child.
wait "$PID" 2>/dev/null || true

# Add a grace period to prevent fast changing states.
sleep 5

# Check process exists again and we can signal it
if ! kill -0 "$PID" 2>/dev/null; then
  echo "Process with PID $PID is terminated." >&2
  exit 0
else
  echo "error: process with PID $PID still exits!" >&2
  exit 1
fi
