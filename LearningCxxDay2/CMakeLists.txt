cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay2)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCxxDay2-1 01-ClassDesign/ClassDesign.cpp)

add_executable(LearningCxxDay2-2 02-InlineFunction/InlineFunction.cpp)

add_executable(LearningCxxDay2-3 03-DefaultAndPlaceHolderFunction/DefaultAndPlaceHolderFunction.cpp)

add_executable(LearningCxxDay2-4 04-FunctionOverload/FunctionOverload.cpp)

add_executable(LearningCxxDay2-5 05-ExternC/ExternC.cpp 05-ExternC/test.c 05-ExternC/test.h)

add_executable(LearningCxxDay2-6-1 06-PackageInCAndCPP/PackageInC.c)

add_executable(LearningCxxDay2-6-2 06-PackageInCAndCPP/PackageInCPP.cpp)

add_executable(LearningCxxDay2-7 07-MakeItPrivate/MakeItPrivate.cpp)
