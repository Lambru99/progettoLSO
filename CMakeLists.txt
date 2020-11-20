cmake_minimum_required(VERSION 3.15)
project(progettoLSO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(progettoLSO
        ascii_lettere_accentate.txt
        fileReader.c
        fileReader.h
        key.txt
        LICENSE
        link_utili.txt
        main.c
        prova.txt playfair.c playfair.h)
