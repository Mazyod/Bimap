

cmake_minimum_required(VERSION 3.2)
project(BimapTests)


include_directories(
    .
    ..
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(BimapTests
    catch.hpp
    main.cpp

    # appease CLion
    ../Bimap/Bimap.h
)
