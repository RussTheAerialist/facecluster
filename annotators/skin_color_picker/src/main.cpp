#include <iostream>

#include <tclap/CmdLine.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv_adapters.h"
#include "version.h"
#include "rectangle.h"
#include "skin_hue_averager.h"

// 84,120+346x346 1.jpg

using namespace af::common;

int run(const std::string& path, const Rectangle& faceBox, bool display )
{
    std::cout << "RECT:" << faceBox.toString() << std::endl;
    // Load Image
    cv::Mat original = cv::imread(path);
    
    // Set ROI from Rectangle
    cv::Rect_<int> box = af::adapters::makeCvRect(faceBox);
    cv::Mat face = original(box);

    // Skin Hue Averager
    SkinHueAverager averager;
    
    float average_hue = -1;
    
    if (display)
    {
        average_hue = averager.display(face);
    } else {
        average_hue = averager.average(face);
    }
    // Skin Hue Discriminator
    
    // Output skin category
    
    if (display)
    {
        cv::waitKey();
    }
    
    return -1;
}

int main(int argc, char **argv)
{
    try {
        TCLAP::CmdLine cmd("Determine Skin Color Group", ' ', PROJECT_VERSION);
        
        TCLAP::UnlabeledValueArg<std::string> imagePathArg("imagePath", "Path to the image to use", true, "image.jpg", "path");
        cmd.add(imagePathArg);
        
        TCLAP::UnlabeledValueArg<std::string> boundingBoxArg("boundingBox", "Face bounding box", true, "X,Y+WxH", "box string");
        cmd.add(boundingBoxArg);
        
        TCLAP::SwitchArg displayArg("v", "view", "Draw the bounding box on the image", false);
        cmd.add(displayArg);
        
        cmd.parse(argc, argv);
        return run(imagePathArg.getValue(), Rectangle::fromString(boundingBoxArg.getValue()), displayArg.getValue());
        
    } catch (TCLAP::ArgException &e) {
        std::cerr << "Error: " << e.error() << " for arg " << e.argId() << std::endl;
        return -2;
    }
    
}