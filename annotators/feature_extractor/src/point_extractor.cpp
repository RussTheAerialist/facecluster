/* code from the demo for asmlib-opencv
 
 void searchAndFit(
 ASMModel & asmModel,
 cv::CascadeClassifier &objCascadeClassfifier,
 const string & picPath,
 int verboseL) {
 // Load image.
 Mat img = cv::imread(picPath);
 if (img.empty()) {
 cerr << "Load image '" << picPath << "' failed." << endl;
 exit(2);
 }
 
 // Face detection.
 vector< cv::Rect > faces;
 objCascadeClassfifier.detectMultiScale(
 img, faces,
 1.2, 2, CV_HAAR_SCALE_IMAGE, Size(60, 60) );
 
 // Fit to ASM!
 vector < ASMFitResult > fitResult = asmModel.fitAll(img, faces, verboseL);
 asmModel.showResult(img, fitResult);
 cvWaitKey();
 }
 */

#include <vector>
#include <string>
#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv_adapters.h"
#include "rectangle.h"
#include "point_extractor.h"
#include "asmmodel.h"

using Point = cv::Point_<int>;

class PointExtractor::PointExtractorImpl
{
public:
    PointExtractorImpl(const std::string& model_path);
    void display(cv::Mat &image, const af::common::Rectangle& face);
    std::vector<Point> extract(cv::Mat &image, const af::common::Rectangle& face);
    
private:
    StatModel::ASMModel model;
    
    std::vector< StatModel::ASMFitResult > get_fit(cv::Mat &image, const af::common::Rectangle& face);
};

PointExtractor::PointExtractor(const std::string& model_path) :
    pimpl(new PointExtractorImpl(model_path))
{
}

PointExtractor::~PointExtractor() = default;

void PointExtractor::display(cv::Mat &image, const af::common::Rectangle &face)
{
    pimpl->display(image, face);
}

std::vector<Point> PointExtractor::extract(cv::Mat &image, const af::common::Rectangle& face)
{
    return pimpl->extract(image, face);
}

PointExtractor::PointExtractorImpl::PointExtractorImpl(const std::string& model_path)
{
    model.loadFromFile(model_path);
}

void PointExtractor::PointExtractorImpl::display(cv::Mat &image, const af::common::Rectangle& face)
{
    auto results = get_fit(image, face);
    model.showResult(image, results);
}

std::vector< Point > PointExtractor::PointExtractorImpl::extract(cv::Mat &image, const af::common::Rectangle& face)
{
    auto results = get_fit(image, face);
    std::vector< Point > points;
    
    results[0].toPointList(points);
    
    return points;
}


std::vector< StatModel::ASMFitResult > PointExtractor::PointExtractorImpl::get_fit(cv::Mat &image, const af::common::Rectangle& face)
{
    // Get Face Bounding Box, must be a vector for the asmlib api
    std::vector< cv::Rect_<int> > faces = { af::adapters::makeCvRect(face) };
    return model.fitAll(image, faces);
}

