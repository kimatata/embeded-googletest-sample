# Define environment variables
add_definitions(-DTEST_ENV)

# Include double for resolving dependencies
include_directories(../test/double)

# Create the ledCtrl library
add_library(ledCtrl SHARED
  ledCtrl.c
  ledImpl.c
)

target_include_directories(ledCtrl PUBLIC ${PROJECT_SOURCE_DIR}/product/led)
target_link_libraries(ledCtrl double)
