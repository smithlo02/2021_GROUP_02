/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFileOpen;
    QAction *actionFileSave;
    QAction *actionHelp;
    QAction *actionPrint;
    QAction *actionSphere_2;
    QAction *actionCube;
    QAction *actionCylinder_2;
    QAction *actionTetrahedron;
    QAction *actionDisk;
    QAction *actionLine;
    QAction *actionCone;
    QAction *actionPyramid;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QVTKOpenGLWidget *qvtkWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QPushButton *lightcolor;
    QPushButton *backgroundcolor;
    QPushButton *modelcolor;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *OSI;
    QLabel *label_16;
    QHBoxLayout *opacity;
    QLabel *label_7;
    QSpinBox *opacityspin;
    QSlider *opacityslider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QSpinBox *diffusespin;
    QSlider *diffuseslider;
    QHBoxLayout *specular;
    QLabel *label_8;
    QSpinBox *specularspin;
    QSlider *specularslider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QSpinBox *ambientspin;
    QSlider *ambientslider;
    QHBoxLayout *intensity;
    QLabel *label_9;
    QSpinBox *intensityspin;
    QSlider *intensityslider;
    QSpacerItem *horizontalSpacer_10;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_17;
    QVBoxLayout *LightFocalPosition;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QHBoxLayout *positionslider;
    QSlider *xslider;
    QSlider *yslider;
    QSlider *zslider;
    QHBoxLayout *spinbox;
    QSpinBox *xspin;
    QSpinBox *yspin;
    QSpinBox *zspin;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *curvatures;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *reflection;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *outline;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *smooth;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *clip;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *shrink;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_13;
    QLCDNumber *pieceslcd;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLCDNumber *cellslcd;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_15;
    QLCDNumber *pointslcd;
    QPushButton *get_statistics;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QRadioButton *wireframe;
    QRadioButton *solid;
    QRadioButton *vertices;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_8;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSource;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1452, 736);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionFileOpen = new QAction(MainWindow);
        actionFileOpen->setObjectName(QString::fromUtf8("actionFileOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileOpen->setIcon(icon);
        actionFileSave = new QAction(MainWindow);
        actionFileSave->setObjectName(QString::fromUtf8("actionFileSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFileSave->setIcon(icon1);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon3);
        actionSphere_2 = new QAction(MainWindow);
        actionSphere_2->setObjectName(QString::fromUtf8("actionSphere_2"));
        actionCube = new QAction(MainWindow);
        actionCube->setObjectName(QString::fromUtf8("actionCube"));
        actionCylinder_2 = new QAction(MainWindow);
        actionCylinder_2->setObjectName(QString::fromUtf8("actionCylinder_2"));
        actionTetrahedron = new QAction(MainWindow);
        actionTetrahedron->setObjectName(QString::fromUtf8("actionTetrahedron"));
        actionDisk = new QAction(MainWindow);
        actionDisk->setObjectName(QString::fromUtf8("actionDisk"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        actionCone = new QAction(MainWindow);
        actionCone->setObjectName(QString::fromUtf8("actionCone"));
        actionPyramid = new QAction(MainWindow);
        actionPyramid->setObjectName(QString::fromUtf8("actionPyramid"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        qvtkWidget = new QVTKOpenGLWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);
        qvtkWidget->setMinimumSize(QSize(600, 400));

        verticalLayout->addWidget(qvtkWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        verticalLayout_5->addWidget(label_12);

        lightcolor = new QPushButton(centralwidget);
        lightcolor->setObjectName(QString::fromUtf8("lightcolor"));
        lightcolor->setFlat(false);

        verticalLayout_5->addWidget(lightcolor);

        backgroundcolor = new QPushButton(centralwidget);
        backgroundcolor->setObjectName(QString::fromUtf8("backgroundcolor"));
        backgroundcolor->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(backgroundcolor);

        modelcolor = new QPushButton(centralwidget);
        modelcolor->setObjectName(QString::fromUtf8("modelcolor"));

        verticalLayout_5->addWidget(modelcolor);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        horizontalLayout->addLayout(verticalLayout_9);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        OSI = new QVBoxLayout();
        OSI->setObjectName(QString::fromUtf8("OSI"));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        OSI->addWidget(label_16);

        opacity = new QHBoxLayout();
        opacity->setObjectName(QString::fromUtf8("opacity"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        opacity->addWidget(label_7);

        opacityspin = new QSpinBox(centralwidget);
        opacityspin->setObjectName(QString::fromUtf8("opacityspin"));

        opacity->addWidget(opacityspin);

        opacityslider = new QSlider(centralwidget);
        opacityslider->setObjectName(QString::fromUtf8("opacityslider"));
        opacityslider->setMaximum(10);
        opacityslider->setOrientation(Qt::Horizontal);

        opacity->addWidget(opacityslider);


        OSI->addLayout(opacity);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        diffusespin = new QSpinBox(centralwidget);
        diffusespin->setObjectName(QString::fromUtf8("diffusespin"));

        horizontalLayout_3->addWidget(diffusespin);

        diffuseslider = new QSlider(centralwidget);
        diffuseslider->setObjectName(QString::fromUtf8("diffuseslider"));
        diffuseslider->setMaximum(10);
        diffuseslider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(diffuseslider);


        OSI->addLayout(horizontalLayout_3);

        specular = new QHBoxLayout();
        specular->setObjectName(QString::fromUtf8("specular"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        specular->addWidget(label_8);

        specularspin = new QSpinBox(centralwidget);
        specularspin->setObjectName(QString::fromUtf8("specularspin"));

        specular->addWidget(specularspin);

        specularslider = new QSlider(centralwidget);
        specularslider->setObjectName(QString::fromUtf8("specularslider"));
        specularslider->setMaximum(10);
        specularslider->setOrientation(Qt::Horizontal);

        specular->addWidget(specularslider);


        OSI->addLayout(specular);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        ambientspin = new QSpinBox(centralwidget);
        ambientspin->setObjectName(QString::fromUtf8("ambientspin"));

        horizontalLayout_2->addWidget(ambientspin);

        ambientslider = new QSlider(centralwidget);
        ambientslider->setObjectName(QString::fromUtf8("ambientslider"));
        ambientslider->setMaximum(10);
        ambientslider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(ambientslider);


        OSI->addLayout(horizontalLayout_2);

        intensity = new QHBoxLayout();
        intensity->setObjectName(QString::fromUtf8("intensity"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        intensity->addWidget(label_9);

        intensityspin = new QSpinBox(centralwidget);
        intensityspin->setObjectName(QString::fromUtf8("intensityspin"));

        intensity->addWidget(intensityspin);

        intensityslider = new QSlider(centralwidget);
        intensityslider->setObjectName(QString::fromUtf8("intensityslider"));
        intensityslider->setMaximum(128);
        intensityslider->setSingleStep(4);
        intensityslider->setOrientation(Qt::Horizontal);

        intensity->addWidget(intensityslider);


        OSI->addLayout(intensity);


        horizontalLayout->addLayout(OSI);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        verticalLayout_11->addWidget(label_17);

        LightFocalPosition = new QVBoxLayout();
        LightFocalPosition->setObjectName(QString::fromUtf8("LightFocalPosition"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_8->addWidget(label_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);


        LightFocalPosition->addLayout(horizontalLayout_8);

        positionslider = new QHBoxLayout();
        positionslider->setObjectName(QString::fromUtf8("positionslider"));
        xslider = new QSlider(centralwidget);
        xslider->setObjectName(QString::fromUtf8("xslider"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(xslider->sizePolicy().hasHeightForWidth());
        xslider->setSizePolicy(sizePolicy2);
        xslider->setMinimum(-10);
        xslider->setMaximum(10);
        xslider->setSingleStep(5);
        xslider->setOrientation(Qt::Vertical);

        positionslider->addWidget(xslider);

        yslider = new QSlider(centralwidget);
        yslider->setObjectName(QString::fromUtf8("yslider"));
        sizePolicy2.setHeightForWidth(yslider->sizePolicy().hasHeightForWidth());
        yslider->setSizePolicy(sizePolicy2);
        yslider->setMinimum(-10);
        yslider->setMaximum(10);
        yslider->setSingleStep(5);
        yslider->setOrientation(Qt::Vertical);

        positionslider->addWidget(yslider);

        zslider = new QSlider(centralwidget);
        zslider->setObjectName(QString::fromUtf8("zslider"));
        sizePolicy2.setHeightForWidth(zslider->sizePolicy().hasHeightForWidth());
        zslider->setSizePolicy(sizePolicy2);
        zslider->setMinimum(-10);
        zslider->setMaximum(10);
        zslider->setSingleStep(5);
        zslider->setOrientation(Qt::Vertical);

        positionslider->addWidget(zslider);


        LightFocalPosition->addLayout(positionslider);

        spinbox = new QHBoxLayout();
        spinbox->setObjectName(QString::fromUtf8("spinbox"));
        xspin = new QSpinBox(centralwidget);
        xspin->setObjectName(QString::fromUtf8("xspin"));

        spinbox->addWidget(xspin);

        yspin = new QSpinBox(centralwidget);
        yspin->setObjectName(QString::fromUtf8("yspin"));

        spinbox->addWidget(yspin);

        zspin = new QSpinBox(centralwidget);
        zspin->setObjectName(QString::fromUtf8("zspin"));

        spinbox->addWidget(zspin);


        LightFocalPosition->addLayout(spinbox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        LightFocalPosition->addItem(verticalSpacer_5);


        verticalLayout_11->addLayout(LightFocalPosition);


        horizontalLayout->addLayout(verticalLayout_11);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(label_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        curvatures = new QPushButton(centralwidget);
        curvatures->setObjectName(QString::fromUtf8("curvatures"));
        sizePolicy2.setHeightForWidth(curvatures->sizePolicy().hasHeightForWidth());
        curvatures->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(curvatures);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        reflection = new QPushButton(centralwidget);
        reflection->setObjectName(QString::fromUtf8("reflection"));
        sizePolicy2.setHeightForWidth(reflection->sizePolicy().hasHeightForWidth());
        reflection->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(reflection);


        verticalLayout_6->addLayout(horizontalLayout_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        outline = new QPushButton(centralwidget);
        outline->setObjectName(QString::fromUtf8("outline"));
        sizePolicy2.setHeightForWidth(outline->sizePolicy().hasHeightForWidth());
        outline->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(outline);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        smooth = new QPushButton(centralwidget);
        smooth->setObjectName(QString::fromUtf8("smooth"));
        sizePolicy2.setHeightForWidth(smooth->sizePolicy().hasHeightForWidth());
        smooth->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(smooth);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        clip = new QPushButton(centralwidget);
        clip->setObjectName(QString::fromUtf8("clip"));
        sizePolicy2.setHeightForWidth(clip->sizePolicy().hasHeightForWidth());
        clip->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(clip);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);

        shrink = new QPushButton(centralwidget);
        shrink->setObjectName(QString::fromUtf8("shrink"));
        sizePolicy2.setHeightForWidth(shrink->sizePolicy().hasHeightForWidth());
        shrink->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(shrink);


        verticalLayout_6->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_5->addWidget(label_13);

        pieceslcd = new QLCDNumber(centralwidget);
        pieceslcd->setObjectName(QString::fromUtf8("pieceslcd"));
        pieceslcd->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout_5->addWidget(pieceslcd);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_6->addWidget(label_14);

        cellslcd = new QLCDNumber(centralwidget);
        cellslcd->setObjectName(QString::fromUtf8("cellslcd"));

        horizontalLayout_6->addWidget(cellslcd);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_7->addWidget(label_15);

        pointslcd = new QLCDNumber(centralwidget);
        pointslcd->setObjectName(QString::fromUtf8("pointslcd"));

        horizontalLayout_7->addWidget(pointslcd);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_4);

        get_statistics = new QPushButton(centralwidget);
        get_statistics->setObjectName(QString::fromUtf8("get_statistics"));

        verticalLayout_3->addWidget(get_statistics);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(label_5);

        wireframe = new QRadioButton(centralwidget);
        wireframe->setObjectName(QString::fromUtf8("wireframe"));

        verticalLayout_2->addWidget(wireframe);

        solid = new QRadioButton(centralwidget);
        solid->setObjectName(QString::fromUtf8("solid"));

        verticalLayout_2->addWidget(solid);

        vertices = new QRadioButton(centralwidget);
        vertices->setObjectName(QString::fromUtf8("vertices"));

        verticalLayout_2->addWidget(vertices);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        horizontalLayout->addLayout(verticalLayout_8);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1452, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSource = new QMenu(menubar);
        menuSource->setObjectName(QString::fromUtf8("menuSource"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy3);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSource->menuAction());
        menuFile->addAction(actionFileOpen);
        menuFile->addAction(actionFileSave);
        menuSource->addAction(actionSphere_2);
        menuSource->addAction(actionCube);
        menuSource->addAction(actionCylinder_2);
        menuSource->addAction(actionTetrahedron);
        menuSource->addAction(actionDisk);
        menuSource->addAction(actionLine);
        menuSource->addAction(actionCone);
        menuSource->addAction(actionPyramid);
        toolBar->addAction(actionFileOpen);
        toolBar->addAction(actionFileSave);
        toolBar->addAction(actionHelp);
        toolBar->addAction(actionPrint);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFileOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionFileSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        actionSphere_2->setText(QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        actionCube->setText(QCoreApplication::translate("MainWindow", "Cube", nullptr));
        actionCylinder_2->setText(QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        actionTetrahedron->setText(QCoreApplication::translate("MainWindow", "Tetrahedron", nullptr));
        actionDisk->setText(QCoreApplication::translate("MainWindow", "Disk", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        actionCone->setText(QCoreApplication::translate("MainWindow", "Cone", nullptr));
        actionPyramid->setText(QCoreApplication::translate("MainWindow", "Pyramid", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Change color:", nullptr));
        lightcolor->setText(QCoreApplication::translate("MainWindow", "light color", nullptr));
        backgroundcolor->setText(QCoreApplication::translate("MainWindow", "background color", nullptr));
        modelcolor->setText(QCoreApplication::translate("MainWindow", "model color", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Visual effect:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "opacity", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "diffuse", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "specular", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ambient", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "specularpower", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "LightFocal:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Filter:", nullptr));
        curvatures->setText(QCoreApplication::translate("MainWindow", "Curvatures", nullptr));
        reflection->setText(QCoreApplication::translate("MainWindow", "Reflection", nullptr));
        outline->setText(QCoreApplication::translate("MainWindow", "OutLine   ", nullptr));
        smooth->setText(QCoreApplication::translate("MainWindow", "Smooth    ", nullptr));
        clip->setText(QCoreApplication::translate("MainWindow", "Clip      ", nullptr));
        shrink->setText(QCoreApplication::translate("MainWindow", "Shrink    ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Statistics:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Pieces", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Cells ", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Points", nullptr));
        get_statistics->setText(QCoreApplication::translate("MainWindow", "getData", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Modes:", nullptr));
        wireframe->setText(QCoreApplication::translate("MainWindow", "wireframe", nullptr));
        solid->setText(QCoreApplication::translate("MainWindow", "solid", nullptr));
        vertices->setText(QCoreApplication::translate("MainWindow", "vertices", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSource->setTitle(QCoreApplication::translate("MainWindow", "Source", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
