cmake_minimum_required(VERSION 3.23)
project(video-hosting)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE sources "src/*.cpp")

add_executable(video-hosting ${sources})
