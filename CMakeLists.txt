cmake_minimum_required(VERSION 3.24.2)
project(Chess)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Chess ${SOURCES})
