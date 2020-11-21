cmake_minimum_required(VERSION 3.15)
project(progettoLSO C)

set(CMAKE_C_STANDARD 99)

add_executable(progettoLSO main.c FileReader.c FileReader.h PlayfairCipher.c PlayfairCipher.h KeyStruct.h)