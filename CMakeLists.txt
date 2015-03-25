cmake_minimum_required(VERSION 2.8)
PROJECT (faceCluster)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    "${CMAKE_SOURCE_DIR}/contrib/FindTBB/CMake/FindTBB/"
    "${CMAKE_SOURCE_DIR}/CMake/"
)
include("Version")
include_directories(${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)

find_package(TBB REQUIRED)
include_directories(${TBB_INCLUDE_DIR})

find_package(TCLAP REQUIRED)
include_directories(${TCLAP_INCLUDE_DIR})

add_definitions(-std=c++11)

add_subdirectory(annotators)
