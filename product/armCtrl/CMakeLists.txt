# Define environment variables
add_definitions(-DTEST_ENV)

# Include double for resolving dependencies
include_directories(../test/double)

# Create the armCtrl library
add_library(armCtrl SHARED
  armCtrl.c
)

target_include_directories(armCtrl PUBLIC ${PROJECT_SOURCE_DIR}/product/armCtrl)
target_link_libraries(armCtrl double)
