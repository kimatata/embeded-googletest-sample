#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
TEST_SRC_DIR="$ROOT_DIR/test/test"
BUILD_DIR="$ROOT_DIR/build/test"
COVERAGE_DIR="$ROOT_DIR/coverage"

ENABLE_COVERAGE=OFF
if [[ "${1:-}" == "--coverage" ]]; then
    echo "Coverage mode enabled."
    ENABLE_COVERAGE=ON
else
    echo "Running tests without coverage."
fi

# Clean old build
if [[ "$ENABLE_COVERAGE" == "ON" ]]; then
  rm -rf "$BUILD_DIR"
fi
mkdir -p "$BUILD_DIR"

cmake -S "$TEST_SRC_DIR" -B "$BUILD_DIR" -DENABLE_COVERAGE="$ENABLE_COVERAGE"
cmake --build "$BUILD_DIR" -j

"$BUILD_DIR/runTests"

if [[ "$ENABLE_COVERAGE" == "ON" ]]; then
    echo "Generating coverage report..."
    rm -rf "$COVERAGE_DIR"
    mkdir -p "$COVERAGE_DIR"

    # Capture from build tree; base-directory is repo root so lcov can resolve source paths correctly.
    lcov --capture \
      --directory "$BUILD_DIR" \
      --base-directory "$ROOT_DIR" \
      --output-file "$BUILD_DIR/coverage.info" \
      --rc branch_coverage=1 \
      --rc geninfo_unexecuted_blocks=1 \
      --ignore-errors mismatch \

    # Exclude external/system + tests themselves (adjust patterns as you like)
    lcov --remove "$BUILD_DIR/coverage.info" \
      --output-file "$BUILD_DIR/coverage_filtered.info" \
      --rc branch_coverage=1 \
      --ignore-errors mismatch,gcov,unused

    genhtml "$BUILD_DIR/coverage_filtered.info" \
      --output-directory "$COVERAGE_DIR" \
      --branch-coverage \
      --rc genhtml_branch_coverage=1

    echo "Coverage report generated in: $COVERAGE_DIR"
    echo ""
    lcov --summary "$BUILD_DIR/coverage_filtered.info" --rc branch_coverage=1
fi