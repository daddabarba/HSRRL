cmake_minimum_required(VERSION 3.8)
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
        RLIB/Defs.hpp
        RLIB/Bases/RL_Agent.hpp
        RLIB/Bases/RL_Agent.cpp
        RLIB/Bases/Transition_Learning_Agent.hpp
        RLIB/Bases/Transition_Learning_Agent.cpp
        RLIB/Bases/Q_Agent.hpp
        RLIB/Bases/Q_Agent.cpp
        RLIB/Addons/Q_Agent_Addons.hpp
        RLIB/Addons/Q_Agent_Addons.cpp
        Actor/RL_Actor.hpp
        Actor/RL_Actor.cpp
)

set(SOURCES ${SOURCES}
        Actor/Defs.hpp
        Actor/RL_Actor.hpp
        Actor/RL_Actor.cpp
        Actor/Transition_Learning_Actor.hpp
        Actor/Transition_Learning_Actor.cpp
)

set(SOURCES ${SOURCES}
        CPP_SocketWrapper/cppsockets/Socket.cpp
        CPP_SocketWrapper/cppsockets/Socket.h
        CPP_SocketWrapper/cppsockets/SocketClient.cpp
        CPP_SocketWrapper/cppsockets/SocketClient.h
        CPP_SocketWrapper/cppsockets/SocketServer.cpp
        CPP_SocketWrapper/cppsockets/SocketServer.h
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

add_executable(TEST_REACT test_react.cpp ${SOURCE_FILES} ${SOURCES})
target_link_libraries(TEST_REACT ${ARMADILLO_LIBRARIES} ${Boost_LIBRARIES})

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${ARMADILLO_LIBRARIES} ${Boost_LIBRARIES})