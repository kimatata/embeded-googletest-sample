#!/bin/bash

# check coverage flag
if [ "$1" == "--coverage" ]; then
    echo "Coverage mode enabled."
    COVERAGE_FLAGS="-DCMAKE_CXX_FLAGS=--coverage -DCMAKE_C_FLAGS=--coverage"
else
    echo "Running tests without coverage."
    COVERAGE_FLAGS=""
fi

# build
cd test/test
cmake $COVERAGE_FLAGS CMakeLists.txt
make

# run test suites
./runTests

# if coverage enabled, generate coverage report
if [ "$1" == "--coverage" ]; then
    echo "Generating coverage report..."
    # create coverage directory
    mkdir -p ../coverage
    # colect coverage info
    lcov --capture --directory . --output-file coverage.info --rc lcov_branch_coverage=1 --ignore-errors mismatch
    # remove test code, google test code, and other library code coverage from report
    lcov --remove coverage.info '/usr/*' '*/gtest/*' '*/gmock/*' '*/test/*' --output-file coverage_filtered.info
    # generate coverage report
    genhtml coverage_filtered.info --output-directory ../coverage
    echo "Coverage report generated in root/coverage directory."
fi
