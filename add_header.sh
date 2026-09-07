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

git diff --name-only -z "$BASELINE"..HEAD -- '*.cc' '*.h' |
while IFS= read -r -d '' file; do
    [[ -f "$file" ]] || continue

    grep -q 'end_generated_IBM_copyright_prolog' "$file" || continue
    grep -q 'Modifications Copyright (C) Will Stockdell 2026' "$file" && continue

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
