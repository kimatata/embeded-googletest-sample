cmake_minimum_required(VERSION 3.14)
project(embeded-googletest-sample
    DESCRIPTION "google test for embeded code"
    HOMEPAGE_URL "https://github.com/kimatata/embeded-googletest-sample"
)

# Locate GTest (includes Google Mock as well)
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Add the library directory
add_subdirectory(../double/ build/double)
add_subdirectory(../../product build/product)

# Link runTests
add_executable(runTests
    testArmCtrl.cpp
    testCounter.cpp
    testFileManager.cpp
    testLedCtrl.cpp
    testLedImpl.cpp
)

# Link test executable against gtest & gmock libraries
target_link_libraries(runTests
    PRIVATE
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    Threads::Threads
    double
    product
)

# Apply coverage ONLY to product (not to test C++ files)
if(ENABLE_COVERAGE)
    foreach(tgt IN ITEMS product)
        target_compile_options(${tgt} PRIVATE
            --coverage
            -O0
            -g
            -fprofile-arcs
            -ftest-coverage
        )
        target_link_options(${tgt} PRIVATE --coverage)
    endforeach()

    # runTests needs --coverage at link time to collect .gcda from instrumented libs
    target_link_options(runTests PRIVATE --coverage)
endif()