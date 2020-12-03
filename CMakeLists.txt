cmake_minimum_required(VERSION 3.15)
project(progettoLSO)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(progettoLSO
        encodedMessage.txt
        fileReader.c
        fileReader.h
        initializer.c
        initializer.h
        keyfile.txt
        LICENSE
        link_utili.txt
        main.c
        message.txt
        playfair.c
        playfair.h)
