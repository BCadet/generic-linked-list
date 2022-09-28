cmake_minimum_required(VERSION 3.6)

project(gll C)

set(GLL_SRC ${CMAKE_CURRENT_LIST_DIR}/src/gll.c)

add_library(gll ${GLL_SRC})

if(NOT GLL_MALLOC)
message(STATUS "[GLL] malloc disabled: gll lib uses static node pool instead")
if(NOT GLL_POOL_SIZE)
set(GLL_POOL_SIZE 50)
message(STATUS "[GLL] Please consider defining the pool size with GLL_POOL_SIZE variable. Using default value...")
endif()
message(STATUS "[GLL] gll node pool size defined to ${GLL_POOL_SIZE}.")
target_compile_definitions(gll PUBLIC
    GLL_DONT_USE_MALLOC
    GLL_MAX_NODE_POOL_SIZE=${GLL_POOL_SIZE}
    )
endif()

add_executable(gll-performance-test ${CMAKE_CURRENT_LIST_DIR}/performance.c)
target_link_libraries(gll-performance-test gll)
set_target_properties(gll-performance-test PROPERTIES EXCLUDE_FROM_ALL TRUE)

add_executable(gll-tests ${CMAKE_CURRENT_LIST_DIR}/tests.c)
target_link_libraries(gll-tests gll)
set_target_properties(gll-tests PROPERTIES EXCLUDE_FROM_ALL TRUE)

option(GLL_DOCUMENTATION "Build the generic-linked-list documentation with Doxygen" OFF)
if(GLL_DOCUMENTATION)
    message(STATUS "[GLL] Documentation build enabled: generic-linked-list-doc")
    find_package(Doxygen REQUIRED dot)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/documentation/${PROJECT_NAME}")
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "README.md")
    set(DOXYGEN_PROJECT_NAME "Generic Doubly Linked List")
    set(DOXYGEN_GENERATE_TAGFILE "${CMAKE_BINARY_DIR}/documentation/${PROJECT_NAME}.tag")
    set(DOXYGEN_GENERATE_TREEVIEW "YES")
    doxygen_add_docs(${PROJECT_NAME}-doc .)
endif()