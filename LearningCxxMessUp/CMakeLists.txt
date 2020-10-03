cmake_minimum_required(VERSION 3.16)
project(LearningCxxMessUp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearningCxxMessUp-1 CopyConstruct.cpp)
add_executable(LearningCxxMessUp-2 TestDeepOrShallow.cc)
add_executable(LearningCxxMessUp-3 RightValueReference.cc)
add_executable(LearningCxxMessUp-4 RightValueReference2.cc)

add_executable(LearningCxxMessUp-5 TestMessup.cc)
