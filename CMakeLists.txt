cmake_minimum_required(VERSION 3.7)
project(ImgProc)                 
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES rgb2gray.cpp)
add_executable(ImgProc ${SOURCE_FILES})

# OpenCV wibs
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ImgProc ${OpenCV_LIBS})
