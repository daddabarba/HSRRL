cmake_minimum_required(VERSION 3.10)
project(HSRRL)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES ${SOURCES}
        ReactiveCPP/Defs.hpp
        ReactiveCPP/Notification.hpp
        ReactiveCPP/Operator.hpp
        ReactiveCPP/ParameterNode.hpp
        ReactiveCPP/utils.hpp
        ReactiveCPP/Variable.hpp
)

set(SOURCES ${SOURCES}
        RL/Defs.hpp
        RL/RL_Agent.cpp
        RL/RL_Agent.hpp
        RL/TransitionLearning_Agent.cpp
        RL/TransitionLearning_Agent.hpp
        RL/ModelFree_Agent.cpp
        RL/ModelFree_Agent.hpp
        RL/Q_Agent.cpp
        RL/Q_Agent.hpp
)

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

add_executable(HSRRL main.cpp ${SOURCE_FILES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${ARMADILLO_LIBRARIES} ${Boost_LIBRARIES})