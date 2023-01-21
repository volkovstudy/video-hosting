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

### TESTING ###
enable_testing()

include_directories(tests)

set(tests-sources ${main-sources})

# UsersLineParser
add_executable(users-line-parser-tests ${tests-sources} tests/users-line-parser-tests/UsersLineParserTests.cpp)
add_test(NAME UsersLineParser COMMAND users-line-parser-tests)
