#include "ModelRender.h"

ModelRender::ModelRender(){
    cube = vtkSmartPointer<vtkCubeSource>::New();// make a cube
    disk = vtkSmartPointer<vtkDiskSource>::New();
    line = vtkSmartPointer<vtkLineSource>::New();
    sphere = vtkSmartPointer<vtkSphereSource>::New();
    cylinder = vtkSmartPointer<vtkCylinderSource>::New();
    cone = vtkSmartPointer<vtkConeSource>::New();
    tetra = vtkSmartPointer<vtkTetra> ::New();

    actor = vtkSmartPointer<vtkActor>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
    mylight  = vtkSmartPointer<vtkLight>::New();
    prop= vtkSmartPointer<vtkProperty>::New() ;
    reader= vtkSmartPointer<vtkSTLReader>::New();
    mapper= vtkSmartPointer<vtkDataSetMapper>::New();
    renderWindow =  vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    polydata = vtkSmartPointer<vtkPolyData>::New();

    surfacefilter = vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
}

/*
 * read the STL files
 */

void ModelRender::STLfileReader(QString fileName){

    reader->SetFileName(fileName.toLatin1().data());
    reader->Update();
    file=fileName;

}
/*
 * set general vtk pipeline
 *
 * source->polydata->mapper->actor->renderer->rendererwindow
 *
 */
void ModelRender::setPipeline(){
    polydata=reader->GetOutput();
    mapper->SetInputConnection(reader->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0, 0, 0);
    actor->SetProperty(prop);
    renderer->SetBackground(85,255,127);
    mylight->SetColor(0,0,0);
    //renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();
}
/*
 * create a cube
 *
 */
void ModelRender::buildCube(){

    qDebug()<<"build a cube";
    polydata=cube->GetOutput();
    cube->Update();
    mapper->SetInputConnection(cube->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();
}
/*
 *create a cylinder
 */
void ModelRender::buildCylinder(){
    qDebug()<<"build a Cylinder";
    polydata=cylinder->GetOutput();
    cylinder->Update();
    mapper->SetInputConnection(cylinder->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();

}
/*
 * create a disk
 *
 */
void ModelRender::buildDisk(){
    qDebug()<<"build a Disk";
    polydata=disk->GetOutput();
    disk->Update();
    mapper->SetInputConnection(disk->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();

}
/*
 * create a line
 */
void ModelRender::buildLine(){
    qDebug()<<"build a Line";
    polydata=line->GetOutput();
    line->Update();
    mapper->SetInputConnection(line->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();



}

/*
 * create a pyramid using vtkpoints
 *
 * pipeline: points->pyramid->cellsarray->unstructuredGrid->surface filter->polydata...
 *          |                                     ^
 *          |-------------------------------------|
 */
void ModelRender::buildPyramid(){

    vtkSmartPointer<vtkPoints> points =vtkSmartPointer<vtkPoints>::New();
    //five vertices created
    float p0[3] = {1.0, 1.0, 1.0};
    float p1[3] = {-1.0, 1.0, 1.0};
    float p2[3] = {-1.0, -1.0, 1.0};
    float p3[3] = {1.0, -1.0, 1.0};
    float p4[3] = {0.0, 0.0, 0.0};

    points->InsertNextPoint(p0);
    points->InsertNextPoint(p1);
    points->InsertNextPoint(p2);
    points->InsertNextPoint(p3);
    points->InsertNextPoint(p4);

    vtkSmartPointer<vtkPyramid> pyramid =vtkSmartPointer<vtkPyramid>::New();
    pyramid->GetPointIds()->SetId(0, 0);
    pyramid->GetPointIds()->SetId(1, 1);
    pyramid->GetPointIds()->SetId(2, 2);
    pyramid->GetPointIds()->SetId(3, 3);
    pyramid->GetPointIds()->SetId(4, 4);

    vtkSmartPointer<vtkCellArray> cells=vtkSmartPointer<vtkCellArray>::New();
    cells->InsertNextCell(pyramid);

    vtkSmartPointer<vtkUnstructuredGrid> ug=vtkSmartPointer<vtkUnstructuredGrid>::New();
    ug->SetPoints(points);
    ug->InsertNextCell(pyramid->GetCellType(), pyramid->GetPointIds());

    //convert unstructuredgrid data to polydata
    surfacefilter->SetInputData(ug);
    surfacefilter->Update();
    polydata = surfacefilter->GetOutput();

    mapper->SetInputData(polydata);
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    //rendering
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();

}

/*
 *
 * create a sphere
 */
void ModelRender::buildSphere(){
    qDebug()<<"build a sphere";
    polydata=sphere->GetOutput();
    sphere->Update();
    mapper->SetInputConnection(sphere->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();

}
/*
 * create a cone
 */
void ModelRender::buildCone(){
    qDebug()<<"build a Cone";
    polydata=cone->GetOutput();
    cone->Update();
    mapper->SetInputConnection(cone->GetOutputPort());
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    renderer->RemoveAllViewProps();
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();


}
/*
 *
 * create a tera using vtkpoints
 *
 */
void ModelRender::buildTera(){

    vtkSmartPointer<vtkPoints> points= vtkSmartPointer<vtkPoints>::New();
    //four vertices
    points->InsertNextPoint(0, 0, 0);
    points->InsertNextPoint(1, 0, 0);
    points->InsertNextPoint(0, 1, 0);
    points->InsertNextPoint(0, 1, 1);

    vtkSmartPointer<vtkUnstructuredGrid> ug =vtkSmartPointer<vtkUnstructuredGrid>::New();
    ug->SetPoints(points);
    vtkIdType ptIds[]={0,1,2,3};
    ug->InsertNextCell(VTK_TETRA,4,ptIds);

    // convert unstructured grid data to polydata
    surfacefilter->SetInputData(ug);
    surfacefilter->Update();
    polydata = surfacefilter->GetOutput();

    mapper->SetInputData(polydata);
    actor->SetMapper(mapper);
    prop->SetColor(1.0,0,0);
    actor->SetProperty(prop);
    //rendering
    renderer->AddLight(mylight);
    renderer->AddActor(actor);
    renderer->GetRenderWindow()->Render();

}



void ModelRender::setFileName(QString Name){
    this->file= Name;
}

QString ModelRender::getFileName(){
    return this->file;
}
vtkSmartPointer<vtkRenderer> ModelRender::getRenderer(){
    return this->renderer;
}

vtkSmartPointer<vtkActor> ModelRender::getActor(){
    return this->actor;

}
vtkSmartPointer<vtkProperty> ModelRender::getProp(){
    return this->prop;

}
vtkSmartPointer<vtkSTLReader> ModelRender::getSTLReader(){
   return this->reader;
}
vtkSmartPointer<vtkDataSetMapper> ModelRender::getMapper(){
   return this->mapper;
}
vtkSmartPointer<vtkLight> ModelRender::getLight(){
    return this->mylight;
}
vtkSmartPointer<vtkGenericOpenGLRenderWindow> ModelRender::getRenderWindow(){
    return this->renderWindow;
}

vtkSmartPointer<vtkPolyData> ModelRender::getPolyData(){
    return this->polydata;
}

vtkSmartPointer<vtkDataSetSurfaceFilter> ModelRender::getSurfaceFilter(){

    return this->surfacefilter;

}

