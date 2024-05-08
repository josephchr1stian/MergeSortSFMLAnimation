cmake_minimum_required(VERSION 3.28)
project(sortAnimation)

set(CMAKE_CXX_STANDARD 23)

add_executable(sortAnimation main.cpp
        MergeAnimation.cpp
        MergeAnimation.h
        MouseEvents.h
        MouseEvents.cpp
        Application.cpp
        Application.h
        )

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(sortAnimation sfml-graphics sfml-audio)