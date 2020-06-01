/* Include our modules */
#include "imageManipulator.hpp"

/**************************************
 * IMAGE MANIPULATOR CLASS
 * ***********************************/

/* Constructors */
ImageManipulator::ImageManipulator(){

}

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
int ImageManipulator::reset()
{
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
    Point2f center(image.cols / 2, image.rows / 2);
    // getting the matrix which will define the rotation
    Mat M = getRotationMatrix2D(center, angle, scale);
    // rotating the image
    warpAffine(image, rotated, M, image.size(), flags, borderMode, borderValue);
    image = rotated;
    return 0;
}

/* Lighten & Contrast an Image */
int ImageManipulator::brightenAndContrastImage(double alpha /*= (1.0)*/, double beta /*= (0.0)*/, int rtype /*= (-1)*/)
{
    //increase or decrease the brightness or the contrast; alpha -> contrast; beta -> brightness
    image.convertTo(image, rtype, alpha, beta);
    return 0;
}

/* Contrast an Image */
int ImageManipulator::brightenImage(double beta /*= (0.0)*/, int rtype /*= (-1)*/)
{
    //increase or decrease the brightness
    return brightenAndContrastImage(1, beta, rtype);
}

/* Lighten an Image */
int ImageManipulator::lightenImage(double alpha /*= (1.0)*/, int rtype /*= (-1)*/)
{
    //increase or decrease the brightness
    return brightenAndContrastImage(alpha, 0, rtype);
}

/* Resize an Image */
int ImageManipulator::resizeImage(Size dsize, double fx /*= (0.0)*/, double fy /*= (0.0)*/, int interpolation /*= (1)*/)
{
    Mat dest;
    // Scaling down or/and up the image
    resize(image, dest, dsize, fx, fy, interpolation);
    image = dest;
    return 0;
}

/* Crop an Image */
int ImageManipulator::cropImage(int height, int width)
{
    //Cropped image
    Mat crop = image(Range(0, image.size().height - height), Range(0, image.size().width - width));
    image = crop;
    return 0;
}

/* Dilate an Image */
int ImageManipulator::dilateImage(int dilation_elem, int dilation_size)
{

    int dilation_type;
    if (dilation_elem == 0)
    {
        dilation_type = MORPH_RECT;
    }
    else if (dilation_elem == 1)
    {
        dilation_type = MORPH_CROSS;
    }
    else if (dilation_elem == 2)
    {
        dilation_type = MORPH_ELLIPSE;
    }

    Mat element = getStructuringElement(dilation_type,
                                        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
                                        Point(dilation_size, dilation_size));

    Mat dilatedImage;
    /// Apply the dilation operation
    dilate(image, dilatedImage, element);

    image = dilatedImage;
    return 0;
}

/* Erode an Image */
int ImageManipulator::erodeImage(int erosion_elem, int erosion_size)
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

    Mat element = getStructuringElement(erosion_type,
                                        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
                                        Point(erosion_size, erosion_size));

    Mat erodedImage;

    /// Apply the erosions operation
    erode(image, erodedImage, element);

    image = erodedImage;
    return 0;
}

/* Panorama */

/* First we need to take images from a source and instantiate a stitching mode */
int ImageManipulator::createOwnStitcher(string &entry_path) {
    Stitcher::Mode mode = Stitcher::PANORAMA;
    vector<Mat> images;
    string panorama_name = "panorama.jpg";
    string panorama_output_path = "../assets/panorama-output/";
    /* Read input files from a given directory */
    DIR *dir;
    struct dirent *entry;
    if( dir = opendir(entry_path.c_str()) ){
        while(entry = readdir(dir)){
                        /* For each found image, we instantiate a Mat object and we add it to the vector */
                        if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ) {
                            Mat image = imread(entry_path + entry->d_name, IMREAD_COLOR);
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
CannyBody ImageManipulator::generateCannyProperties(string &entry_path) {

    cannyBody.lowThreshold = 0;
    cannyBody.max_lowThreshold = 100;
    cannyBody.ratio = 3;
    cannyBody.kernel_size = 3;
    cannyBody.window_name = "Canny edged image";

    cannyBody.src = imread(entry_path, IMREAD_COLOR);

    if(cannyBody.src.empty()) {
        cout << "The specified image could not be found." << endl;
        return cannyBody;
    }

    cannyBody.dest.create( cannyBody.src.size(), cannyBody.src.type() );
    cvtColor( cannyBody.src, cannyBody.src_gray, COLOR_BGR2GRAY );
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

