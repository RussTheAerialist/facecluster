set(fe_SRC
    src/main.cpp
    src/point_extractor.cpp
)

set(fe_HDR
    include/point_extractor.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ASM_INCLUDE_DIR}
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(feature_extractor
    ${fe_SRC}
    ${fe_HDR}
)

add_dependencies(feature_extractor asm aboutface_common)
target_link_libraries(feature_extractor
    aboutface_common
    ${OpenCV_LIBS}
    asm
)

install(TARGETS feature_extractor
        DESTINATION ${CMAKE_SOURCE_DIR}/dist/${RELEASE_PATH}
)
