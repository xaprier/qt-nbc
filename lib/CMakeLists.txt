# Specify the directory to check
set(
  DIRECTORIES_TO_CHECK
  "${CMAKE_CURRENT_SOURCE_DIR}/Number" # get Number
  "${CMAKE_CURRENT_SOURCE_DIR}/tester" # get tester
  "${CMAKE_CURRENT_SOURCE_DIR}/ASTHandler" # get ASTHandler
)

foreach(DIRECTORY ${DIRECTORIES_TO_CHECK})
  # Check if the directory exists
  if(NOT EXISTS ${DIRECTORY} OR NOT EXISTS ${DIRECTORY}/CMakeLists.txt)
    message(FATAL_ERROR "Directory ${DIRECTORY} does not exist.\nYou should get submodules while cloning(git clone --recurse-submodules ...).\nOr you can just get modules(git submodule update --init --recursive)")
  else()
    add_subdirectory(${DIRECTORY})
  endif()
endforeach()