# ./CMakeLists.txt
cmake_minimum_required(VERSION 3.5)
project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

aux_source_directory(./src CPP_LIST)
add_executable(main ${CPP_LIST})

target_include_directories(main PUBLIC ${INCLUDE_DIR})

message("Succeed!")
message(${INCLUDE_DIR})