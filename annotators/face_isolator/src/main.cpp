#include "face_isolator.h"
#include "rectangle.h"

#include <iostream>
#include <tclap/CmdLine.h>

#include "version.h"

int run(const std::string& dataDirectory, const std::string& imagePath, bool display)
{
    std::string frontal_path = dataDirectory + "/" + FRONTAL_CLASSIFIER_FILENAME;
    std::string profile_path = dataDirectory + "/" + PROFILE_CLASSIFIER_FILENAME;
    
    FaceIsolator isolator(frontal_path, profile_path);
    
    if (display) {
        isolator.show_face(imagePath);
    } else {
        const auto& retval = isolator.find_face(imagePath);
    
        if (!retval.first) // Finding the face failed
        {
            std::cerr << "Error: Unable to find face in " << imagePath << std::endl;
            return -1;
        }
        std::cout << "Face: " << retval.second.toString() << std::endl;
    }
    return 0;
}

int main(int argc, char **argv)
{
    try {
        TCLAP::CmdLine cmd("Isolate the bounding box of the face and determine if frontal or profile", ' ', PROJECT_VERSION);
        
        TCLAP::ValueArg<std::string> dataDirectoryArg("d", "datadir", "Path to the data directory", false, "./data", "string");
        cmd.add(dataDirectoryArg);
        
        TCLAP::UnlabeledValueArg<std::string> imagePathArg("imagePath", "Path to the image to detect", true, "image.jpg", "string");
        cmd.add(imagePathArg);
        
        TCLAP::SwitchArg displayArg("v", "view", "Draw the bounding box on the image", false);
        cmd.add(displayArg);
        
        cmd.parse(argc, argv);
        return run(dataDirectoryArg.getValue(), imagePathArg.getValue(), displayArg.getValue());
        
    } catch (TCLAP::ArgException &e) {
        std::cerr << "Error: " << e.error() << " for arg " << e.argId() << std::endl;
        return -2;
    }
    
}