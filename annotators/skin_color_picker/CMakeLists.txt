set(skin_color_picker_SRC
    src/main.cpp
    src/skin_hue_averager.cpp
)

set(skin_color_picker_HEADERS
    include/skin_hue_averager.h
)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

LINK_DIRECTORIES(
    ${CMAKE_BINARY_DIR}/bin
    ${TBB_LIBRARY_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable( skin_color_picker
    ${skin_color_picker_HEADERS}
    ${skin_color_picker_SRC}
)

target_link_libraries( skin_color_picker
    aboutface_common
    ${OpenCV_LIBS}
)

install(TARGETS skin_color_picker
    DESTINATION ${CMAKE_SOURCE_DIR}/dist/${RELEASE_PATH}
)
