cmake_minimum_required(VERSION 3.26)
project(buscaminas)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS  OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.0)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(buscaminas main.cpp
        window.h)
target_link_libraries(buscaminas sfml-graphics)
