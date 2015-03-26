set(face_isolator_SRC
    src/main.cpp
    src/face_isolator.cpp
)

set(face_isolator_HEADERS
    include/face_isolator.h
)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
      message(STATUS "dir='${dir}'")
  endforeach()

LINK_DIRECTORIES(
    ${CMAKE_BINARY_DIR}/bin
    ${TBB_LIBRARY_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable( face_isolator
    ${face_isolator_HEADERS}
    ${face_isolator_SRC}
)

target_link_libraries( face_isolator
    aboutface_common
    ${OpenCV_LIBS}
)
