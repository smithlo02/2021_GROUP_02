#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vtkSTLReader.h"
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkLight.h>
#include<vtkProperty.h>
#include<ModelRender.h>
#include<filter.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void signal_loadStl(QString path);

public slots:

    void readSTL();


/************** color parts*********************************/
    void setBackgndColor();
    void setModelColor();

/************** light parts*********************************/
    void setLightColor();
    void setOpacity();
    void setAmbient();
    void setDiffuse();
    void setSpecular();
    void setSpecularPower();
    void setFocalPosition();
    void setWireframe();
    void setSolid();
    void setVertices();
    void showStatistics();
/********Filter Parts**********************************/
    void LaunchOutLineFilter();
    void LaunchClipFilter();
    void LaunchShrinkFilter();
    void LaunchSmoothFilter();
    void LaunchReflectFilter();
    void LaunchCurveFilter();
   // void resetFunc();
/***************Menu bar source*************************/

    void DrawCube();
    void DrawCylinder();
    void DrawSphere();
    void DrawDisk();
    void DrawLine();
    void DrawCone();
    void DrawTetra();
    void DrawPyramid();

private:

    Ui::MainWindow *ui;

    ModelRender* Model = new ModelRender();
    filter * vtkFilter = new filter();

    void UiSetup();//set up ui
    void InitOpenGLWindow();//initialize opengl window

    /*connection between signals and slots of light parts
     *contain: light-bkgnd-model color, capacity,light focal position, light factors.
     */
    void lightFunctionConnect();

    /*connection between signals and slots of light parts
     *contain: solid wireframe vertices and statistics
     */
    void strucFunctionConnect();

    /*connection between signals and slots of structure display
     *contain: filters and reset function
     */
    void filterFunctionConnect();

    /*connection between signals and slots of the menu Bar
     *contain: cube sphere..., openfunctions
     */
    void menuBarSourceConnect();
};
#endif // MAINWINDOW_H
