set(common_SRC
    src/rectangle.cpp
) 

set(common_HEADERS
    include/rectangle.h
    include/opencv_adapters.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(aboutface_common SHARED
    ${common_SRC}
    ${common_HEADERS}
)

install(TARGETS aboutface_common
    DESTINATION ${CMAKE_SOURCE_DIR}/dist
)
install(FILES ${common_HEADERS}
    DESTINATION ${CMAKE_SOURCE_DIR}/dist/include
)
