cmake_minimum_required(VERSION 3.28)
project(boids_cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)

add_executable(boids_cpp src/main.cpp)


