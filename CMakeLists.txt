cmake_minimum_required(VERSION 3.23)
project(video-hosting)

set(CMAKE_CXX_STANDARD 14)

add_executable(video-hosting
        src/main.cpp
        src/models/film/Film.cpp src/models/film/Film.h
        src/models/user/User.cpp src/models/user/User.h
)
