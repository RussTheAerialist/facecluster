#include <iostream>

#include <tclap/CmdLine.h>
#include "version.h"
#include "rectangle.h"

// 84,120+346x346 1.jpg

int run(const std::string& imagePath, const Rectangle& faceBox, bool display )
{
    // Load Image
    // Set ROI from Rectangle
    // Skin Hue Averager
    // Skin Hue Discriminator
    
    // Output skin category
    
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