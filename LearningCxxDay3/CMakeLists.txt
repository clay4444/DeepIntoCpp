cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay3)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCxxDay3-1 01-CubeClassDesign/CubeClassDesign.cpp)

add_executable(LearningCxxDay3-2 02-PointCircleRelationShipClassDesign/PointCycleRelationShipClassDesign.cpp 02-PointCircleRelationShipClassDesign/point.h
        02-PointCircleRelationShipClassDesign/point.cpp 02-PointCircleRelationShipClassDesign/circle.h 02-PointCircleRelationShipClassDesign/circle.cpp)

add_executable(LearningCxxDay3-3 03-FunctionOfConstructAndDestruct/FunctionOfConstructAndDestruct.cpp)

add_executable(LearningCxxDay3-4-1 04-FunctionOfConstructDetail/ClassificationAndInvoke.cpp)

add_executable(LearningCxxDay3-4-2 04-FunctionOfConstructDetail/ConstructFunctionInvokeTime.cpp)

add_executable(LearningCxxDay3-4-3 04-FunctionOfConstructDetail/ConstructFunctionInvokeRule.cpp)

add_executable(LearningCxxDay3-5 05-ShallowAndDeepCopy/ShallowAndDeepCopy.cpp)

add_executable(LearningCxxDay3-6 06-InitializeList/InitializeList.cpp)

add_executable(LearningCxxDay3-7 07-ObjectAsClassField/ObjectAsClassField.cpp)

add_executable(LearningCxxDay3-8 08-Explict/Explict.cpp)

add_executable(LearningCxxDay3-9 09-NewAndDelete/NewAndDelete.cpp)
