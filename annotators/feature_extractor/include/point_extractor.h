#pragma once

#include <memory>
#include <vector>
#include <opencv2/core/core.hpp>

namespace af {
    namespace common {
        class Rectangle;
    }
}

using Point = cv::Point_<int>;

class PointExtractor
{
public:
    PointExtractor(const std::string& model_path);
    virtual ~PointExtractor();
    
    void display(cv::Mat& image, const af::common::Rectangle& face);
    std::vector<Point> extract(cv::Mat& image, const af::common::Rectangle& face);
    
private:
    class PointExtractorImpl;
    std::unique_ptr<PointExtractorImpl> pimpl;
};