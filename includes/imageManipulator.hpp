#ifndef __IMAGE_MANIPULATOR__
#define __IMAGE_MANIPULATOR__

/* Include external libraries */
#include <opencv2/opencv.hpp>

/* Macros */
#define IS_COLORED 1
#define IS_GREY 2

#define IMAGE_IS_EMPTY -1

/* Namespaces */
using namespace std;
using namespace cv;

/* State structore for image */
struct state{
    int color = IS_COLORED;
};

/* ImageManipulator Class */
class ImageManipulator 
{
    private:
        Mat image;
        Mat originalImage;
        state imageState;

    public:
        // Constructor
        ImageManipulator(char *imageName);
        // Getters
        Mat getOriginalImage();
        Mat getImage();
        state getState();
        // Setters
        int setOriginalImage(char *imageName);
        // Methods
        int reset();
        int imageToGrey();
        int imageToColor();
        int blurImage(int kernelX, int kernelY, Point anchor = Point(-1,-1), int borderType = 4);
        int blurImage(int kernelXY, Point anchor = Point(-1,-1), int borderType = 4);
        int gaussianBlurImage(int kernelX, int kernelY, double sigmaX = (0.0), double sigmaY = (0.0), int borderType = 4);
        int gaussianBlurImage(int kernelXY, double sigmaX = (0.0), double sigmaY = (0.0), int borderType = 4);
        int rotateImage(double angle, double scale = (1.0), int flags = 1, int borderMode = 0, const Scalar &borderValue = Scalar());
};

#endif