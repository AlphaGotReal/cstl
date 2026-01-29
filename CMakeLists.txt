cmake_minimum_required(VERSION 3.12)
project(cstl C) 

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set (CMAKE_C_FLAGS "-Wall")

include(CTest)
enable_testing()

include_directories(include)
add_library(${PROJECT_NAME}
  src/cstl.c
  src/list.c
  src/utils.c
)

# link math library, very weird indeed
target_link_libraries(${PROJECT_NAME} m)

add_executable(debug src/debug.c)
target_link_libraries(debug
  PUBLIC
  ${PROJECT_NAME}
)

function(cstl_test test_name)
  add_executable(${test_name} tests/${test_name}.c)
  target_link_libraries(${test_name} PRIVATE ${PROJECT_NAME})
  add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

# tests
cstl_test(test_list)
