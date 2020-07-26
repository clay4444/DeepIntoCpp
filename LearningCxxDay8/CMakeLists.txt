cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay8)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCxxDay8-1-1 01-FunctionTemplate/FunctionTemplate.cpp)
add_executable(LearningCxxDay8-1-2 01-FunctionTemplate/GenericOrder.cpp)
add_executable(LearningCxxDay8-1-3 01-FunctionTemplate/DifferenceWithOrdinaryFunc.cpp)
add_executable(LearningCxxDay8-1-4 01-FunctionTemplate/LimitOfTemplate.cpp)

add_executable(LearningCxxDay8-2-1 02-ClassTemplate/ClassTemplate.cpp)
add_executable(LearningCxxDay8-2-2 02-ClassTemplate/FunctionCreateTimeInClassTemplate.cpp)
add_executable(LearningCxxDay8-2-3 02-ClassTemplate/AsFunctionParam.cpp)
add_executable(LearningCxxDay8-2-4 02-ClassTemplate/ProblemOfInherit.cpp)
add_executable(LearningCxxDay8-2-5 02-ClassTemplate/MemberFunctionOfOutOfClass.cpp)
add_executable(LearningCxxDay8-2-6 02-ClassTemplate/MemberFunctionInMultiFiles.cpp 02-ClassTemplate/person.hpp)
add_executable(LearningCxxDay8-2-7 02-ClassTemplate/WithTomomotoFunction.cpp)
add_executable(LearningCxxDay8-2-8 02-ClassTemplate/myArray.hpp 02-ClassTemplate/MyArrayApp.cpp)