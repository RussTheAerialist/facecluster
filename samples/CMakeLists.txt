set (SAMPLE_FILES
    1.jpg
    2.jpg
    3.jpg
)

install(FILES ${SAMPLE_FILES}
    DESTINATION ${CMAKE_SOURCE_DIR}/dist/${RELEASE_PATH}/samples
)
