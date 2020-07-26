cmake_minimum_required(VERSION 3.16)
project(LearningCxxDay9)

set(CMAKE_CXX_STANDARD 11)

add_executable(LearningCxxDay9-1 01-TypeConversion/StaticDynamicCast.cpp)
add_executable(LearningCxxDay9-2-1 02-Exception/ExceptionBasicGrammer.cpp)
add_executable(LearningCxxDay9-2-2 02-Exception/ExceptionInterfaceDeclaration.cpp)
add_executable(LearningCxxDay9-2-3 02-Exception/VariableLifeCycle.cpp)
add_executable(LearningCxxDay9-2-4 02-Exception/PolymorphismInException.cpp)
add_executable(LearningCxxDay9-2-5 02-Exception/StandardLibraryException.cpp)
add_executable(LearningCxxDay9-2-6 02-Exception/CustomerException.cpp)

add_executable(LearningCxxDay9-3-1 03-InputOutputStream/InputStreamTest.cpp)
add_executable(LearningCxxDay9-3-2 03-InputOutputStream/OutputStreamTest.cpp)
add_executable(LearningCxxDay9-3-3 03-InputOutputStream/FileReadWrite.cpp)
