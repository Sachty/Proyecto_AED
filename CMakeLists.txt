cmake_minimum_required(VERSION 3.25)
project(Proyecto_AED)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.6 COMPONENTS system window graphics)

add_executable(Proyecto_AED
        main_manual.cpp)

target_link_libraries(Proyecto_AED sfml-system sfml-window sfml-graphics)
