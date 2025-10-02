#!/bin/bash
set -euo pipefail

PORT=8000

# detect tool and test; set RESULT and ERRMSG appropriately
if command -v ss >/dev/null 2>&1; then
  if ss -ltn "( sport = :${PORT} )" 2>/dev/null | grep -q LISTEN; then
    pid=$(ss -ltnp "( sport = :${PORT} )" 2>/dev/null | sed -n 's/.*pid=\([0-9][0-9]*\).*/\1/p' | head -n1 || true)
    if [ -n "${pid}" ]; then
      echo "error: port ${PORT} is already listening (pid ${pid})" >&2
    else
      echo "error: port ${PORT} is already listening" >&2
    fi
    exit 1
  fi
elif command -v lsof >/dev/null 2>&1; then
  pids=$(lsof -iTCP:"${PORT}" -sTCP:LISTEN -t -nP 2>/dev/null || true)
  first_pid=$(printf "%s\n" "${pids}" | head -n1 | tr -d '\n' || true)
  if [ -n "${first_pid}" ]; then
    echo "error: port ${PORT} is already listening (pid ${first_pid})" >&2
    exit 1
  fi
else
  echo "error: neither ss nor lsof is available" >&2
  exit 2
fi

# success message appears only once here
echo "Port ${PORT} is free."
exit 0
