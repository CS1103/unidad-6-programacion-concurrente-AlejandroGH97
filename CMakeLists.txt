cmake_minimum_required(VERSION 3.14)
project(unidad_6_programacion_concurrente_AlejandroGH97)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(unidad_6_programacion_concurrente_AlejandroGH97
        "main.cpp" matriz_reg.cpp matriz_reg.h matriz_thread.cpp matriz_thread.h)
