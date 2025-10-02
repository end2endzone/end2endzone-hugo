#!/bin/bash
set -euo pipefail

PORT=8000
GRACE=5  # seconds to wait after SIGTERM

# Get PID listening on $PORT (one PID or empty). Prefer lsof; fall back to ss.
get_pid() {
  if command -v lsof >/dev/null 2>&1; then
    # -t prints only PIDs; head -n1 ensures a single PID if any
    lsof -iTCP:"${PORT}" -sTCP:LISTEN -t -nP 2>/dev/null | head -n1 || true
  elif command -v ss >/dev/null 2>&1; then
    # ss output contains pid=NNN, try to extract the first PID from any LISTEN line
    ss -ltnp "( sport = :${PORT} )" 2>/dev/null \
      | awk '/LISTEN/ { for(i=1;i<=NF;i++) if($i ~ /pid=/){ gsub(/[^0-9]/,"",$i); print $i; exit } }' \
      | head -n1 || true
  else
    echo "error: neither lsof nor ss is available" >&2
    return 2
  fi
}

pid=$(get_pid) || rc=$?
if [ "${rc:-0}" -eq 2 ]; then
  exit 2
fi

if [ -z "${pid:-}" ]; then
  echo "No process is listening on port ${PORT}." >&2
  exit 0
fi

# Terminate running site background process
echo "Found proces with pid ${pid} listening on port ${PORT}."
./ci/linux/terminate_or_kill_pid.sh "${pid}"
echo
