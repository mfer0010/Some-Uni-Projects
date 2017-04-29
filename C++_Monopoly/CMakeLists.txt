cmake_minimum_required(VERSION 3.6)
project(task2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    main.cpp
    Ownerships.cpp
    Ownerships.h
    Player.cpp
    Player.h
    Properties.cpp
    Properties.h
    Tile.cpp
    Tile.h Hazard.h Hazard.cpp Xorti.h Xorti.cpp Port.h Port.cpp TipparkjaBXejn.h TipparkjaBXejn.cpp Blank.h Blank.cpp Company.h Company.cpp GameController.h GameController.cpp)

add_executable(task2 ${SOURCE_FILES})