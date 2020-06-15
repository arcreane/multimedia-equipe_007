/* Include our modules */
#include "imageManipulator.hpp"

/**************************************
 * IMAGE MANIPULATOR CLASS
 * ***********************************/

/* Constructors */
ImageManipulator::ImageManipulator()
{
    this->slider = 5;
}

ImageManipulator::ImageManipulator(char *imageName)
{
    this->setOriginalImage(imageName);
    this->slider = 5;
}

/* Getters */
Mat ImageManipulator::getOriginalImage()
{
    return originalImage;
}

Mat ImageManipulator::getImage()
{
    return currentImageState.image;
}

ImageColorType ImageManipulator::getColorType()
{
    return currentImageState.colorType;
}

/* Setters */
int ImageManipulator::setImage(Mat newImage)
{
    currentImageState.image = newImage;
    return 0;
}

int ImageManipulator::setOriginalImage(char *imageName)
{
    Mat img = imread(imageName);
    if (img.empty())
    {
        return IMAGE_IS_EMPTY;
    }
    originalImage = img;
    setImage(img);
    currentImageState.colorType = BGR_IMAGE;
    return 0;
}

/* Reset function */
int ImageManipulator::reset()
{
    setImage(originalImage);
    currentImageState.colorType = BGR_IMAGE;
    return 0;
}

/* Set image to its grey version */
int ImageManipulator::imageToGrey()
{
    Mat greyImage;
    // get grey image from colored image
    cvtColor(currentImageState.image, greyImage, COLOR_BGR2GRAY);
    currentImageState.colorType = GRAY_IMAGE;
    setImage(greyImage);
    return 0;
}

/* Set image to a blurred version using classic blur */
Mat ImageManipulator::blurImage(int kernelX, int kernelY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    Mat blurredImage;
    // blur image
    blur(currentImageState.image, blurredImage, Size(kernelX, kernelY), anchor, borderType);
    return blurredImage;
}

/* Set image to a blurred version using classic blur */
Mat ImageManipulator::blurImage(int kernelXY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    return blurImage(kernelXY, kernelXY, anchor, borderType);
}

/* Set image to a blurred version using gaussian blur */
Mat ImageManipulator::gaussianBlurImage(int kernelX, int kernelY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    Mat gaussianBlurredImage;
    // gaussian blur image
    GaussianBlur(currentImageState.image, gaussianBlurredImage, Size(kernelX, kernelY), sigmaX, sigmaY, borderType);
    return gaussianBlurredImage;
}

/* Set image to a blurred version using gaussian blur */
Mat ImageManipulator::gaussianBlurImage(int kernelXY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    return gaussianBlurImage(kernelXY, kernelXY, sigmaX, sigmaY, borderType);
}

/* Get a rotated version of ImageManipulator current image using warpAffine with rotation matrix 2D */
int ImageManipulator::rotateImage(double angle, double scale /*= (1.0)*/, int flags /*= 1*/, int borderMode /*= 0*/, const Scalar &borderValue /*= Scalar()*/)
{
    Mat rotated;
    // defining center
    Point2f center(currentImageState.image.cols / 2, currentImageState.image.rows / 2);
    // getting the matrix which will define the rotation
    Mat M = getRotationMatrix2D(center, angle, scale);
    // rotating the image
    warpAffine(currentImageState.image, rotated, M, currentImageState.image.size(), flags, borderMode, borderValue);
    setImage(rotated);
    return 0;
}

/* Lighten & Contrast an Image */
Mat ImageManipulator::brightenAndContrastImage(double alpha /*= (1.0)*/, double beta /*= (0.0)*/, int rtype /*= (-1)*/)
{
    Mat newImage;
    //increase or decrease the brightness or the contrast; alpha -> contrast; beta -> brightness
    currentImageState.image.convertTo(newImage, rtype, alpha, beta);
    return newImage;
}

/* Contrast an Image */
Mat ImageManipulator::contrastImage(double beta /*= (0.0)*/, int rtype /*= (-1)*/)
{
    //increase or decrease the brightness
    return brightenAndContrastImage(1, beta, rtype);
}

/* Lighten an Image */
Mat ImageManipulator::brightenImage(double alpha /*= (1.0)*/, int rtype /*= (-1)*/)
{
    //increase or decrease the brightness
    return brightenAndContrastImage(alpha, 0, rtype);
}

/* Resize an Image */
Mat ImageManipulator::resizeImage(double fx /*= (0.0)*/, double fy /*= (0.0)*/, int interpolation /*= (1)*/)
{
    Mat dest;
    // Scaling down or/and up the image
    resize(currentImageState.image, dest, Size(), fx, fy, interpolation);
    return dest;
}

/* Resize an Image */
Mat ImageManipulator::resizeImage(double fxfy /*= (0.0)*/, int interpolation /*= (1)*/)
{
    return resizeImage(fxfy, fxfy, interpolation);
}

/* Crop an Image */
int ImageManipulator::cropImage(int height, int width)
{
    //Cropped image
    setImage(currentImageState.image(Range(0, currentImageState.image.size().height - height), Range(0, currentImageState.image.size().width - width)));
    return 0;
}

/* Dilate an Image */
Mat ImageManipulator::dilateImage(int dilation_elem, int dilation_size)
{
    int dilation_type;
    switch(dilation_elem){
    case 0:
        dilation_type = MORPH_RECT;
        break;
    case 1:
        dilation_type = MORPH_CROSS;
        break;
    case 2:
        dilation_type = MORPH_ELLIPSE;
        break;
    default:
        break;
    }
    // get size and point and create element mat
    Size size = Size(2 * dilation_size + 1, 2 * dilation_size + 1);
    Point point = Point(dilation_size, dilation_size);
    Mat element = getStructuringElement(dilation_type, size, point);
    // create dilatated image and apply the dilation operation
    Mat dilatedImage;
    dilate(currentImageState.image, dilatedImage, element);
    return dilatedImage;
}

/* Erode an Image */
Mat ImageManipulator::erodeImage(int erosion_elem, int erosion_size)
{
    int erosion_type;
    if (erosion_elem == 0)
    {
        erosion_type = MORPH_RECT;
    }
    else if (erosion_elem == 1)
    {
        erosion_type = MORPH_CROSS;
    }
    else if (erosion_elem == 2)
    {
        erosion_type = MORPH_ELLIPSE;
    }
    Size size = Size(2 * erosion_size + 1, 2 * erosion_size + 1);
    Point point = Point(erosion_size, erosion_size);
    Mat element = getStructuringElement(erosion_type, size, point);
    Mat erodedImage;
    // Apply the erosions operation
    erode(currentImageState.image, erodedImage, element);
    return erodedImage;
}

/* Panorama */

/* First we need to take images from a source and instantiate a stitching mode */
int ImageManipulator::createOwnStitcher(string &entry_path) {
    Stitcher::Mode mode = Stitcher::PANORAMA;
    vector<Mat> images;
    string panorama_name = "panorama.jpg";
    string panorama_output_path = "/../assets/panorama-output/";
    /* Read input files from a given directory */
    DIR *dir;
    struct dirent *entry;
    if( dir = opendir(entry_path.c_str()) ){
        while(entry = readdir(dir)){
                        /* For each found image, we instantiate a Mat object and we add it to the vector */
                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ) {
                            Mat image = imread(entry_path + "/" + entry->d_name, IMREAD_COLOR);
                            if(!image.data) {
                                cout << "could not open image " << entry->d_name << endl;
                            } else {
                                images.push_back(image);
                            }
                        }  
                } 
        closedir(dir);
    }
    /* Now that we have images, mode and the output path, we can generate the panorama */
    createOwnPanorama(images, mode, panorama_output_path, panorama_name);

    return 0;
}

/* With a list of images as a vector, we can now create a panorama with the specified stitching mode */
void ImageManipulator::createOwnPanorama(vector<Mat> images, Stitcher::Mode mode, string panorama_output_path, string panorama_name) {

    Mat pano;
    Ptr<Stitcher> stitcher = Stitcher::create(mode);
    Stitcher::Status status = stitcher->stitch(images, pano);
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << " - is the common area enough large? " << endl;
        return;
    }

    DIR *dir;
    struct dirent *entry;

    /* If there is no current image being edited, we display the result as an image.
       Else, we open a new window containing the result because we don't want to replace current content due to the fact that panorama
       is not an editing functionality.
    */
    imshow("Panorama result", pano);
//    if(getImage().empty()) {
//        setImage(pano);
//    } else {
//        imshow("Panorama result", pano);
//    }

    if( dir = opendir(panorama_output_path.c_str()) ) {
        imwrite(panorama_output_path + panorama_name, pano);
        cout << "Stitching completed successfully!" << " Panorama saved in : " << panorama_output_path;
    } else {
        cout << "The given output directory does not exist." << endl;
        cout << panorama_output_path << endl;
    }   
}

/* Canny edge image detection */

// instantiating a CannyBody struct to set required properties to process a canny edge detection
CannyBody cannyBody;

// Setting properties related to canny edge detection
CannyBody ImageManipulator::generateCannyProperties() {

    cannyBody.lowThreshold = 0;
    cannyBody.max_lowThreshold = 100;
    cannyBody.ratio = 3;
    cannyBody.kernel_size = 3;
    cannyBody.window_name = "Canny edged image";

    cannyBody.src = currentImageState.image;

    if(cannyBody.src.empty()) {
        cout << "The specified image could not be found." << endl;
        return cannyBody;
    }

    cannyBody.dest.create( cannyBody.src.size(), cannyBody.src.type() );
    if (currentImageState.colorType == GRAY_IMAGE){
    // cvtColor( cannyBody.src, cannyBody.src_gray, COLOR_BGR2GRAY );

    } else {
         cvtColor( cannyBody.src, cannyBody.src_gray, COLOR_BGR2GRAY );
    }
    namedWindow( cannyBody.window_name, WINDOW_AUTOSIZE );

    createTrackbar( "Min Threshold:", cannyBody.window_name, &cannyBody.lowThreshold, cannyBody.max_lowThreshold, startCannyDetection);
    startCannyDetection(0, 0);
    waitKey(0);
    return cannyBody;
}

/* Launching Canny on the image with parameters supplied above */
void startCannyDetection(int, void*)
{    
    blur( cannyBody.src_gray, cannyBody.detected_edges, Size(3,3) );
    Canny( cannyBody.detected_edges, cannyBody.detected_edges, cannyBody.lowThreshold, cannyBody.lowThreshold * cannyBody.ratio, cannyBody.kernel_size );
    cannyBody.dest = Scalar::all(0);
    cannyBody.src.copyTo( cannyBody.dest, cannyBody.detected_edges);
    imshow( cannyBody.window_name, cannyBody.dest );
}

