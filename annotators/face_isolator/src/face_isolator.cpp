#include "rectangle.h"
#include "face_isolator.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using FindFaceReturn = std::pair<bool, Rectangle>;
const FindFaceReturn FailedFindFace = FindFaceReturn(false, Rectangle());

Rectangle makeRectangle(cv::Rect_<int>& in_rect)
{
    return Rectangle(in_rect.x, in_rect.y, in_rect.width, in_rect.height);
}

class FaceIsolator::FaceIsolatorImpl {
public:
    FaceIsolatorImpl(std::string frontal, std::string profile)
    {
        frontal_classifier.load(frontal);
        profile_classifier.load(profile);
    }
    
    virtual ~FaceIsolatorImpl() = default;
    
    FindFaceReturn find_face(const std::string& path)
    {
        cv::Mat original = cv::imread(path);
        if (!original.data) // Failed to load file
        {
            return FailedFindFace;
        }
        
        return get_face_bounding_box(original);
    }
    
    bool show_face(const std::string& path)
    {
        cv::Mat original = cv::imread(path);
        if (!original.data)
        {
            return false;
        }
        
        const auto& face = get_face_bounding_box(original);
        
        if (!face.first) {
            return false;
        }
        
        cv::rectangle(original, cv::Rect_<int>(face.second.x, face.second.y, face.second.width, face.second.height), CV_RGB(0, 255, 0), 1);
        cv::imshow("Face Isolator", original);
        cv::waitKey();
        
        return true;
    }
    
private:
    
    FindFaceReturn get_face_bounding_box(cv::Mat& original)
    {
        cv::Mat gray;
        cv::cvtColor(original, gray, CV_BGR2GRAY); // Convert to grayscale
        
        std::vector< cv::Rect_<int> > faces;
        frontal_classifier.detectMultiScale(gray, faces);
        if (faces.size() == 0) {
            profile_classifier.detectMultiScale(gray, faces);
        }
        
        if (faces.size() == 0) {
            return FailedFindFace;
        }
        
        return FindFaceReturn(true, makeRectangle(faces[0]));
    }
    
    cv::CascadeClassifier frontal_classifier;
    cv::CascadeClassifier profile_classifier;
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

bool FaceIsolator::show_face(const std::string& path)
{
    return pimpl->show_face(path);
}
