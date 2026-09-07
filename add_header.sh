#!/usr/bin/env bash
set -euo pipefail

BASELINE="${1:?usage: $0 <initial-commit>}"
DRY_RUN="${DRY_RUN:-0}"

NOTICE='/* ================================================================ */
/*                                                                  */
/* Modifications Copyright (C) Will Stockdell 2026                  */
/*                                                                  */
/* Modifications to this file are made available under the          */
/* Eclipse Public License (EPL) version 1.0.                        */
/*                                                                  */
/* ================================================================ */'

find . -type f \( -name '*.cc' -o -name '*.h' \) -print0 |
while IFS= read -r -d '' file; do
    # Only IBM-derived files.
    grep -q 'end_generated_IBM_copyright_prolog' "$file" || continue

    # Already updated.
    grep -q 'Modifications Copyright (C) Will Stockdell 2026' "$file" && continue

    # Ignore files that have only been moved/renamed since the import.
    # A real content change produces at least one diff hunk.
    if ! git log --follow -p --format= \
        "$BASELINE"..HEAD -- "$file" |
        grep '^@@' >/dev/null
    then
        continue
    fi

    echo "$file"

    [[ "$DRY_RUN" == "1" ]] && continue

    tmp="$(mktemp)"

    awk -v notice="$NOTICE" '
        { print }

        /end_generated_IBM_copyright_prolog/ {
            print ""
            print notice
        }
    ' "$file" > "$tmp"

    cat "$tmp" > "$file"
    rm "$tmp"
done
