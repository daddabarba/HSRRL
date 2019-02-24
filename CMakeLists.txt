cmake_minimum_required(VERSION 3.13)
project(ReactTest)

set(CMAKE_CXX_STANDARD 14)

# Armadillo
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

# Boost
find_package(Boost 1.58 COMPONENTS filesystem system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

# flags
set(GCC_COVERAGE_COMPILE_FLAGS "-O3 -march=native -larmadillo -fopenmp -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(ReactTest main.cpp ReactiveCPP/ParameterNode.h ReactiveCPP/Operator.h ReactiveCPP/Variable.h ReactiveCPP/Notification.h)
target_link_libraries(${PROJECT_NAME} ${ARMADILLO_LIBRARIES} ${Boost_LIBRARIES})