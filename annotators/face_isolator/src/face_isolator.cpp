#include "rectangle.h"
#include "face_isolator.h"

using FindFaceReturn = std::pair<bool, Rectangle>;

class FaceIsolator::FaceIsolatorImpl {
public:
    FaceIsolatorImpl(std::string frontal, std::string profile) {
    }
    
    virtual ~FaceIsolatorImpl() = default;
    
    FindFaceReturn find_face(const std::string& path) {
        return FindFaceReturn(false, Rectangle());
    }
};

FaceIsolator::FaceIsolator(std::string frontal_classifier_path, std::string profile_classifier_path) :
    pimpl(new FaceIsolator::FaceIsolatorImpl(frontal_classifier_path, profile_classifier_path))
{
}

FaceIsolator::~FaceIsolator() = default;

FindFaceReturn FaceIsolator::find_face(const std::string &path)
{
    return pimpl->find_face(path);
}