/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionLanguage;
    QAction *actionAbout;
    QAction *actionToGrey;
    QAction *actionReset;
    QAction *actionDetectEdges;
    QAction *actionPanorama;
    QAction *actionBlur;
    QWidget *centralwidget;
    QWidget *imageWidget;
    QWidget *containerWidget;
    QWidget *contrastWidget;
    QLabel *label_3;
    QSlider *slider_contrast;
    QLabel *label_4;
    QSlider *slider_brightness;
    QWidget *blurWidget;
    QLabel *label;
    QSlider *slider_blur;
    QCheckBox *gaussianBox;
    QWidget *rotationWidget;
    QPushButton *buttonRotateM90;
    QPushButton *buttonRotateP90;
    QPushButton *customRotate;
    QLabel *labelRotate;
    QLineEdit *customRotateInput;
    QWidget *widget;
    QLabel *labelResize;
    QLabel *labelCrop;
    QPushButton *cropButton;
    QLineEdit *cropInputX;
    QLineEdit *cropInputY;
    QLineEdit *resizeW;
    QPushButton *resizeButton;
    QLineEdit *resizeH;
    QWidget *contrastWidget_2;
    QLabel *erosionLabel;
    QSlider *erosionBar;
    QRadioButton *erosionRadio1;
    QRadioButton *erosionRadio0;
    QRadioButton *erosionRadio2;
    QWidget *contrastWidget_3;
    QLabel *dilationLabel;
    QSlider *dilationBar;
    QRadioButton *dilationRadio1;
    QRadioButton *dilationRadio0;
    QRadioButton *dilationRadio2;
    QMenuBar *menubar;
    QMenu *menuFiles;
    QMenu *menuSettings;
    QMenu *menuAbout;
    QMenu *menuImages;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(804, 597);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLanguage = new QAction(MainWindow);
        actionLanguage->setObjectName(QString::fromUtf8("actionLanguage"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionToGrey = new QAction(MainWindow);
        actionToGrey->setObjectName(QString::fromUtf8("actionToGrey"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionDetectEdges = new QAction(MainWindow);
        actionDetectEdges->setObjectName(QString::fromUtf8("actionDetectEdges"));
        actionPanorama = new QAction(MainWindow);
        actionPanorama->setObjectName(QString::fromUtf8("actionPanorama"));
        actionBlur = new QAction(MainWindow);
        actionBlur->setObjectName(QString::fromUtf8("actionBlur"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        imageWidget = new QWidget(centralwidget);
        imageWidget->setObjectName(QString::fromUtf8("imageWidget"));
        imageWidget->setGeometry(QRect(10, 10, 441, 541));
        containerWidget = new QWidget(centralwidget);
        containerWidget->setObjectName(QString::fromUtf8("containerWidget"));
        containerWidget->setGeometry(QRect(470, 10, 211, 541));
        contrastWidget = new QWidget(containerWidget);
        contrastWidget->setObjectName(QString::fromUtf8("contrastWidget"));
        contrastWidget->setGeometry(QRect(0, 80, 201, 101));
        label_3 = new QLabel(contrastWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 181, 17));
        slider_contrast = new QSlider(contrastWidget);
        slider_contrast->setObjectName(QString::fromUtf8("slider_contrast"));
        slider_contrast->setGeometry(QRect(10, 30, 171, 21));
        slider_contrast->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(contrastWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 181, 17));
        slider_brightness = new QSlider(contrastWidget);
        slider_brightness->setObjectName(QString::fromUtf8("slider_brightness"));
        slider_brightness->setGeometry(QRect(10, 80, 171, 21));
        slider_brightness->setOrientation(Qt::Horizontal);
        blurWidget = new QWidget(containerWidget);
        blurWidget->setObjectName(QString::fromUtf8("blurWidget"));
        blurWidget->setGeometry(QRect(0, 0, 201, 71));
        label = new QLabel(blurWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 181, 17));
        slider_blur = new QSlider(blurWidget);
        slider_blur->setObjectName(QString::fromUtf8("slider_blur"));
        slider_blur->setGeometry(QRect(10, 50, 171, 21));
        slider_blur->setOrientation(Qt::Horizontal);
        gaussianBox = new QCheckBox(blurWidget);
        gaussianBox->setObjectName(QString::fromUtf8("gaussianBox"));
        gaussianBox->setGeometry(QRect(10, 0, 92, 23));
        rotationWidget = new QWidget(containerWidget);
        rotationWidget->setObjectName(QString::fromUtf8("rotationWidget"));
        rotationWidget->setGeometry(QRect(0, 350, 201, 91));
        buttonRotateM90 = new QPushButton(rotationWidget);
        buttonRotateM90->setObjectName(QString::fromUtf8("buttonRotateM90"));
        buttonRotateM90->setGeometry(QRect(110, 10, 89, 25));
        buttonRotateP90 = new QPushButton(rotationWidget);
        buttonRotateP90->setObjectName(QString::fromUtf8("buttonRotateP90"));
        buttonRotateP90->setGeometry(QRect(0, 10, 89, 25));
        customRotate = new QPushButton(rotationWidget);
        customRotate->setObjectName(QString::fromUtf8("customRotate"));
        customRotate->setGeometry(QRect(130, 60, 61, 25));
        labelRotate = new QLabel(rotationWidget);
        labelRotate->setObjectName(QString::fromUtf8("labelRotate"));
        labelRotate->setGeometry(QRect(10, 40, 181, 17));
        customRotateInput = new QLineEdit(rotationWidget);
        customRotateInput->setObjectName(QString::fromUtf8("customRotateInput"));
        customRotateInput->setGeometry(QRect(10, 60, 113, 25));
        widget = new QWidget(containerWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 440, 201, 101));
        labelResize = new QLabel(widget);
        labelResize->setObjectName(QString::fromUtf8("labelResize"));
        labelResize->setGeometry(QRect(10, 0, 181, 17));
        labelCrop = new QLabel(widget);
        labelCrop->setObjectName(QString::fromUtf8("labelCrop"));
        labelCrop->setGeometry(QRect(10, 50, 181, 17));
        cropButton = new QPushButton(widget);
        cropButton->setObjectName(QString::fromUtf8("cropButton"));
        cropButton->setGeometry(QRect(130, 70, 61, 25));
        cropInputX = new QLineEdit(widget);
        cropInputX->setObjectName(QString::fromUtf8("cropInputX"));
        cropInputX->setGeometry(QRect(10, 70, 51, 25));
        cropInputY = new QLineEdit(widget);
        cropInputY->setObjectName(QString::fromUtf8("cropInputY"));
        cropInputY->setGeometry(QRect(70, 70, 51, 25));
        resizeW = new QLineEdit(widget);
        resizeW->setObjectName(QString::fromUtf8("resizeW"));
        resizeW->setGeometry(QRect(10, 20, 51, 25));
        resizeButton = new QPushButton(widget);
        resizeButton->setObjectName(QString::fromUtf8("resizeButton"));
        resizeButton->setGeometry(QRect(130, 20, 61, 25));
        resizeH = new QLineEdit(widget);
        resizeH->setObjectName(QString::fromUtf8("resizeH"));
        resizeH->setGeometry(QRect(70, 20, 51, 25));
        contrastWidget_2 = new QWidget(containerWidget);
        contrastWidget_2->setObjectName(QString::fromUtf8("contrastWidget_2"));
        contrastWidget_2->setGeometry(QRect(0, 190, 201, 71));
        erosionLabel = new QLabel(contrastWidget_2);
        erosionLabel->setObjectName(QString::fromUtf8("erosionLabel"));
        erosionLabel->setGeometry(QRect(10, 10, 181, 17));
        erosionBar = new QSlider(contrastWidget_2);
        erosionBar->setObjectName(QString::fromUtf8("erosionBar"));
        erosionBar->setGeometry(QRect(10, 50, 171, 21));
        erosionBar->setOrientation(Qt::Horizontal);
        erosionRadio1 = new QRadioButton(contrastWidget_2);
        erosionRadio1->setObjectName(QString::fromUtf8("erosionRadio1"));
        erosionRadio1->setGeometry(QRect(70, 30, 61, 23));
        erosionRadio0 = new QRadioButton(contrastWidget_2);
        erosionRadio0->setObjectName(QString::fromUtf8("erosionRadio0"));
        erosionRadio0->setGeometry(QRect(10, 30, 61, 23));
        erosionRadio2 = new QRadioButton(contrastWidget_2);
        erosionRadio2->setObjectName(QString::fromUtf8("erosionRadio2"));
        erosionRadio2->setGeometry(QRect(130, 30, 71, 23));
        contrastWidget_3 = new QWidget(containerWidget);
        contrastWidget_3->setObjectName(QString::fromUtf8("contrastWidget_3"));
        contrastWidget_3->setGeometry(QRect(0, 270, 201, 71));
        dilationLabel = new QLabel(contrastWidget_3);
        dilationLabel->setObjectName(QString::fromUtf8("dilationLabel"));
        dilationLabel->setGeometry(QRect(10, 10, 181, 17));
        dilationBar = new QSlider(contrastWidget_3);
        dilationBar->setObjectName(QString::fromUtf8("dilationBar"));
        dilationBar->setGeometry(QRect(10, 50, 171, 21));
        dilationBar->setOrientation(Qt::Horizontal);
        dilationRadio1 = new QRadioButton(contrastWidget_3);
        dilationRadio1->setObjectName(QString::fromUtf8("dilationRadio1"));
        dilationRadio1->setGeometry(QRect(70, 30, 61, 23));
        dilationRadio0 = new QRadioButton(contrastWidget_3);
        dilationRadio0->setObjectName(QString::fromUtf8("dilationRadio0"));
        dilationRadio0->setGeometry(QRect(10, 30, 61, 23));
        dilationRadio2 = new QRadioButton(contrastWidget_3);
        dilationRadio2->setObjectName(QString::fromUtf8("dilationRadio2"));
        dilationRadio2->setGeometry(QRect(130, 30, 71, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 804, 22));
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuImages = new QMenu(menubar);
        menuImages->setObjectName(QString::fromUtf8("menuImages"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::RightToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuImages->menuAction());
        menuFiles->addAction(actionOpen);
        menuFiles->addAction(actionSave);
        menuSettings->addAction(actionLanguage);
        menuAbout->addAction(actionAbout);
        menuImages->addAction(actionReset);
        menuImages->addSeparator();
        menuImages->addAction(actionToGrey);
        menuImages->addAction(actionDetectEdges);
        menuImages->addSeparator();
        menuImages->addAction(actionPanorama);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionReset);
        toolBar->addSeparator();
        toolBar->addAction(actionToGrey);
        toolBar->addAction(actionDetectEdges);
        toolBar->addSeparator();
        toolBar->addAction(actionPanorama);

        retranslateUi(MainWindow);
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(open()));
        QObject::connect(actionToGrey, SIGNAL(triggered()), MainWindow, SLOT(imageToGrey()));
        QObject::connect(actionReset, SIGNAL(triggered()), MainWindow, SLOT(reset()));
        QObject::connect(actionDetectEdges, SIGNAL(triggered()), MainWindow, SLOT(detectEdges()));
        QObject::connect(actionPanorama, SIGNAL(triggered()), MainWindow, SLOT(createPanorama()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open Image", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionLanguage->setText(QCoreApplication::translate("MainWindow", "Language", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionToGrey->setText(QCoreApplication::translate("MainWindow", "To grey", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionDetectEdges->setText(QCoreApplication::translate("MainWindow", "Edge Detection", nullptr));
        actionPanorama->setText(QCoreApplication::translate("MainWindow", "Panorama", nullptr));
#if QT_CONFIG(tooltip)
        actionPanorama->setToolTip(QCoreApplication::translate("MainWindow", "Open the assets folder", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBlur->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Kernel size for blurring", nullptr));
        gaussianBox->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
        buttonRotateM90->setText(QCoreApplication::translate("MainWindow", "Rotate - 90\302\260", nullptr));
        buttonRotateP90->setText(QCoreApplication::translate("MainWindow", "Rotate + 90\302\260", nullptr));
        customRotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        labelRotate->setText(QCoreApplication::translate("MainWindow", "Custom rotation", nullptr));
        labelResize->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        labelCrop->setText(QCoreApplication::translate("MainWindow", "Crop inputs", nullptr));
        cropButton->setText(QCoreApplication::translate("MainWindow", "Crop", nullptr));
        resizeButton->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        erosionLabel->setText(QCoreApplication::translate("MainWindow", "Erosion", nullptr));
        erosionRadio1->setText(QCoreApplication::translate("MainWindow", "Cross", nullptr));
        erosionRadio0->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
        erosionRadio2->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        dilationLabel->setText(QCoreApplication::translate("MainWindow", "Dilation", nullptr));
        dilationRadio1->setText(QCoreApplication::translate("MainWindow", "Cross", nullptr));
        dilationRadio0->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
        dilationRadio2->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuImages->setTitle(QCoreApplication::translate("MainWindow", "Images", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
