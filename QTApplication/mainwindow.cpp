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

    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showImage(Mat mat)
{
    //transform matrice into a qimage
    cvtColor(mat, mat, CV_BGR2RGB);
    QImage image(mat.data, mat.cols, mat.rows, QImage::Format_RGB888);
    //transform qimage into a pixmap
    QPixmap pixmap = QPixmap::fromImage(image);
    imageLabel->setPixmap(pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio));
    imageLabel->show();

}

void MainWindow::open()
{

    // get filename
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg)"));

    // convert it into char*
    QByteArray conversion = fileName.toLocal8Bit();
    char *c_fileName = conversion.data();

    Mat mat = imread(c_fileName);
    showImage(mat);

}




