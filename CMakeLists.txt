cmake_minimum_required(VERSION 3.23)
project(video-hosting)

set(CMAKE_CXX_STANDARD 14)

add_executable(video-hosting
        src/main.cpp
        src/film/Film.cpp src/film/Film.h
        src/user/User.cpp src/user/User.h
)
