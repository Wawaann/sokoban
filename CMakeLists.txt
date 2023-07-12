cmake_minimum_required(VERSION 3.15)

project(sokoban)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(sokoban 
        src/main.cpp
        src/Map.cpp src/Map.hpp
        src/Player.cpp src/Player.hpp)

target_link_libraries(sokoban sfml-graphics sfml-window sfml-system)
