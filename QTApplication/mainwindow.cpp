#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qscreen.h"
#include "qfiledialog.h"
#include "qgridlayout.h"
#include "qpushbutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageLabel = new QLabel((ui->imageWidget));
    imageLabel->resize(ui->imageWidget->width(),ui->imageWidget->height());
    imageManipulator = new ImageManipulator();
    imageIsLoaded = false;
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showImage(Mat mat)
{
    if (imageManipulator->getColorType() == GRAY_IMAGE){
        cvtColor(mat, mat, CV_GRAY2RGB);
    } else {
        cvtColor(mat, mat, CV_BGR2RGB);
    }
    //transform matrice into a qimage
    QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    //set label pixmap with qimage
    QPixmap pixmap = QPixmap::fromImage(image);
    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
    imageLabel->show();
}

void MainWindow::refreshImage()
{
    showImage(imageManipulator->getImage());
}

void MainWindow::open()
{
    // get filename
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg)"));
    // convert it into char*
    QByteArray conversion = fileName.toLocal8Bit();
    char *c_fileName = conversion.data();
    // read image and show in gui
    imageManipulator->setOriginalImage(c_fileName);
    imageIsLoaded = true;
    refreshImage();
}

/* Reset function */
void MainWindow::reset()
{
    if (imageIsLoaded) {
        imageManipulator->reset();
        refreshImage();
    }
}

/* Undo function */
void MainWindow::undo()
{
    if (imageIsLoaded) {
        imageManipulator->undo();
        refreshImage();
    }
}

/* Redo function */
void MainWindow::redo()
{
    if (imageIsLoaded) {
        imageManipulator->redo();
        refreshImage();
    }
}

/* Set image to its grey version */
void MainWindow::imageToGrey()
{
    if (imageIsLoaded && (imageManipulator->getColorType() != GRAY_IMAGE)) {
        imageManipulator->imageToGrey();
        refreshImage();
    }
}

/* Set image to its colored version */
void MainWindow::imageToColor()
{
    if (imageIsLoaded) {
        imageManipulator->imageToColor();
        refreshImage();
    }
}

/* Set image to a blurred version using classic blur */
void MainWindow::blurImage(int kernelX, int kernelY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    imageManipulator->blurImage(kernelX, kernelY, anchor, borderType);
    refreshImage();
}

/* Set image to a blurred version using classic blur */
void MainWindow::blurImage(int kernelXY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    imageManipulator->blurImage(kernelXY, anchor, borderType);
    refreshImage();
}

/* Set image to a blurred version using gaussian blur */
void MainWindow::gaussianBlurImage(int kernelX, int kernelY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    imageManipulator->gaussianBlurImage(kernelX, kernelY, sigmaX, sigmaY, borderType);
    refreshImage();
}

/* Set image to a blurred version using gaussian blur */
void MainWindow::gaussianBlurImage(int kernelXY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    imageManipulator->gaussianBlurImage(kernelXY, sigmaX, sigmaY, borderType);
    refreshImage();
}

/* Get a rotated version of ImageManipulator current image using warpAffine with rotation matrix 2D */
void MainWindow::rotateImage(double angle, double scale /*= (1.0)*/, int flags /*= 1*/, int borderMode /*= 0*/, const Scalar &borderValue /*= Scalar()*/)
{
    imageManipulator->rotateImage(angle, scale, flags, borderMode, borderValue);
    refreshImage();
}

/* Lighten & Contrast an Image */
void MainWindow::brightenAndContrastImage(double alpha /*= (1.0)*/, double beta /*= (0.0)*/, int rtype /*= (-1)*/)
{
    imageManipulator->brightenAndContrastImage(alpha, beta, rtype);
    refreshImage();
}

/* Contrast an Image */
void MainWindow::brightenImage(double beta /*= (0.0)*/, int rtype /*= (-1)*/)
{
    imageManipulator->brightenImage(beta, rtype);
    refreshImage();
}

/* Lighten an Image */
void MainWindow::lightenImage(double alpha /*= (1.0)*/, int rtype /*= (-1)*/)
{
    imageManipulator->lightenImage(alpha, rtype);
    refreshImage();
}

/* Resize an Image */
void MainWindow::resizeImage(Size dsize, double fx /*= (0.0)*/, double fy /*= (0.0)*/, int interpolation /*= (1)*/)
{
    imageManipulator->resizeImage(dsize, fx, fy, interpolation);
    refreshImage();
}

/* Crop an Image */
void MainWindow::cropImage(int height, int width)
{
    imageManipulator->cropImage(height, width);
    refreshImage();
}

/* Dilate an Image */
void MainWindow::dilateImage(int dilation_elem, int dilation_size)
{
    imageManipulator->dilateImage(dilation_elem, dilation_size);
    refreshImage();
}

/* Erode an Image */
void MainWindow::erodeImage(int erosion_elem, int erosion_size)
{
    imageManipulator->erodeImage(erosion_elem, erosion_size);
    refreshImage();
}



