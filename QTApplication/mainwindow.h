#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "imageManipulator.hpp"

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QtPrintSupport/QPrinter>
#include <opencv2/opencv.hpp>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void open();
    void reset();
    void imageToGrey();
    void detectEdges();
    void createPanorama();
    void blurImage(int kernelXY);
    void rotateImageP90();
    void rotateImageM90();
    void customRotate();
    void resizeImage();
    void contrastImage(int beta = 0);
    void brightenImage(int alpha = 1);
    void resizeImage(int scale);
    void cropImage();
    void dilateImage(int dilation_size);
    void erodeImage(int erode_size);

private:
    // private attributes
    Ui::MainWindow *ui;
    QLabel *imageLabel;
    ImageManipulator *imageManipulator;
    bool imageIsLoaded;
    Mat imageToModify;
    int width;
    int height;
    double angle;
    // private functions
    void setAngle(double angle);
    double getAngle();
    void showImage(Mat mat);
    void refreshImage();
    void initializeAll();
    void resetAll();
    void connectAll();
    void classicBlurImage(int kernelXY, Point anchor = Point(-1, -1), int borderType = 4);
    void gaussianBlurImage(int kernelXY, double sigmaX = (0.0), double sigmaY = (0.0), int borderType = 4);
};

#endif // MAINWINDOW_H
