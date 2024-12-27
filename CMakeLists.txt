cmake_minimum_required(VERSION 3.5)

project(CubicByte LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    cubicbyte.cpp
    main.cpp
)

set(HEADERS
    cubicbyte.h
)


add_executable(CubicByte ${SOURCES} ${HEADERS})

install(TARGETS CubicByte
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
