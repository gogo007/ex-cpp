cmake_minimum_required(VERSION 3.20)
project(TD3_CPO3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TD3_CPO3
        testWarOfRobots/tst_testwarofrobots.cpp
        bonstate.cpp
        bonstate.h
        faiblestate.cpp
        faiblestate.h
        fortstate.cpp
        fortstate.h
        game.cpp
        game.h
        main.cpp
        mortstate.cpp
        mortstate.h
        moyenstate.cpp
        moyenstate.h
        player.cpp
        player.h
        state.cpp
        state.h)
