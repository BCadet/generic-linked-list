cmake_minimum_required(VERSION 3.6)

project(gll C)

option(MALLOC "gll use malloc" ON)

if(NOT GLL_MALLOC)
message(STATUS "[GLL] malloc disabled: gll lib uses static node pool instead")
if(NOT GLL_POOL_SIZE)
set(GLL_POOL_SIZE 50)
message(STATUS "[GLL] Please consider defining the pool size with GLL_POOL_SIZE variable. Using default value...")
endif()
message(STATUS "[GLL] gll node pool size defined to ${GLL_POOL_SIZE}.")
add_definitions(
    -D GLL_DONT_USE_MALLOC
    -D GLL_MAX_NODE_POOL_SIZE=${GLL_POOL_SIZE}
    )
endif()

set(GLL_SRC ${CMAKE_CURRENT_LIST_DIR}/src/gll.c)

add_library(gll ${GLL_SRC})

add_executable(gll-performance-test ${CMAKE_CURRENT_LIST_DIR}/performance.c)
target_link_libraries(gll-performance-test gll)
set_target_properties(gll-performance-test PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_executable(gll-tests ${CMAKE_CURRENT_LIST_DIR}/tests.c)
target_link_libraries(gll-tests gll)
set_target_properties(gll-tests PROPERTIES EXCLUDE_FROM_ALL TRUE)
