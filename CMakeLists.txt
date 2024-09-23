cmake_minimum_required(VERSION 3.30)
project(pivoh)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    src/*.c
    src/*.h
    include/*.h
)


# Add executable target
add_executable(pivoh ${sources})
target_include_directories(pivoh PRIVATE src include)
