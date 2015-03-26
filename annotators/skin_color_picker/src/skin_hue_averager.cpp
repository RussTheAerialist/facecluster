#include "skin_hue_averager.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui//highgui.hpp>

class SkinHueAverager::SkinHueAveragerImpl {
    static const float MIN_HUE;
    static const float MAX_HUE;
};

const float SkinHueAverager::SkinHueAveragerImpl::MIN_HUE = 0;
const float SkinHueAverager::SkinHueAveragerImpl::MAX_HUE = 1;

SkinHueAverager::SkinHueAverager()
: pimpl(new SkinHueAverager::SkinHueAveragerImpl())
{
    
}

SkinHueAverager::~SkinHueAverager() = default;

float SkinHueAverager::average(cv::Mat &face)
{
    return 0;
}

float SkinHueAverager::display(cv::Mat &face)
{
    cv::Mat hsvFace;
    cv::cvtColor(face, hsvFace, CV_BGR2HSV);
    
    cv::imshow("Skin Hue Averager", hsvFace);
    
    return 0;
}