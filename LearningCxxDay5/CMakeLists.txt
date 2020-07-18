cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay5)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCxxDay5-1 01-MyArray/MyArrayMain.cpp 01-MyArray/myArray.h 01-MyArray/myArray.cpp)
add_executable(LearningCxxDay5-2 02-PlusOperatorOverload/PlusOperatorOverload.cpp)
add_executable(LearningCxxDay5-3 03-ShiftLeftOperatorOverload/ShiftLeftOperator.cpp)
add_executable(LearningCxxDay5-4 04-IncrementOeratorOverload/IncrementOeratorOverload.cpp)
add_executable(LearningCxxDay5-5 05-PointOperatorOverload/PointOperatorOverload.cpp)
add_executable(LearningCxxDay5-6 06-AssignmentOperatorOverload/AssignmentOperatorOverload.cpp)