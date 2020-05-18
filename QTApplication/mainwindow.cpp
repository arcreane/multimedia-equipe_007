#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qscreen.h"
#include "qfiledialog.h"

#include <opencv2/opencv.hpp>

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    // get filename
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg)"));
    if (!fileName.data()){
        // convert it into char*
        QByteArray conversion = fileName.toLocal8Bit();
        char *c_fileName = conversion.data();
        Mat image = imread(c_fileName);
        imshow("Display", image);
    }
}
