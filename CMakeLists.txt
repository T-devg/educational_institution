cmake_minimum_required(VERSION 4.2)
project(educational_institution)

set(CMAKE_CXX_STANDARD 20)

add_executable(educational_institution main.cpp
        ArrayTemplate.h
        Teacher.h
        Subject.h
        EducationFunctions.h)
