
cmake_minimum_required(VERSION 3.10)
project(exercise_9)



# Disable copy elision
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")


add_executable(copy_elision copy_elision.cpp)
add_executable(copy_assignment copy_assignment.cpp)
