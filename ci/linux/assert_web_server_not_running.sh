#!/bin/bash
set -euo pipefail

PORT=8000

# detect tool and test; set RESULT and ERRMSG appropriately
if command -v ss >/dev/null 2>&1; then
  if ss -ltn "( sport = :${PORT} )" 2>/dev/null | grep -q LISTEN; then
    echo "error: port ${PORT} is already listening" >&2
    exit 1
  fi
elif command -v lsof >/dev/null 2>&1; then
  if lsof -iTCP:"${PORT}" -sTCP:LISTEN -t -nP 2>/dev/null | grep -q .; then
    echo "error: port ${PORT} is already listening" >&2
    exit 1
  fi
else
  echo "error: neither ss nor lsof is available" >&2
  exit 2
fi

# success message appears only once here
echo "Port ${PORT} is free."
exit 0
