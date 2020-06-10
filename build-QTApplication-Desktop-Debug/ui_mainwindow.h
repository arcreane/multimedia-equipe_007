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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QAction *actionChangeColor;
    QAction *actionReset;
    QAction *actionUndo;
    QAction *actionRedo;
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
    QSlider *slider;
    QCheckBox *gaussianBox;
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
        actionChangeColor = new QAction(MainWindow);
        actionChangeColor->setObjectName(QString::fromUtf8("actionChangeColor"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
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
        imageWidget->setGeometry(QRect(10, 10, 441, 471));
        containerWidget = new QWidget(centralwidget);
        containerWidget->setObjectName(QString::fromUtf8("containerWidget"));
        containerWidget->setGeometry(QRect(470, 10, 211, 471));
        contrastWidget = new QWidget(containerWidget);
        contrastWidget->setObjectName(QString::fromUtf8("contrastWidget"));
        contrastWidget->setGeometry(QRect(10, 240, 191, 141));
        label_3 = new QLabel(contrastWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 181, 17));
        slider_contrast = new QSlider(contrastWidget);
        slider_contrast->setObjectName(QString::fromUtf8("slider_contrast"));
        slider_contrast->setGeometry(QRect(10, 50, 171, 21));
        slider_contrast->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(contrastWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 181, 17));
        slider_brightness = new QSlider(contrastWidget);
        slider_brightness->setObjectName(QString::fromUtf8("slider_brightness"));
        slider_brightness->setGeometry(QRect(10, 110, 171, 21));
        slider_brightness->setOrientation(Qt::Horizontal);
        blurWidget = new QWidget(containerWidget);
        blurWidget->setObjectName(QString::fromUtf8("blurWidget"));
        blurWidget->setGeometry(QRect(10, 80, 191, 141));
        label = new QLabel(blurWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 181, 17));
        slider = new QSlider(blurWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(10, 70, 171, 21));
        slider->setOrientation(Qt::Horizontal);
        gaussianBox = new QCheckBox(blurWidget);
        gaussianBox->setObjectName(QString::fromUtf8("gaussianBox"));
        gaussianBox->setGeometry(QRect(10, 0, 92, 23));
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
        menuFiles->addSeparator();
        menuFiles->addAction(actionSave);
        menuSettings->addAction(actionLanguage);
        menuAbout->addAction(actionAbout);
        menuImages->addAction(actionChangeColor);
        menuImages->addAction(actionDetectEdges);
        menuImages->addAction(actionReset);
        menuImages->addAction(actionUndo);
        menuImages->addAction(actionRedo);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionReset);
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionPanorama);

        retranslateUi(MainWindow);
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(open()));
        QObject::connect(actionChangeColor, SIGNAL(triggered()), MainWindow, SLOT(imageToGrey()));
        QObject::connect(actionReset, SIGNAL(triggered()), MainWindow, SLOT(reset()));
        QObject::connect(actionUndo, SIGNAL(triggered()), MainWindow, SLOT(undo()));
        QObject::connect(actionRedo, SIGNAL(triggered()), MainWindow, SLOT(redo()));
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
        actionChangeColor->setText(QCoreApplication::translate("MainWindow", "To grey", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionDetectEdges->setText(QCoreApplication::translate("MainWindow", "Edge Detection", nullptr));
        actionPanorama->setText(QCoreApplication::translate("MainWindow", "Panorama", nullptr));
#if QT_CONFIG(tooltip)
        actionPanorama->setToolTip(QCoreApplication::translate("MainWindow", "Open the assets folder", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBlur->setText(QCoreApplication::translate("MainWindow", "Blur", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "brightness", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "kernel size for blurring", nullptr));
        gaussianBox->setText(QCoreApplication::translate("MainWindow", "Gaussian", nullptr));
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
