/* Include our modules */
#include "imageManipulator.hpp"

/**************************************
 * IMAGE MANIPULATOR CLASS
 * ***********************************/

/* Constructor */
ImageManipulator::ImageManipulator(char *imageName)
{
    this->setOriginalImage(imageName);
}

/* Getters */
Mat ImageManipulator::getOriginalImage()
{
    return image;
}

Mat ImageManipulator::getImage()
{
    return image;
}

state ImageManipulator::getState()
{
    return imageState;
}

/* Setters */
int ImageManipulator::setOriginalImage(char *imageName)
{
    Mat img = imread(imageName);
    if (img.empty())
    {
        return IMAGE_IS_EMPTY;        
    }
    this->originalImage = img;
    this->image = img;
    this->imageState.color = IS_COLORED;
    return 0;
}

/* Reset function */
int ImageManipulator::reset() {
    image = originalImage;
    imageState.color = IS_COLORED;
    return 0;
}

/* Set image to its grey version */
int ImageManipulator::imageToGrey()
{
    if (imageState.color == IS_COLORED)
    {
        Mat greyImage;
        // get grey image from colored image
        cvtColor(image, greyImage, COLOR_BGR2GRAY);
        image = greyImage;
        imageState.color = IS_GREY;
    }
    return 0;
}

/* Set image to its colored version */
int ImageManipulator::imageToColor()
{
    if (imageState.color == IS_GREY)
    {
        Mat coloredImage;
        // get colored image from grey image
        cvtColor(image, coloredImage, COLOR_GRAY2BGR);
        image = coloredImage;
        imageState.color = IS_COLORED;
    }
    return 0;
}

/* Set image to a blurred version using classic blur */
int ImageManipulator::blurImage(int kernelX, int kernelY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    Mat blurredImage;
    // blur image
    blur(image, blurredImage, Size(kernelX, kernelY));
    image = blurredImage;
    return 0;
}

/* Set image to a blurred version using classic blur */
int ImageManipulator::blurImage(int kernelXY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    return blurImage(kernelXY, kernelXY, anchor, borderType);
}

/* Set image to a blurred version using gaussian blur */
int ImageManipulator::gaussianBlurImage(int kernelX, int kernelY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    Mat gaussianBlurredImage;
    // gaussian blur image
    GaussianBlur(image, gaussianBlurredImage, Size(kernelX, kernelY), sigmaX, sigmaY, borderType);
    image = gaussianBlurredImage;
    return 0;
}

/* Set image to a blurred version using gaussian blur */
int ImageManipulator::gaussianBlurImage(int kernelXY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    return gaussianBlurImage(kernelXY, kernelXY, sigmaX, sigmaY, borderType);
}

/* Get a rotated version of ImageManipulator current image using warpAffine with rotation matrix 2D */
int ImageManipulator::rotateImage(double angle, double scale /*= (1.0)*/, int flags /*= 1*/, int borderMode /*= 0*/, const Scalar &borderValue /*= Scalar()*/)
{
    Mat rotated;
    // defining center
    Point2f center(image.cols/2, image.rows/2);
    // getting the matrix which will define the rotation
    Mat M = getRotationMatrix2D(center, angle, scale);
    // rotating the image
    warpAffine(image, rotated, M, image.size(), flags, borderMode, borderValue);
    image = rotated;
    return 0;
}
