cmake_minimum_required(VERSION 3.23)
project(video-hosting)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

file(GLOB_RECURSE main-sources
        "src/models/*.cpp"
        "src/repositories/*.cpp"
        "src/services/*.cpp"
)

add_executable(video-hosting src/main.cpp ${main-sources})
