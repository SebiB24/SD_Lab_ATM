cmake_minimum_required(VERSION 3.27)
project(SD_Lab_ATM)

set(CMAKE_CXX_STANDARD 17)

add_executable(SD_Lab_ATM main.cpp
        Pair.cpp
        Pair.h
        Tests.cpp
        Tests.h
        Collection.cpp
        Collection.h
        Vector.cpp
        Vector.h
        Atm.cpp
        Atm.h
        Except.h
        Tranzactie.cpp
        Tranzactie.h)
