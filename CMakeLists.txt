cmake_minimum_required(VERSION 3.8)

project(prcg_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE prcg_test)

find_package(OpenCV REQUIRED)
find_package(platercg REQUIRED)

set(PROJECT_LIBRARIES ${OpenCV_LIBS} platercg stdc++fs)

add_executable(${EXECUTABLE} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE} ${PROJECT_LIBRARIES})
