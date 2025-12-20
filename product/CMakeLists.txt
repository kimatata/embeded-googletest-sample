add_library(product SHARED
  armCtrl/armCtrl.c
  board/board.c
  counter/counter.c
  fileManager/fileManager.c
  ledCtrl/ledCtrl.c
  ledCtrl/ledImpl.c
)
target_compile_definitions(product PUBLIC TEST_ENV)
target_include_directories(product PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/armCtrl
  ${CMAKE_CURRENT_SOURCE_DIR}/board
  ${CMAKE_CURRENT_SOURCE_DIR}/counter
  ${CMAKE_CURRENT_SOURCE_DIR}/fileManager
  ${CMAKE_CURRENT_SOURCE_DIR}/ledCtrl
)
target_link_libraries(product PUBLIC double)
