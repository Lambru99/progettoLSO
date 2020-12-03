cmake_minimum_required(VERSION 3.15)
project(progettoLSO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(progettoLSO
        fileReader.c
        fileReader.h
        LICENSE
        main.c
        initializer.c
        initializer.h
        playfair.c
        playfair.h
        fileWriter.c fileWriter.h)
