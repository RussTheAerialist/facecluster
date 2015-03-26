#include <iostream>

#include <tclap/CmdLine.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv_adapters.h"
#include "version.h"
#include "rectangle.h"
#include "point_extractor.h"

using namespace af::common;

// ./feature_extractor -v ../../../contrib/asmlib-opencv/data/color_asm75.model ../../../samples/1.jpg 84,120+346x346
// ./feature_extractor -v ../../../contrib/asmlib-opencv/data/color_asm75.model ../../../samples/2.jpg 349,144+395x395
// ./feature_extractor -v ../../../contrib/asmlib-opencv/data/color_asm75.model ../../../samples/3.jpg 154,164+246x246
// ./feature_extractor -v ../../../contrib/asmlib-opencv/data/color_asm75.model ../../../samples/4.jpg 346,124+283x283

int run(const std::string& model_path, const std::string& image_path, const Rectangle& faceBox, bool display )
{
    // Load Image
    cv::Mat original = cv::imread(image_path);
    

    
    // Extract Feature Points
    PointExtractor extractor(model_path);
    if (display) {
        extractor.display(original, faceBox);
        cv::waitKey();
    } else {
        auto points = extractor.extract(original, faceBox);
        std::cout << "Points:";
        for(auto& e : points)
        {
            std::cout << " " << e.x << "," << e.y;
        }
        std::cout << std::endl;
    }
    
    return 0;
}

int main(int argc, char **argv)
{
    try {
        TCLAP::CmdLine cmd("Extract Facial Feature Points", ' ', PROJECT_VERSION);
        
        TCLAP::UnlabeledValueArg<std::string> modelPathArg("modelPath", "Path to the ASM model",
                                                           true, "muct76.model", "path");
        cmd.add(modelPathArg);

        
        TCLAP::UnlabeledValueArg<std::string> imagePathArg("imagePath", "Path to the image to use", true, "image.jpg", "path");
        cmd.add(imagePathArg);
        
        TCLAP::UnlabeledValueArg<std::string> boundingBoxArg("boundingBox", "Face bounding box", true, "X,Y+WxH", "box string");
        cmd.add(boundingBoxArg);
        
        TCLAP::SwitchArg displayArg("v", "view", "display points overlayed on the image", false);
        cmd.add(displayArg);
        
        cmd.parse(argc, argv);
        return run(modelPathArg.getValue(), imagePathArg.getValue(),
                   Rectangle::fromString(boundingBoxArg.getValue()), displayArg.getValue());
        
    } catch (TCLAP::ArgException &e) {
        std::cerr << "Error: " << e.error() << " for arg " << e.argId() << std::endl;
        return -2;
    }
    
}