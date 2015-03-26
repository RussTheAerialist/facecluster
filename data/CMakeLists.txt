set (DATA_FILES
    haarcascade_frontalface_alt2.xml
    haarcascade_profileface.xml
)

install(FILES ${DATA_FILES}
    DESTINATION ${CMAKE_SOURCE_DIR}/dist/data
)
