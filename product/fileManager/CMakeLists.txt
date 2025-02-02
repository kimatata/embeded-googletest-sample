# Define environment variables
add_definitions(-DTEST_ENV)

# Include double for resolving dependencies
include_directories(../test/double)

# Create the fileManager library
add_library(fileManager SHARED
  fileManager.c
)

target_include_directories(fileManager PUBLIC ${PROJECT_SOURCE_DIR}/product/fileManager)
target_link_libraries(fileManager double)
