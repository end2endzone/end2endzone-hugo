#!/bin/bash
set -euo pipefail

PORT=8000

if command -v ss >/dev/null 2>&1; then
  ss -ltn "( sport = :${PORT} )" 2>/dev/null | grep -q LISTEN \
    || { echo "error: port ${PORT} is not listening" >&2; exit 1; }
elif command -v lsof >/dev/null 2>&1; then
  lsof -iTCP:"${PORT}" -sTCP:LISTEN -t -nP 2>/dev/null | grep -q . \
    || { echo "error: port ${PORT} is not listening" >&2; exit 1; }
else
  echo "error: neither ss nor lsof is available" >&2
  exit 2
fi

echo "A process is listening on port ${PORT}."
