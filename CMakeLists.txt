cmake_minimum_required(VERSION 3.8)
project(HSRRL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ReactiveCPP/Node.h ReactiveCPP/Defs.h ReactiveCPP/VarNode.h ReactiveCPP/InputNode.h main_test.cpp ReactiveCPP/utils.h ReactiveCPP/ParameterNode.h)
add_executable(HSRRL ${SOURCE_FILES})