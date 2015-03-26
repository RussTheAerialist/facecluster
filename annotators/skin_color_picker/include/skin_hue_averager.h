#pragma once

#include <string>
#include <memory>
#include <opencv2/core/core.hpp>

class SkinHueAverager {
public:
    SkinHueAverager();
    virtual ~SkinHueAverager();
    
    float average(cv::Mat& face);
    float display(cv::Mat& face);
    
private:
    class SkinHueAveragerImpl;
    std::unique_ptr<SkinHueAveragerImpl> pimpl;
};