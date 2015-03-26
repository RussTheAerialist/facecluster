#include "skin_hue_averager.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui//highgui.hpp>

class SkinHueAverager::SkinHueAveragerImpl {
public:
    float display(cv::Mat &face);
    float average(cv::Mat &face);
    
private:
    static const cv::Scalar min_color;
    static const cv::Scalar max_color;
    
    cv::Mat get_skin_image(cv::Mat &face);
};

const cv::Scalar SkinHueAverager::SkinHueAveragerImpl::min_color(0, 48, 80);
const cv::Scalar SkinHueAverager::SkinHueAveragerImpl::max_color(25, 255, 255);

SkinHueAverager::SkinHueAverager()
: pimpl(new SkinHueAverager::SkinHueAveragerImpl())
{
    
}

SkinHueAverager::~SkinHueAverager() = default;

float SkinHueAverager::average(cv::Mat &face)
{
    return pimpl->average(face);
}

float SkinHueAverager::display(cv::Mat &face)
{
    return pimpl->display(face);
}


cv::Mat SkinHueAverager::SkinHueAveragerImpl::get_skin_image(cv::Mat &face)
{
    cv::Mat hsvFace;
    cv::cvtColor(face, hsvFace, CV_BGR2HSV_FULL);
    
    // Find Skin Tones
    cv::Mat skinMask;
    cv::inRange(hsvFace, SkinHueAverager::SkinHueAveragerImpl::min_color, SkinHueAverager::SkinHueAveragerImpl::max_color, skinMask);
    
    auto kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(8, 8));
    cv::Mat tmp;
    
    // Clean up Mask
    cv::erode(skinMask, tmp, kernel);
    cv::erode(tmp, skinMask, kernel);
    cv::dilate(skinMask, tmp, kernel);
    cv::dilate(tmp, skinMask, kernel);
    
    cv::GaussianBlur(skinMask, tmp, cv::Size(3, 3), 0);
    cv::bitwise_and(hsvFace, hsvFace, skinMask, tmp);

    return skinMask;
}


float SkinHueAverager::SkinHueAveragerImpl::display(cv::Mat &face)
{
    auto skinMask = get_skin_image(face);
    cv::imshow("face", skinMask);
    auto mean = cv::mean(skinMask);
    return mean.val[0];
}

float SkinHueAverager::SkinHueAveragerImpl::average(cv::Mat &face)
{
    auto skinMask = get_skin_image(face);
    auto mean = cv::mean(skinMask);
    return mean.val[0];
}