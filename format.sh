#!/bin/bash

echo "Running clang-format on source files in product/ and test/..."

find ./product ./test -type f \( -name "*.c" -o -name "*.h" -o -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +

echo "Formatting completed."
