cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay6)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCxxDay6-1 01-MyString/MyString.h 01-MyString/MyString.cpp  01-MyString/MyStringMain.cpp)
add_executable(LearningCxxDay6-2-1 02-Inherit/BasicGrammer.cpp )
add_executable(LearningCxxDay6-2-2 02-Inherit/InheritWay.cpp )
add_executable(LearningCxxDay6-2-3 02-Inherit/ObjectModel.cpp )
add_executable(LearningCxxDay6-2-4 02-Inherit/ConstructAndDestruct.cpp )
add_executable(LearningCxxDay6-2-5 02-Inherit/MembersOfSameName.cpp )
add_executable(LearningCxxDay6-2-6 02-Inherit/StaticMember.cpp )
add_executable(LearningCxxDay6-2-7 02-Inherit/MultiInherit.cpp )
add_executable(LearningCxxDay6-2-8 02-Inherit/DiamondInherit.cpp )