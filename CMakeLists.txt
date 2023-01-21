cmake_minimum_required(VERSION 3.23)
project(video-hosting)

set(CMAKE_CXX_STANDARD 14)

add_executable(video-hosting
        src/main.cpp
        src/models/film/Film.cpp src/models/film/Film.h
        src/models/user/User.cpp src/models/user/User.h
        src/services/authentication-service/AuthenticationService.cpp src/services/authentication-service/AuthenticationService.h
        src/repositories/users-repository/UsersRepository.cpp src/repositories/users-repository/UsersRepository.h
        src/repositories/users-repository/users-line-parser/UsersLineParser.cpp src/repositories/users-repository/users-line-parser/UsersLineParser.h
        src/repositories/films-repository/FilmsRepository.cpp src/repositories/films-repository/FilmsRepository.h
        src/services/file-service/FileService.cpp src/services/file-service/FileService.h
)
