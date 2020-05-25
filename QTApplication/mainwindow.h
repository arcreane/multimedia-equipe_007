#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;
    QLabel *imageLabel;

};

#endif // MAINWINDOW_H
