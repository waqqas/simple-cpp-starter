# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name
project(cat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CURRENT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/animals")

# Add the library target
add_library(cat ${CMAKE_CURRENT_SOURCE_DIR}/cat.cpp ${CMAKE_CURRENT_SOURCE_DIR}/cat.h)

# Include the header file
target_include_directories(cat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC) 
    target_compile_options(cat PRIVATE /W4 /WX) 
else() 
    target_compile_options(cat PRIVATE -Wall -Wextra -pedantic -Werror) 
endif()


# Set the library properties
set_target_properties(cat PROPERTIES
    VERSION 1.0
    SOVERSION 1
)

# Optionally, you can install the library
install(TARGETS cat
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)