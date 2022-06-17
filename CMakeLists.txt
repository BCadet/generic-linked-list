cmake_minimum_required(VERSION 3.6)

project(gll C)

option(MALLOC "use malloc" ON)

if(NOT MALLOC)
set(POOL_SIZE 50)
message(STATUS "malloc disabled: use pool size of ${POOL_SIZE}")
add_definitions(
    -D GLL_DONT_USE_MALLOC
    -D GLL_MAX_NODE_POOL_SIZE=${POOL_SIZE}
    )
endif()

set(GLL_SRC ${CMAKE_CURRENT_LIST_DIR}/src/gll.c)

add_library(gll ${GLL_SRC})

add_executable(performance ${CMAKE_CURRENT_LIST_DIR}/performance.c)
target_link_libraries(performance gll)

add_executable(tests ${CMAKE_CURRENT_LIST_DIR}/tests.c)
target_link_libraries(tests gll)
