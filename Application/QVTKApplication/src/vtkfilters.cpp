#include "vtkfilters.h"
#include <vtkPlane.h>
#include <vtkPolyDataNormals.h>
#include <modelrender.h>
#include <vtkActor.h>
#include <vtkDelaunay2D.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkOutlineFilter.h>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkDataSetSurfaceFilter.h>
#include <vtkClipDataSet.h>
#include <vtkCutter.h>
#include <vtkShrinkFilter.h>
#include <vtkDataSetMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <qmessagebox.h>

VTkFilters &VTkFilters::GetInstance()
{
	static VTkFilters Singleton;
	return Singleton;
}

VTkFilters::VTkFilters()
{

	mOutlineActor = vtkSmartPointer<vtkActor>::New();
	mContourActor = vtkSmartPointer<vtkActor>::New();
	mMeshActor = vtkSmartPointer<vtkActor>::New();
	mPointActor = vtkSmartPointer<vtkActor>::New();
	mSmoothedActor = vtkSmartPointer<vtkActor>::New();
	mDelaunay = vtkSmartPointer<vtkDelaunay2D>::New();
	mGlyphFilter = vtkSmartPointer<vtkVertexGlyphFilter>::New();
	mOutlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mContourMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mMeshMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mPointMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mDataSetMapper = vtkSmartPointer<vtkDataSetMapper>::New();
	mSmoothedMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mOutlinefilter = vtkSmartPointer<vtkOutlineFilter>::New();
	mSmoothfilter = vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
	mSurfacefilter = vtkSmartPointer<vtkDataSetSurfaceFilter>::New();
	mClipfilter = vtkSmartPointer<vtkClipDataSet>::New();
	mContourfilter = vtkSmartPointer<vtkCutter>::New();
	mShrinkfilter = vtkSmartPointer<vtkShrinkFilter>::New();
}

void VTkFilters::OutLineFiltering()
{
    //check if the dynamically allocated memory block of PolyData is empty, if it does, then no model exists by now
    if(ModelRender::GetInstance().GetPolyData()!= nullptr) {
        //Set up generic pipeline: Source->filter->mapper->actor
        mOutlinefilter->SetInputData(ModelRender::GetInstance().GetPolyData());
        mOutlinefilter->Update();
        mOutlineMapper->SetInputConnection(mOutlinefilter->GetOutputPort());
        mOutlineActor->SetMapper(mOutlineMapper);
        //set the Line width and color
        mOutlineActor->GetProperty()->SetColor(1, 0, 0);
        mOutlineActor->GetProperty()->SetLineWidth(1.5);
        ModelRender::GetInstance().GetRenderer()->AddActor(mOutlineActor);
        ModelRender::GetInstance().GetRenderWindow()->Render();
    }
    else
        QMessageBox::warning(nullptr,"Warning","No Model Found!");

}

void VTkFilters::SmoothFiltering()
{
    //check if the dynamically allocated memory block of PolyData is empty, if it does, then no model exists by now
    if(ModelRender::GetInstance().GetPolyData()!= nullptr) {
        //Set up generic pipeline: Source->filter->mapper->actor
        mDelaunay->SetInputData(ModelRender::GetInstance().GetPolyData());
        mDelaunay->Update();
        mSmoothfilter->SetInputConnection(mDelaunay->GetOutputPort());
        mSmoothfilter->SetNumberOfIterations(15);
        mSmoothfilter->SetRelaxationFactor(0.1);
        mSmoothfilter->FeatureEdgeSmoothingOff();
        mSmoothfilter->BoundarySmoothingOn();
        mSmoothfilter->Update();

        // Update normals on newly smoothed PolyData
        auto normalGenerator = vtkSmartPointer<vtkPolyDataNormals>::New();
        normalGenerator->SetInputConnection(mSmoothfilter->GetOutputPort());
        normalGenerator->ComputePointNormalsOn();
        normalGenerator->ComputeCellNormalsOn();
        normalGenerator->Update();
        mSmoothedMapper->SetInputConnection(normalGenerator->GetOutputPort());
        mSmoothedActor->SetMapper(mSmoothedMapper);
        ModelRender::GetInstance().GetRenderer()->AddActor(mSmoothedActor);
        ModelRender::GetInstance().GetRenderWindow()->Render();
    }
    else
        QMessageBox::warning(nullptr,"Warning","No Model Found!");

}

void VTkFilters::ClipFiltering()
{
    //check if the dynamically allocated memory block of PolyData is empty, if it does, then no model exists by now
    if(ModelRender::GetInstance().GetPolyData()!= nullptr) {
        //Set up generic pipeline: Source->filter->mapper->actor
        //create a plane to clip
        auto planeLeft = vtkSmartPointer<vtkPlane>::New();
        planeLeft->SetOrigin(ModelRender::GetInstance().GetPolyData()->GetCenter());
        planeLeft->SetNormal(0.0, 0.0, 1.0);
        mClipfilter->SetInputData(ModelRender::GetInstance().GetPolyData());
        mClipfilter->SetClipFunction(planeLeft.Get());
        mClipfilter->Update();
        mDataSetMapper->SetInputConnection(mClipfilter->GetOutputPort());
        ModelRender::GetInstance().GetActor()->SetMapper(mDataSetMapper);
        ModelRender::GetInstance().GetRenderer()->AddActor(ModelRender::GetInstance().GetActor());
        ModelRender::GetInstance().GetRenderWindow()->Render();
    }
    else
    QMessageBox::warning(nullptr,"Warning","No Model Found!");
}

void VTkFilters::ContourFiltering()
{
    //check if the dynamically allocated memory block of PolyData is empty, if it does, then no model exists by now
    if(ModelRender::GetInstance().GetPolyData()!= nullptr) {
        //Set up generic pipeline: Source->filter->mapper->actor
        // Create a plane to cut
        auto plane =
                vtkSmartPointer<vtkPlane>::New();
        plane->SetOrigin(ModelRender::GetInstance().GetPolyData()->GetCenter());
        plane->SetNormal(1, 1, 1);

        //compute the upper bounds of the model
        double minBound[3];
        minBound[0] = ModelRender::GetInstance().GetBounds()[0];
        minBound[1] = ModelRender::GetInstance().GetBounds()[2];
        minBound[2] = ModelRender::GetInstance().GetBounds()[4];

        //compute the lower bounds of the model
        double maxBound[3];
        maxBound[0] = ModelRender::GetInstance().GetBounds()[1];
        maxBound[1] = ModelRender::GetInstance().GetBounds()[3];
        maxBound[2] = ModelRender::GetInstance().GetBounds()[5];

        //compute the center of the model
        double center[3];
        center[0] = ModelRender::GetInstance().GetPolyData()->GetCenter()[0];
        center[1] = ModelRender::GetInstance().GetPolyData()->GetCenter()[1];
        center[2] = ModelRender::GetInstance().GetPolyData()->GetCenter()[2];

        //compute the max and min distances
        double distanceMin = sqrt(vtkMath::Distance2BetweenPoints(minBound, center));
        double distanceMax = sqrt(vtkMath::Distance2BetweenPoints(maxBound, center));

        //Create cutter
        mContourfilter->SetCutFunction(plane);
        mContourfilter->SetInputData(ModelRender::GetInstance().GetPolyData());
        mContourfilter->GenerateValues(20, -distanceMin, distanceMax);
        mContourMapper->SetInputConnection(mContourfilter->GetOutputPort());
        mContourMapper->ScalarVisibilityOff();
        mContourActor->GetProperty()->SetColor(ModelRender::GetInstance().GetColor()->GetColor3d("Red").GetData());
        mContourActor->GetProperty()->SetLineWidth(5);
        mContourActor->SetMapper(mContourMapper);
        ModelRender::GetInstance().GetRenderer()->AddActor(mContourActor);
        ModelRender::GetInstance().GetRenderWindow()->Render();
    }
    else
    QMessageBox::warning(nullptr,"Warning","No Model Found!");
}

void VTkFilters::Delaunay2DFiltering()
{
    //check if the dynamically allocated memory block of PolyData is empty, if it does, then no model exists by now
    if(ModelRender::GetInstance().GetPolyData()!= nullptr) {
        //Set up generic pipeline: Source->filter->mapper->actor
        //filter the meshes out
        mDelaunay->SetInputData(ModelRender::GetInstance().GetPolyData());
        mMeshMapper->SetInputConnection(mDelaunay->GetOutputPort());
        mMeshActor->SetMapper(mMeshMapper);
        mMeshActor->GetProperty()->SetColor(ModelRender::GetInstance().GetColor()->GetColor3d("Banana").GetData());
        mMeshActor->GetProperty()->EdgeVisibilityOn();
        //filter the points out
        mGlyphFilter->SetInputData(ModelRender::GetInstance().GetPolyData());
        mPointMapper->SetInputConnection(mGlyphFilter->GetOutputPort());
        mPointActor->GetProperty()->SetColor(ModelRender::GetInstance().GetColor()->GetColor3d("Tomato").GetData());
        mPointActor->GetProperty()->SetPointSize(5);
        mPointActor->SetMapper(mPointMapper);
        ModelRender::GetInstance().GetRenderer()->AddActor(mMeshActor);
        ModelRender::GetInstance().GetRenderer()->AddActor(mPointActor);
        ModelRender::GetInstance().GetRenderWindow()->Render();
    }
    else
    QMessageBox::warning(nullptr,"Warning","No Model Found!");
}

void VTkFilters::ShrinkFiltering()
{
    //check if the dynamically allocated memory block of PolyData is empty, if it does, then no model exists by now
    if(ModelRender::GetInstance().GetPolyData()!= nullptr) {
        //Set up generic pipeline: Source->filter->mapper->actor
        mShrinkfilter->SetInputData(ModelRender::GetInstance().GetPolyData());
        //set the shrink factor
        mShrinkfilter->SetShrinkFactor(.8);
        mShrinkfilter->Update();
        mDataSetMapper->SetInputConnection(mShrinkfilter->GetOutputPort());
        ModelRender::GetInstance().GetActor()->SetMapper(mDataSetMapper);
        ModelRender::GetInstance().GetRenderer()->AddActor(ModelRender::GetInstance().GetActor());
        ModelRender::GetInstance().GetRenderWindow()->Render();
    }
    else
    QMessageBox::warning(nullptr,"Warning","No Model Found!");
}
