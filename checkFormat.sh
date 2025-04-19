#!/bin/bash

FILES=$(find ./product ./test -type f \( -name "*.c" -o -name "*.h" -o -name "*.cpp" -o -name "*.hpp"  \))

FORMAT_FAILED=0

for file in $FILES; do
    if ! clang-format --dry-run --Werror "$file"; then
        echo "Formatting issue detected in: $file"
        FORMAT_FAILED=1
    fi
done

if [ $FORMAT_FAILED -ne 0 ]; then
    echo "Code formatting check failed."
    exit 1
else
    echo "All files are properly formatted."
fi
