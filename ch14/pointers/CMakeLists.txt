cmake_minimum_required(VERSION 3.5)

project(pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXTERNAL_DIR ../../external)
set(INCLUDE_DIR src)

set(HEADER_FILES
    ${INCLUDE_DIR}/copied_built_in_ptr.hpp
    ${INCLUDE_DIR}/copied_object_ptr.hpp
    ${INCLUDE_DIR}/reference_count.hpp
)

set(SOURCE_FILES
)

add_executable(pointers
    main.cpp
    ${SOURCE_FILES}
    ${HEADER_FILES}
)
target_include_directories(pointers PRIVATE ${INCLUDE_DIR})

set(TEST_FILES
    ${INCLUDE_DIR}/copied_built_in_ptr_test.cpp
    ${INCLUDE_DIR}/copied_object_ptr_test.cpp
    ${INCLUDE_DIR}/reference_count_test.cpp
)

add_executable(test
    test.cpp
    ${TEST_FILES}
    ${SOURCE_FILES}
    ${HEADER_FILES}
)
target_include_directories(test PRIVATE
    ${INCLUDE_DIR}
    ${EXTERNAL_DIR}
)
