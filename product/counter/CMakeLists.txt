# Define environment variables
add_definitions(-DTEST_ENV)

# Include double for resolving dependencies
include_directories(../test/double)

# Create the counter library
add_library(counter SHARED
  counter.c
)

target_include_directories(counter PUBLIC ${PROJECT_SOURCE_DIR}/product/counter)
target_link_libraries(counter double)
