
cmake_minimum_required(VERSION 3.10)
project(exercise_19)



add_executable(thread1 thread1.cpp)

# Find the pthread library
find_package(Threads REQUIRED)

# Link the pthread library to the target
target_link_libraries(thread1 PRIVATE Threads::Threads)

add_executable(mutex1 mutex1.cpp)
target_link_libraries(mutex1 PRIVATE Threads::Threads)


add_executable(lock_guard1 lock_guard1.cpp)
target_link_libraries(lock_guard1 PRIVATE Threads::Threads)

add_executable(atomic1 atomic1.cpp)
target_link_libraries(atomic1 PRIVATE Threads::Threads)

add_executable(atomic2 atomic2.cpp)
target_link_libraries(atomic2 PRIVATE Threads::Threads)

add_executable(future1 future1.cpp)
target_link_libraries(future1 PRIVATE Threads::Threads)

add_executable(future2 future2.cpp)
target_link_libraries(future2 PRIVATE Threads::Threads)
