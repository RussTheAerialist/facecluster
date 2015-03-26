#pragma once

#include <string>
#include <memory>

const std::string FRONTAL_CLASSIFIER_FILENAME = "haarcascade_frontalface_alt2.xml";
const std::string PROFILE_CLASSIFIER_FILENAME = "haarcascade_profileface.xml";

namespace af {
    namespace common {
        class Rectangle;
    }
}

using FindFaceReturn = std::pair<bool, af::common::Rectangle>;

class FaceIsolator
{
public:
    FaceIsolator(std::string frontal_classifier_path, std::string profile_classifier_path);
    virtual ~FaceIsolator();
    
    FindFaceReturn find_face(const std::string& path);
    bool show_face(const std::string& path);
    
private:
    class FaceIsolatorImpl;
    std::unique_ptr<FaceIsolatorImpl> pimpl;
};

