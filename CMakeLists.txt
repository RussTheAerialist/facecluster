cmake_minimum_required(VERSION 2.8)
PROJECT (aboutFace)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    "${CMAKE_SOURCE_DIR}/contrib/FindTBB/CMake/FindTBB/"
    "${CMAKE_SOURCE_DIR}/CMake/"
)
include("Version")
include_directories(${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "opencv = ${OpenCV_VERSION}")

find_package(TBB REQUIRED)
include_directories(${TBB_INCLUDE_DIR})

find_package(TCLAP REQUIRED)
include_directories(${TCLAP_INCLUDE_DIR})

add_definitions(-std=c++11)

add_subdirectory(common)
include_directories(${CMAKE_SOURCE_DIR}/common/include)

add_subdirectory(annotators)
add_subdirectory(data)
add_subdirectory(samples)
