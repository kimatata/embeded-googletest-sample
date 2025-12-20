cmake_minimum_required(VERSION 3.14)
project(embeded-googletest-sample
    DESCRIPTION "google test for embeded code"
    HOMEPAGE_URL "https://github.com/kimatata/embeded-googletest-sample"
)

# Coverage flags for GCC/Clang
add_compile_options(--coverage)
add_link_options(--coverage)

# Locate GTest (includes Google Mock as well)
find_package(GTest REQUIRED)

# Add the library directory
add_subdirectory(../double/ build/double)
add_subdirectory(../../product build/product)

# Link runTests
add_executable(runTests
    testMain.cpp
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
    pthread
    double
    product
)