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
    void showImage(Mat mat);
    void refreshImage();
    void reset();
    void undo();
    void redo();
    void imageToGrey();
    void detectEdges();
    void createPanorama();
    void imageToColor();
    void blurImage(int kernelX, int kernelY, Point anchor = Point(-1, -1), int borderType = 4);
    void blurImage(int kernelXY, Point anchor = Point(-1, -1), int borderType = 4);
    void gaussianBlurImage(int kernelX, int kernelY, double sigmaX = (0.0), double sigmaY = (0.0), int borderType = 4);
    void gaussianBlurImage(int kernelXY, double sigmaX = (0.0), double sigmaY = (0.0), int borderType = 4);
    void rotateImage(double angle, double scale = (1.0), int flags = 1, int borderMode = 0, const Scalar &borderValue = Scalar());
    void brightenAndContrastImage(double alpha = (1.0), double beta = (0.0), int rtype = -1);
    void brightenImage(double beta = (0.0), int rtype = (-1));
    void lightenImage(double alpha = (1.0), int rtype = (-1));
    void resizeImage(Size dsize, double fx = (0.0), double fy = (0.0), int interpolation = 1);
    void cropImage(int height, int width);
    void dilateImage(int dilation_elem, int dilation_size);
    void erodeImage(int dilation_elem, int dilation_size);

private:
    Ui::MainWindow *ui;
    QLabel *imageLabel;
    ImageManipulator *imageManipulator;
    bool imageIsLoaded;
};

#endif // MAINWINDOW_H
