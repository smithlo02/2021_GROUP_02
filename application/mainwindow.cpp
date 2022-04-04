#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include "vtkSTLReader.h"
#include <vtkSTLWriter.h>
#include "vtkPolyDataMapper.h"

#include "vtkClipPolyData.h"
#include <vtkLight.h>

//QT
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QString>
#include <QColorDialog>
#include<QDebug>
#include<QMessageBox>
#include <QPalette>
#include <typeinfo>
#include<QRadioButton>
#include<QLineEdit>
#include<QLine>
#include<ModelRender.h>

//QColor blue;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

   this->UiSetup();
   this->InitOpenGLWindow();
   this->lightFunctionConnect();
   this->strucFunctionConnect();
   this->filterFunctionConnect();
   this->menuBarSourceConnect();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UiSetup(){
    ui->setupUi(this);
    this->setWindowTitle("Group_02 project");

}

void MainWindow::InitOpenGLWindow(){

    ui->qvtkWidget->SetRenderWindow(Model->getRenderWindow());
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(Model->getRenderer());

}
void MainWindow::lightFunctionConnect(){
    //open STL files
    connect(ui->actionFileOpen, &QAction::triggered, this, &MainWindow::readSTL);

    //change bkgnd color
    connect(ui->backgroundcolor,&QPushButton::clicked,this,&MainWindow::setBackgndColor);
    //change model color
    connect(ui->modelcolor,&QPushButton::clicked,this,&MainWindow::setModelColor);
    //change light color
    connect(ui->lightcolor,&QPushButton::clicked,this,&MainWindow::setLightColor);

    //change opacity
    connect(ui->opacityslider, SIGNAL(valueChanged(int)), ui->opacityspin, SLOT(setValue(int)));
    connect(ui->opacityspin, SIGNAL(valueChanged(int)), ui->opacityslider, SLOT(setValue(int)));
    connect(ui->opacityslider, SIGNAL(valueChanged(int)), this, SLOT(setOpacity()));

    //change specular
    connect(ui->specularslider, SIGNAL(valueChanged(int)), ui->specularspin, SLOT(setValue(int)));
    connect(ui->specularslider, SIGNAL(valueChanged(int)), this, SLOT(setSpecular()));
    connect(ui->specularspin, SIGNAL(valueChanged(int)), ui->specularslider, SLOT(setValue(int)));

    //change specular power
    connect(ui->intensityslider, SIGNAL(valueChanged(int)), ui->intensityspin, SLOT(setValue(int)));
    connect(ui->intensityslider, SIGNAL(valueChanged(int)), this, SLOT(setSpecularPower()));
    connect(ui->intensityspin, SIGNAL(valueChanged(int)), ui->intensityslider, SLOT(setValue(int)));

    //change ambient
    connect(ui->ambientslider, SIGNAL(valueChanged(int)), ui->ambientspin, SLOT(setValue(int)));
    connect(ui->ambientslider, SIGNAL(valueChanged(int)), this, SLOT(setAmbient()));
    connect(ui->ambientspin, SIGNAL(valueChanged(int)), ui->ambientslider, SLOT(setValue(int)));

    //change diffuse
    connect(ui->diffuseslider, SIGNAL(valueChanged(int)), ui->diffusespin, SLOT(setValue(int)));
    connect(ui->diffuseslider, SIGNAL(valueChanged(int)), this, SLOT(setDiffuse()));
    connect(ui->diffusespin, SIGNAL(valueChanged(int)), ui->diffuseslider, SLOT(setValue(int)));

    // change focal position
    connect(ui->xslider, SIGNAL(valueChanged(int)), ui->xspin, SLOT(setValue(int)));
    connect(ui->xslider, SIGNAL(valueChanged(int)), this, SLOT(setFocalPosition()));
    connect(ui->xspin, SIGNAL(valueChanged(int)), ui->xslider, SLOT(setValue(int)));

    connect(ui->yslider, SIGNAL(valueChanged(int)), ui->yspin, SLOT(setValue(int)));
    connect(ui->yslider, SIGNAL(valueChanged(int)), this, SLOT(setFocalPosition()));
    connect(ui->yspin, SIGNAL(valueChanged(int)), ui->yslider, SLOT(setValue(int)));

    connect(ui->zslider, SIGNAL(valueChanged(int)), ui->zspin, SLOT(setValue(int)));
    connect(ui->zslider, SIGNAL(valueChanged(int)), this, SLOT(setFocalPosition()));
    connect(ui->zspin, SIGNAL(valueChanged(int)), ui->zslider, SLOT(setValue(int)));
}

void MainWindow::strucFunctionConnect(){
   //display in wireframe
    connect(ui->wireframe,&QRadioButton::toggled,this,&MainWindow::setWireframe);
   //display in solid
    connect(ui->solid,&QRadioButton::toggled,this,&MainWindow::setSolid);
   //display in vertices
    connect(ui->vertices,&QRadioButton::toggled,this,&MainWindow::setVertices);
   //get the cells pieces points statistics
    connect(ui->get_statistics,&QPushButton::clicked,this,&MainWindow::showStatistics);

}
/*
 * filter signals and slots connections
 */
void MainWindow::filterFunctionConnect(){

    connect(ui->outline,&QPushButton::clicked,this,&MainWindow::LaunchOutLineFilter);
    connect(ui->shrink,&QPushButton::clicked,this,&MainWindow::LaunchShrinkFilter);
    connect(ui->clip,&QPushButton::clicked,this,&MainWindow::LaunchClipFilter);
    connect(ui->smooth,&QPushButton::clicked,this,&MainWindow::LaunchSmoothFilter);
    connect(ui->reflection,&QPushButton::clicked,this,&MainWindow::LaunchReflectFilter);
    connect(ui->curvatures,&QPushButton::clicked,this,&MainWindow::LaunchCurveFilter);
    //connect(ui->reset,&QPushButton::clicked,this,&MainWindow::resetFunc);
}
/*
 * menu bar signals and slots connections
 */
void MainWindow::menuBarSourceConnect(){

    connect(ui->actionCube,&QAction::triggered,this,&MainWindow::DrawCube);
    connect(ui->actionSphere_2,&QAction::triggered,this,&MainWindow::DrawSphere);
    connect(ui->actionCone,&QAction::triggered,this,&MainWindow::DrawCone);
    connect(ui->actionDisk,&QAction::triggered,this,&MainWindow::DrawDisk);
    connect(ui->actionLine,&QAction::triggered,this,&MainWindow::DrawLine);
    connect(ui->actionCylinder_2,&QAction::triggered,this,&MainWindow::DrawCylinder);
    connect(ui->actionTetrahedron,&QAction::triggered,this,&MainWindow::DrawTetra);
    connect(ui->actionPyramid,&QAction::triggered,this,&MainWindow::DrawPyramid);

}

/*
 * read stl file
 */
void MainWindow::readSTL()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open STL File"), "./", tr("STL Files(*.stl)"));
    Model->STLfileReader(file);
    Model->setPipeline();

}

//set background color
void MainWindow::setBackgndColor(){
    QColor color = QColorDialog::getColor(Qt::white, this, "Change background color",QColorDialog::ShowAlphaChannel);
            if (color.isValid())
            {
                double R, G, B;
                double red = color.red();
                double blue = color.blue();
                double green = color.green();
                R = (red / 255);
                G = (green / 255);
                B = (blue / 255);
                Model->getRenderer()->SetBackground(R,G,B);
                Model->getRenderer()->GetRenderWindow()->Render();
            }
}

//set model color
void MainWindow::setModelColor(){
    QColor color = QColorDialog::getColor(Qt::white, this, "Change model color");
        if (color.isValid())
        {
            double R, G, B;
            double red = color.red();
            double blue = color.blue();
            double green = color.green();
            R = (red / 255);
            G = (green / 255);
            B = (blue / 255);
            Model->getActor()->GetProperty()->SetColor(R,G,B);
            Model->getRenderer()->GetRenderWindow()->Render();
         }
}

//set Light color
void MainWindow::setLightColor(){
    QColor color = QColorDialog::getColor(Qt::white, this, "Change model color");
        if (color.isValid())
        {
            double R, G, B;
            double red = color.red();
            double blue = color.blue();
            double green = color.green();
            R = (red / 255);
            G = (green / 255);
            B = (blue / 255);
            Model->getLight()->SetColor(R,G,B);
            Model->getRenderer()->GetRenderWindow()->Render();
        }
}

//set opacity
void MainWindow::setOpacity() {
    qDebug() <<"opacity:"<<ui->opacityslider->value();
    double slidervalue = ui->opacityslider->value();
    double opacity =  slidervalue / 10;
    Model->getProp()->SetOpacity(opacity);
    Model->getRenderer()->GetRenderWindow()->Render();
}

// set specular
void MainWindow::setSpecular()
{
    qDebug() << "specular:"<<ui->specularslider->value();

    double slidervalue = ui->specularslider->value();
    double specular = slidervalue / 10;

    Model->getProp()->SetSpecular(specular);
     Model->getRenderer()->GetRenderWindow()->Render();
}

// set specular power
void MainWindow::setSpecularPower()
{
    qDebug() <<"specular power:"<< ui->intensityslider->value();

    double specularPower = ui->intensityslider->value();
     Model->getProp()->SetSpecularPower(specularPower);
     Model->getRenderer()->GetRenderWindow()->Render();
}

//set diffuse
void MainWindow::setDiffuse() {
    qDebug() << "diffuse:" << ui->diffuseslider->value();

    double slidervalue = ui->diffuseslider->value();
    double diffuse = slidervalue / 10;

     Model->getProp()->SetDiffuse(diffuse);
     Model->getRenderer()->GetRenderWindow()->Render();
}

//set ambient
void MainWindow::setAmbient() {
    qDebug() << "ambient:" << ui->ambientslider->value();

    double slidervalue = ui->ambientslider->value();
    double ambient = slidervalue / 10;

     Model->getProp()->SetAmbient(ambient);
     Model->getRenderer()->GetRenderWindow()->Render();
}

//set focal point
void MainWindow::setFocalPosition()
{
    qDebug() << "x:" << ui->xslider->value();
    qDebug()<<"y:"<< ui->yslider->value();
    qDebug() << "z:" << ui->zslider->value();
    double xslidervalue = ui->xslider->value();
    double yslidervalue = ui->yslider->value();
    double zslidervalue = ui->zslider->value();

    double x = xslidervalue / 10;
    double y = yslidervalue / 10;
    double z = zslidervalue / 10;
    Model->getLight()->SetPosition(x, y, z);
    Model->getRenderer()->GetRenderWindow()->Render();

}
// display in wireframe
void MainWindow::setWireframe(){

    Model->getProp()->SetRepresentationToWireframe();
    Model->getRenderer()->GetRenderWindow()->Render();
}

// display in solid
void MainWindow::setSolid(){

    Model->getProp()->SetRepresentationToSurface();
    Model->getRenderer()->GetRenderWindow()->Render();

}

// display in vertices
void MainWindow::setVertices(){
    Model->getProp()->SetRepresentationToPoints();
    Model->getRenderer()->GetRenderWindow()->Render();
}

// show statistics
void MainWindow::showStatistics(){

   int cells, pieces,points;

   ui->cellslcd->setMode(QLCDNumber::Dec);
   ui->pieceslcd->setMode(QLCDNumber::Dec);
   ui->pieceslcd->setMode(QLCDNumber::Dec);

   cells = Model->getPolyData()->GetNumberOfCells();
   pieces = Model->getPolyData()->GetNumberOfPieces();
   points = Model->getPolyData()->GetNumberOfPoints();

   ui->pointslcd->display(points);
   ui->cellslcd->display(cells);
   ui->pieceslcd->display(pieces);

}
/***********************filter parts****************************************/
void MainWindow::LaunchOutLineFilter(){
   vtkFilter->outLineFilter(Model);
}

void MainWindow::LaunchClipFilter(){

    vtkFilter->clipFilter(Model);

}


void MainWindow::LaunchShrinkFilter(){

    vtkFilter->shrinkFilter(Model);

}

void MainWindow::LaunchReflectFilter(){
   vtkFilter->reflectFilter(Model);

}

void MainWindow::LaunchSmoothFilter(){
    vtkFilter->smoothFilter(Model);

}

void MainWindow::LaunchCurveFilter(){
    vtkFilter->curvatureFilter(Model);
}

//void MainWindow::resetFunc(){
//    qDebug()<<"hello";
//    vtkFilter->resetFilter(Model);
//}

/**********************Source parts*********************************/
void MainWindow::DrawCube(){
    Model->buildCube();
}

void MainWindow::DrawCone(){
    Model->buildCone();
}

void MainWindow::DrawSphere(){
    Model->buildSphere();
}

void MainWindow::DrawCylinder(){
    Model->buildCylinder();
}

void MainWindow::DrawTetra(){
    Model->buildTera();

}

void MainWindow::DrawPyramid(){
    Model->buildPyramid();


}

void MainWindow::DrawLine(){
    Model->buildLine();
}

void MainWindow::DrawDisk(){
    Model->buildDisk();
}

