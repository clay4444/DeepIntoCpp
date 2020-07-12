cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay1)

set(CMAKE_CXX_STANDARD 11)

#第一个是编译后生成的可执行文件名，第二个是需要编译的源文件，后面可以跟多个，但是只能有一个main()函数，注意！
add_executable(LearningCxxDay1-1 01-HelloWorld/HelloWorld.cpp )

add_executable(LearningCxxDay1-2 02-DoubleColonOperator/DoubleColonOperator.cpp)

add_executable(LearningCxxDay1-3 03-UseNameSpace/UseNameSpace.cpp 03-UseNameSpace/game1.h 03-UseNameSpace/game1.cpp
        03-UseNameSpace/game2.h 03-UseNameSpace/game2.cpp)

add_executable(LearningCxxDay1-4 04-UsingInstruction/UsingInstruction.cpp)

add_executable(LearningCxxDay1-5 05-CompareWithC_C/CompareWithC_C.c)

add_executable(LearningCxxDay1-6 06-CompareWithC_Cpp/CompareWithC_Cpp.cpp)

add_executable(LearningCxxDay1-7 07-ConstLinkOnC/ConstLinkOnC.c 07-ConstLinkOnC/test.c)

add_executable(LearningCxxDay1-8 08-ConstLinkOnCpp/ConstLinkOnCpp.cpp 08-ConstLinkOnCpp/test.cpp)

add_executable(LearningCxxDay1-9 09-ConstAllocateMemory/ConstAllocateMemory.cpp)

add_executable(LearningCxxDay1-10 10-UseReference/UseReference.cpp)

add_executable(LearningCxxDay1-11 11-ParameterPassing/ParameterPassing.cpp)

add_executable(LearningCxxDay1-12 12-ReferenceOfPoint/ReferenceOfPoint.cpp)

add_executable(LearningCxxDay1-13 13-ReferenceOfConst/ReferenceOfConst.cpp)