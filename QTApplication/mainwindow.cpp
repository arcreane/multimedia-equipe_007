#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qscreen.h"
#include "qfiledialog.h"
#include "qgridlayout.h"
#include "qpushbutton.h"
#include "qslider.h"
#include "qlineedit.h"
#include "qmessagebox.h"

/* CONSTRUCTOR */
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
    ui->containerWidget->setVisible(false);
    initializeAll();
    connectAll();
}

/* DESTRUCTOR */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showImage(Mat mat)
{
   if (imageIsLoaded) {
        if (imageManipulator->getColorType() == GRAY_IMAGE){
            cvtColor(mat, mat, CV_GRAY2RGB);
        }
        //transform matrice into a qimage
        QImage image= QImage((uchar*) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888).rgbSwapped();
        //set label pixmap with qimage
        QPixmap pixmap = QPixmap::fromImage(image);

        //imageLabel->resize(mat.size().width,mat.size().height);

        imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
        imageLabel->show();
        ui->containerWidget->setVisible(true);
   }
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
    int w = imageManipulator->getImage().size().width;
    int h = imageManipulator->getImage().size().height;
    width=w;
    height=h;
    ui->resizeW->setPlaceholderText(QString::number(w));
    ui->resizeH->setPlaceholderText(QString::number(h));
    refreshImage();
}

/* Reset function */
void MainWindow::reset()
{
    if (imageIsLoaded) {
        imageManipulator->reset();
        refreshImage();
        resetAll();
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

void MainWindow::initializeAll()
{
    ui->slider_blur->setRange(1, 41);
    ui->slider_contrast->setRange(-100, 100);
    ui->slider_brightness->setRange(100, 1000);

    resetAll();
}

void MainWindow::resetAll()
{
    ui->slider_blur->setValue(1);
    ui->slider_contrast->setValue(0);
    ui->slider_brightness->setValue(100);


}

void MainWindow::connectAll()
{
    connect(ui->slider_blur, SIGNAL(valueChanged(int)), this, SLOT(blurImage(int)));
    connect(ui->slider_contrast,SIGNAL(valueChanged(int)), this, SLOT(contrastImage(int)));
    connect(ui->slider_brightness,SIGNAL(valueChanged(int)), this, SLOT(brightenImage(int)));
    connect(ui->buttonRotateP90, SIGNAL(clicked()), this, SLOT(rotateImageP90()));
    connect(ui->buttonRotateM90, SIGNAL(clicked()), this, SLOT(rotateImageM90()));
    connect(ui->customRotate, SIGNAL(clicked()), this, SLOT(customRotate()));
    connect(ui->resizeButton, SIGNAL(clicked()), this, SLOT(resizeImage()));
}

/* resize image slot */
void MainWindow::resizeImage(){
    if(imageIsLoaded){
        QString w = ui->resizeW->text();
        QString h = ui->resizeH->text();

        Mat mat = imageManipulator->getImage();

        if ((w.toInt()>=width)|| (h.toInt()>=height)){
            QMessageBox::information(
                this,
                tr("Invalid data"),
                tr("Please choose values under the original size") );
        }

        else if ((w.isEmpty())|| (h.isEmpty())){
            QMessageBox::information(
                this,
                tr("Invalid data"),
                tr("Please choose for both values") );
        }

        else {

        ui->resizeW->setPlaceholderText(w);
        ui->resizeH->setPlaceholderText(h);

        //imageManipulator->resizeImage(w.toInt()/width, h.toInt()/height);

        imageManipulator->resizeImage(w.toInt()/width, h.toInt()/height);

        //transform matrice into a qimage
        QImage image= QImage((uchar*) mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888).rgbSwapped();
        //set label pixmap with qimage
        QPixmap pixmap = QPixmap::fromImage(image);
        imageLabel->setPixmap(pixmap);
        imageLabel->show();
        //imageManipulator->resizeImage(0,scaleW);
        ui->resizeW->clear();
        ui->resizeH->clear();
        // refreshImage();
        }
    }
}

/* Blur image slot */
void MainWindow::blurImage(int kernelXY){
    if(ui->gaussianBox->isChecked()){
        gaussianBlurImage(kernelXY);
    } else {
        classicBlurImage(kernelXY);
    }
}

/* Set image to a blurred version using classic blur */
void MainWindow::classicBlurImage(int kernelXY, Point anchor /*= Point(-1,-1)*/, int borderType /*= 4*/)
{
    if(imageIsLoaded){
        showImage(imageManipulator->blurImage(kernelXY, anchor, borderType));
    }
}

/* Set image to a blurred version using gaussian blur */
void MainWindow::gaussianBlurImage(int kernelXY, double sigmaX /*= (0.0)*/, double sigmaY /*= (0.0)*/, int borderType /*= 4*/)
{
    if (imageIsLoaded && (kernelXY%2 != 0)) {
        showImage(imageManipulator->gaussianBlurImage(kernelXY, sigmaX, sigmaY, borderType));
    }
}

void MainWindow::rotateImageP90()
{
    if(imageIsLoaded){
        imageManipulator->rotateImage(90);
        refreshImage();
    }
}

void MainWindow::rotateImageM90()
{
    if(imageIsLoaded){
        imageManipulator->rotateImage(-90);
        refreshImage();
    }
}

void MainWindow::customRotate()
{
    if(imageIsLoaded){
        QString radiusStr = ui->customRotateInput->text();
        imageManipulator->rotateImage(radiusStr.toInt());
        ui->customRotateInput->clear();
        refreshImage();
    }
}

/* Contrast an Image */
void MainWindow::contrastImage(int beta /*= 0*/)
{
    if (imageIsLoaded) {
        showImage(imageManipulator->contrastImage(beta));
    }
}

/* Contrast an Image */
void MainWindow::brightenImage(int alpha /*= 0*/)
{
    if (imageIsLoaded) {
        showImage(imageManipulator->brightenImage(alpha/100));
    }
}



/* Resize an Image */
void MainWindow::resizeImage(int scale)
{
    double fxfy = scale / 100;
    double height = int(imageManipulator->getImage().size().height * scale / 100);
    showImage(imageManipulator->resizeImage(height, 1));
}

/* Crop an Image */
void MainWindow::cropImage()
{
    QString newWidth = ui->cropInputX->text();
    QString newHeight = ui->cropInputY->text();
    imageManipulator->cropImage(newHeight.toInt(), newWidth.toInt());
    refreshImage();
}

/* Dilate an Image */
void MainWindow::dilateImage(int dilation_size)
{
    //imageManipulator->dilateImage(dilation_elem, dilation_size);
    refreshImage();
}

/* Erode an Image */
void MainWindow::erodeImage(int erode_size)
{
    //imageManipulator->erodeImage(erosion_elem, erode_size);
    refreshImage();
}

/* Detect Edges */
void MainWindow::detectEdges()
{
    if (imageIsLoaded) {
        imageManipulator->generateCannyProperties();
        refreshImage();
    }
}

/* Create Panorama */
void MainWindow::createPanorama()
{
    /* Enabling file explorer features for directories only. */
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly, false);
    dialog.exec();

    // get selected folder
    QDir selected_folder = dialog.directory();
    QString selected_folder_path = selected_folder.absolutePath();
    string pathAsString = selected_folder_path.toStdString();

    /* Starting by stitching */
    imageManipulator->createOwnStitcher(pathAsString);

    /* If an image isnt loaded, it means that our above function will replace the current image with
     * the panorama result so we have to force refresh.
     */
    if (!imageIsLoaded) {
        refreshImage();
    }
}



