cmake_minimum_required(VERSION 3.14)
project(embeded-googletest-sample
    DESCRIPTION "google test for embeded code"
    HOMEPAGE_URL "https://github.com/kimatata/embeded-googletest-sample"
)

# Coverage flags for GCC/Clang
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

# Locate GTest (includes Google Mock as well)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

# Add the library directory
add_subdirectory(../double/ build/double)
add_subdirectory(../../product/armCtrl build/armCtrl)
add_subdirectory(../../product/counter build/counter)
add_subdirectory(../../product/fileManager build/fileManager)
add_subdirectory(../../product/ledCtrl build/ledCtrl)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests testMain.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} gmock gmock_main pthread double armCtrl counter fileManager ledCtrl)
