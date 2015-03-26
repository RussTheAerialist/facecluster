FIND_PACKAGE( OpenCV REQUIRED )
FIND_PACKAGE( TBB REQUIRED)

SET(LIB_SRC_LIST modelfile.cpp asmmodel.cpp shapevec.cpp similaritytrans.cpp afreader.cpp modelimage.cpp  shapemodel.cpp shapeinfo.cpp)

ADD_SUBDIRECTORY(lib)
