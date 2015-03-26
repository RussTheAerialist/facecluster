#pragma once

#include <opencv2/core/core.hpp>
#include "rectangle.h"

namespace af {
    namespace adapters {
        inline af::common::Rectangle makeRectangle(cv::Rect_<int>& in_rect)
        {
            return af::common::Rectangle(in_rect.x, in_rect.y, in_rect.width, in_rect.height);
        }

        inline cv::Rect_<int> makeCvRect(const af::common::Rectangle& rect) {
            return cv::Rect_<int>(rect.x, rect.y, rect.width, rect.height);
        }
    }
}
