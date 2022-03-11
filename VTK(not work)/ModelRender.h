#pragma once

//QT lib
#include<qobject.h>
#include<qdebug.h>
#include<QString>
#include<QFileDialog>
#include<QColor>
#include<QColorDialog>

//vtk lib

#include<vtkSTLReader.h>
#include<vtkCamera.h>
#include<vtkPolyData.h>
#include<vtkRenderer.h>
#include<vtkPolyDataMapper.h>
#include<vtkNamedColors.h>

#include<vtkCubeSource.h>
#include<vtkSphereSource.h>
#include<vtkCylinderSource.h>
#include<vtkDiskSource.h>
#include<vtkLineSource.h>
#include<vtkPyramid.h>
#include<vtkTetra.h>
#include<vtkConeSource.h>


#include <vtkLight.h>
#include<vtkProperty.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkSTLWriter.h>
#include <vtkNew.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkCellType.h>
#include<vtkCellArray.h>
#include<vtkDataSetSurfaceFilter.h>



using namespace std;

class ModelRender :public QObject
{
   Q_OBJECT

public:

    ModelRender();

    vtkSmartPointer<vtkRenderer> getRenderer();
    vtkSmartPointer<vtkActor> getActor();
    vtkSmartPointer<vtkProperty> getProp();
    vtkSmartPointer<vtkSTLReader> getSTLReader();
    vtkSmartPointer<vtkDataSetMapper> getMapper();
    vtkSmartPointer<vtkLight> getLight();
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> getRenderWindow();
    vtkSmartPointer<vtkPolyData> getPolyData();
    vtkSmartPointer<vtkDataSetSurfaceFilter> getSurfaceFilter();

    QString  getFileName();
    void setFileName(QString Name);
    void STLfileReader(QString fileName);
    void setPipeline();

/***************Source build*****************************/
    void buildCube();
    void buildCylinder();
    void buildDisk();
    void buildLine();
    void buildPyramid();
    void buildSphere();
    void buildTera();
    void buildCone();

private:

    QString file;
/*****************Source part*******************************/
    vtkSmartPointer<vtkCubeSource> cube;
    vtkSmartPointer<vtkDiskSource> disk;
    vtkSmartPointer<vtkLineSource> line;
    vtkSmartPointer<vtkSphereSource> sphere;
    vtkSmartPointer<vtkCylinderSource> cylinder;
    vtkSmartPointer<vtkConeSource> cone;
    vtkSmartPointer<vtkTetra> tetra;
/***********************************************************/

    vtkSmartPointer<vtkActor> actor ;
    vtkSmartPointer<vtkRenderer> renderer ;
    vtkSmartPointer<vtkLight> mylight ;
    vtkSmartPointer<vtkProperty> prop ;
    vtkSmartPointer<vtkSTLReader> reader;
    vtkSmartPointer<vtkDataSetMapper> mapper;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkSmartPointer<vtkPolyData> polydata;
    vtkSmartPointer<vtkDataSetSurfaceFilter> surfacefilter;

};
