# Search for tclap in normal locations as well as contrib

FIND_PATH(TCLAP_INCLUDE_DIR tclap/CmdLine.h
    /usr/local/include
    /usr/include
    /usr/local/Cellar/tclap/
    ${CMAKE_SOURCE_DIR}/contrib/tclap/include
    )
IF(TCLAP_INCLUDE_DIR)
    SET(TCLAP_FOUND TRUE)
ELSE()
    SET(TCLAP_FOUND FALSE)
ENDIF() 
