#include <modelrender.h>
#include <vector3d.h>
#include <vtkPoints.h>
#include <vtkPyramid.h>
#include <vtkHexahedron.h>
#include <vtkTetra.h>
#include <vtkCellArray.h>
#include <vtkUnstructuredGrid.h>
#include <vtkfilters.h>
#include <vtkActorCollection.h>
#include <vector>
#include <array>
#include <model.h>
#include <qfiledialog.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkConeSource.h>
#include <vtkCylinderSource.h>
#include <vtkDiskSource.h>
#include <vtkLineSource.h>
#include <vtkSTLReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkDataSetSurfaceFilter.h>

/** @file
* The code for the vtk renderer
*/

ModelRender& ModelRender::GetInstance()
{
	static ModelRender Singleton;
	return Singleton;
}

ModelRender::ModelRender()
{
	mCubeSource = vtkSmartPointer<vtkCubeSource>::New();
	mSphereSource = vtkSmartPointer<vtkSphereSource>::New();
	mConeSource = vtkSmartPointer<vtkConeSource>::New();
	mCylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
	mDiskSource = vtkSmartPointer<vtkDiskSource>::New();
	mLineSource = vtkSmartPointer<vtkLineSource>::New();
	mSTLReader = vtkSmartPointer<vtkSTLReader>::New();
	mColors = vtkSmartPointer<vtkNamedColors>::New();
	mMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mActor = vtkSmartPointer<vtkActor>::New();
    mRenderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	mRenderer = vtkSmartPointer<vtkRenderer>::New();
	mAxes = vtkSmartPointer<vtkAxesActor>::New();
	mWidget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    mCamera = vtkSmartPointer<vtkCamera>::New();
	mBounds = nullptr;

}

void ModelRender::clearActors()
{
    //Get the Actor list
	vtkSmartPointer<vtkActorCollection> actors = vtkActorCollection::New();
	int NumberOfActors = mRenderer->VisibleActorCount();
	actors = mRenderer->GetActors();


	//Init Traversal and remove them one by one from the scene
	actors->InitTraversal();
	for (int i = 0; i < NumberOfActors; i++)
	{
		mRenderer->RemoveActor(actors->GetNextActor());
	}
}


void ModelRender::GenericRenderEvent()
{

	//set the Actor properties
	mActor->GetProperty()->SetEdgeVisibility(false);
	mActor->GetProperty()->SetColor(mColors->GetColor3d("Pink").GetData());

	//set up axes Actor
	mAxes->SetTotalLength(1.5, 1.5, 1.5);
	mWidget->SetViewport(0.0, 0.0, 0.25, 0.25);
	mWidget->SetOrientationMarker(mAxes);
	mWidget->SetInteractor(mRenderWindow->GetInteractor());
	mWidget->SetEnabled(1);
	mWidget->SetInteractive(true);

	// Set up camera based on the bounding box to make sure the camera can auto adjusts its position
	if (mBounds != nullptr)
	{
		mRenderer->ResetCamera(mBounds);
		mRenderer->ResetCameraClippingRange(mBounds);
		mRenderWindow->Render();
	}
}
void ModelRender::CubeRenderEventHandler()
{
    //Set up generic pipeline: Source->Mapper->Actor
    mPolyData = vtkSmartPointer<vtkPolyData>::New();
	mPolyData = mCubeSource->GetOutput();
	mBounds = mPolyData->GetBounds();
	mCubeSource->Update();
	clearActors();
	mMapper->SetInputConnection(mCubeSource->GetOutputPort());
	mActor->SetMapper(mMapper);
	//Add Actor in the scene ,then Render the Actor
	mRenderer->AddActor(mActor);
	GenericRenderEvent();
}

void ModelRender::SphereRenderEventHandler()
{
    //Set up generic pipeline: Source->Mapper->Actor
    mPolyData = vtkSmartPointer<vtkPolyData>::New();
    mPolyData = mSphereSource->GetOutput();
	mBounds = mPolyData->GetBounds();
	mSphereSource->Update();
	clearActors();
	mMapper->SetInputConnection(mSphereSource->GetOutputPort());
	mActor->SetMapper(mMapper);
    //Add Actor in the scene ,then Render the Actor
	mRenderer->AddActor(mActor);
	GenericRenderEvent();
}

void ModelRender::CylinderRenderEventHandler()
{
    //Set up generic pipeline: Source->Mapper->Actor
    mPolyData = vtkSmartPointer<vtkPolyData>::New();
    mPolyData = mCylinderSource->GetOutput();
	mBounds = mPolyData->GetBounds();
	mCylinderSource->Update();
	clearActors();
	mMapper->SetInputConnection(mCylinderSource->GetOutputPort());
	mActor->SetMapper(mMapper);
    //Add Actor in the scene ,then Render the Actor
	mRenderer->AddActor(mActor);
	GenericRenderEvent();
}

void ModelRender::ConeRenderEventHandler()
{
    //Set up generic pipeline: Source->Mapper->Actor
    mPolyData = vtkSmartPointer<vtkPolyData>::New();
    mPolyData = mConeSource->GetOutput();
	mBounds = mPolyData->GetBounds();
	mConeSource->Update();
	clearActors();
	mMapper->SetInputConnection(mConeSource->GetOutputPort());
	mActor->SetMapper(mMapper);
    //Add Actor in the scene ,then Render the Actor
	mRenderer->AddActor(mActor);
	GenericRenderEvent();
}

void ModelRender::DiskRenderEventHandler()
{
    //Set up generic pipeline: Source->Mapper->Actor
    mPolyData = vtkSmartPointer<vtkPolyData>::New();
    mPolyData = mDiskSource->GetOutput();
	mBounds = mPolyData->GetBounds();
	mDiskSource->Update();
	clearActors();
	mMapper->SetInputConnection(mDiskSource->GetOutputPort());
	mActor->SetMapper(mMapper);
    //Add Actor in the scene ,then Render the Actor
	mRenderer->AddActor(mActor);
	GenericRenderEvent();
}

void ModelRender::LineRenderEventHandler()
{
    //Set up generic pipeline: Source->Mapper->Actor
    mPolyData = vtkSmartPointer<vtkPolyData>::New();
    mPolyData = mLineSource->GetOutput();
	mBounds = mPolyData->GetBounds();
	mLineSource->Update();
	clearActors();
	mMapper->SetInputConnection(mLineSource->GetOutputPort());
	mActor->SetMapper(mMapper);
    //Add Actor in the scene ,then Render the Actor
	mRenderer->AddActor(mActor);
	GenericRenderEvent();
}

void ModelRender::PyramidRenderEventHandler()
{

	//define vertices
	vector3D vertices[5] = {vector3D(0, 1.0, 1.0, 1.0), vector3D(1, -1.0, 1.0, 1.0), vector3D(2, -1.0, -1.0, 1.0), vector3D(3, 1.0, -1.0, 1.0), vector3D(4, 0.0, 0.0, 0.0)};

	std::vector<std::array<double, 3>> pointCoordinates;
	pointCoordinates.push_back({{vertices[0].get_X(), vertices[0].get_Y(), vertices[0].get_Z()}});
	pointCoordinates.push_back({{vertices[1].get_X(), vertices[1].get_Y(), vertices[1].get_Z()}});
	pointCoordinates.push_back({{vertices[2].get_X(), vertices[2].get_Y(), vertices[2].get_Z()}});
	pointCoordinates.push_back({{vertices[3].get_X(), vertices[3].get_Y(), vertices[3].get_Z()}});
	pointCoordinates.push_back({{vertices[4].get_X(), vertices[4].get_Y(), vertices[4].get_Z()}});

	// Create the points.
	auto points =
		vtkSmartPointer<vtkPoints>::New();

	// Create a pyramid from the points.
	auto pyramid = vtkSmartPointer<vtkPyramid>::New();

	for (auto i = 0; i < pointCoordinates.size(); ++i)
	{
		points->InsertNextPoint(pointCoordinates[i].data());
		pyramid->GetPointIds()->SetId(i, i);
	}

	// Add the pyramid to a cell array.
	vtkSmartPointer<vtkCellArray> pyramids =
		vtkSmartPointer<vtkCellArray>::New();
	pyramids->InsertNextCell(pyramid);

	// Add the points and pyramid to an unstructured grid.
	vtkSmartPointer<vtkUnstructuredGrid> uGrid =
		vtkSmartPointer<vtkUnstructuredGrid>::New();
	uGrid->SetPoints(points);
	uGrid->InsertNextCell(pyramid->GetCellType(), pyramid->GetPointIds());

	//get the Bounding info of the Model
	mBounds = uGrid->GetBounds();

	//convert uGrid to polydata to retrieve info for filtering
	VTkFilters::GetInstance().GetSurfaceFilter()->SetInputData(uGrid);
	VTkFilters::GetInstance().GetSurfaceFilter()->Update();
    mPolyData = VTkFilters::GetInstance().GetSurfaceFilter()->GetOutput();

	//clear the existing actors and init mapper,actor that about to be placed in the scene
	clearActors();
	mMapper->SetInputData(mPolyData);
	mActor->SetMapper(mMapper);
	mRenderer->AddActor(mActor);

	//do the rendering
	GenericRenderEvent();
}

void ModelRender::TetrahedronRenderEventHandler()
{
	//define vertices
	vector3D vertices[4] = {vector3D(0, 0.0, 0.0, 0.0), vector3D(1, 1.0, 0.0, 0.0), vector3D(2, 1.0, 1.0, 0.0), vector3D(3, 0.0, 1.0, 1.0)};

	auto points =
		vtkSmartPointer<vtkPoints>::New();
	points->InsertNextPoint(vertices[0].get_X(), vertices[0].get_Y(), vertices[0].get_Z());
	points->InsertNextPoint(vertices[1].get_X(), vertices[1].get_Y(), vertices[1].get_Z());
	points->InsertNextPoint(vertices[2].get_X(), vertices[2].get_Y(), vertices[2].get_Z());
	points->InsertNextPoint(vertices[3].get_X(), vertices[3].get_Y(), vertices[3].get_Z());

	// Add the points and tetrahedron to an unstructured grid.
	auto uGrid =
		vtkSmartPointer<vtkUnstructuredGrid>::New();
	uGrid->SetPoints(points);

	vtkIdType ptIds[] = {0, 1, 2, 3};
	uGrid->InsertNextCell(VTK_TETRA, 4, ptIds);
	//get the Bounding info of the Model
	mBounds = uGrid->GetBounds();

	//convert uGrid to polydata to retrieve info for filtering
	VTkFilters::GetInstance().GetSurfaceFilter()->SetInputData(uGrid);
	VTkFilters::GetInstance().GetSurfaceFilter()->Update();
    mPolyData = VTkFilters::GetInstance().GetSurfaceFilter()->GetOutput();

//clear the existing actors and init mapper,actor that about to be placed in the scene
	clearActors();
	mMapper->SetInputData(mPolyData);
	mActor->SetMapper(mMapper);
    mRenderer->AddActor(mActor);

	//do the rendering
    GenericRenderEvent();
}

void ModelRender::HexahedronRenderEventHandler()
{
	vector3D vertices[8] = {vector3D(0, 0.0, 0.0, 0.0), vector3D(1, 1.0, 0.0, 0.0), vector3D(2, 1.0, 1.0, 0.0), vector3D(3, 0.0, 1.0, 0.0),
							vector3D(4, 0.0, 0.0, 1.0), vector3D(5, 1.0, 0.0, 1.0), vector3D(6, 1.0, 1.0, 1.0), vector3D(7, 0.0, 1.0, 1.0)};

	std::vector<std::array<double, 3>> pointCoordinates;
	pointCoordinates.push_back({{vertices[0].get_X(), vertices[0].get_Y(), vertices[0].get_Z()}}); // Face 1
	pointCoordinates.push_back({{vertices[1].get_X(), vertices[1].get_Y(), vertices[1].get_Z()}});
	pointCoordinates.push_back({{vertices[2].get_X(), vertices[2].get_Y(), vertices[2].get_Z()}});
	pointCoordinates.push_back({{vertices[3].get_X(), vertices[3].get_Y(), vertices[3].get_Z()}});
	pointCoordinates.push_back({{vertices[4].get_X(), vertices[4].get_Y(), vertices[4].get_Z()}}); // Face 2
	pointCoordinates.push_back({{vertices[5].get_X(), vertices[5].get_Y(), vertices[5].get_Z()}});
	pointCoordinates.push_back({{vertices[6].get_X(), vertices[6].get_Y(), vertices[6].get_Z()}});
	pointCoordinates.push_back({{vertices[7].get_X(), vertices[7].get_Y(), vertices[7].get_Z()}});

	// Create the points.
	auto points =
		vtkSmartPointer<vtkPoints>::New();

	// Create a hexahedron from the points.
	auto hex =
		vtkSmartPointer<vtkHexahedron>::New();

	for (auto i = 0; i < pointCoordinates.size(); ++i)
	{
		points->InsertNextPoint(pointCoordinates[i].data());
		hex->GetPointIds()->SetId(i, i);
	}

	// Add the hexahedron to a cell array.
	auto hexs =
		vtkSmartPointer<vtkCellArray>::New();
	hexs->InsertNextCell(hex);

	// Add the points and hexahedron to an unstructured grid.
	auto uGrid =
		vtkSmartPointer<vtkUnstructuredGrid>::New();
	uGrid->SetPoints(points);
	uGrid->InsertNextCell(hex->GetCellType(), hex->GetPointIds());
	//get the Bounding info of the Model
    mBounds = uGrid->GetBounds();

	//convert uGrid to polydata to retrieve info for filtering
	VTkFilters::GetInstance().GetSurfaceFilter()->SetInputData(uGrid);
	VTkFilters::GetInstance().GetSurfaceFilter()->Update();
    mPolyData = VTkFilters::GetInstance().GetSurfaceFilter()->GetOutput();

    //clear the existing actors and init mapper,actor that about to be placed in the scene
	clearActors();
	mMapper->SetInputData(mPolyData);
	mActor->SetMapper(mMapper);
	mRenderer->AddActor(mActor);

	//do the rendering
	GenericRenderEvent();
}

void ModelRender::ModFileRender(const string &inputFileName)
{

	Model m1;
	m1.Read_from_A_file(inputFileName);

	//load the points
	auto vtk_points = vtkSmartPointer<vtkPoints>::New();
	for (auto i = 0; i < m1.get_vertex_num(); i++)
	{

		vtk_points->InsertNextPoint(m1.points[i].get_X(), m1.points[i].get_Y(), m1.points[i].get_Z());
	}

	auto unstructuredGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
	unstructuredGrid->SetPoints(vtk_points);

	//load and render the cell
	for (auto i = 0; i < m1.get_Cell_num(); i++)
	{

		//event for rendering tetrahedron
		if (m1.get_cell_type(i) == 't')
		{

			vtkIdType ptIds[] = {m1.Cells[i]->cell_vertices[0].get_ID(), m1.Cells[i]->cell_vertices[1].get_ID(), m1.Cells[i]->cell_vertices[2].get_ID(), m1.Cells[i]->cell_vertices[3].get_ID()};
			unstructuredGrid->InsertNextCell(VTK_TETRA, 4, ptIds);
		}

		//event for rendering pyramid
		if (m1.get_cell_type(i) == 'p')
		{

			vtkIdType ptIds[] = {m1.Cells[i]->cell_vertices[0].get_ID(), m1.Cells[i]->cell_vertices[1].get_ID(), m1.Cells[i]->cell_vertices[2].get_ID(), m1.Cells[i]->cell_vertices[3].get_ID(),
								 m1.Cells[i]->cell_vertices[4].get_ID(), m1.Cells[i]->cell_vertices[5].get_ID()};
			unstructuredGrid->InsertNextCell(VTK_PYRAMID, 5, ptIds);
		}

		//event for rendering hexahedron
		if (m1.get_cell_type(i) == 'h')
		{

			vtkIdType ptIds[] = {m1.Cells[i]->cell_vertices[0].get_ID(), m1.Cells[i]->cell_vertices[1].get_ID(), m1.Cells[i]->cell_vertices[2].get_ID(), m1.Cells[i]->cell_vertices[3].get_ID(),
								 m1.Cells[i]->cell_vertices[4].get_ID(), m1.Cells[i]->cell_vertices[5].get_ID(), m1.Cells[i]->cell_vertices[6].get_ID(), m1.Cells[i]->cell_vertices[7].get_ID()};
			unstructuredGrid->InsertNextCell(VTK_HEXAHEDRON, 8, ptIds);
		}
	}
    //get the Bounding info of the Model
	mBounds = unstructuredGrid->GetBounds();

    //convert uGrid to polydata to retrieve info for filtering
	VTkFilters::GetInstance().GetSurfaceFilter()->SetInputData(unstructuredGrid);
	VTkFilters::GetInstance().GetSurfaceFilter()->Update();
    mPolyData = VTkFilters::GetInstance().GetSurfaceFilter()->GetOutput();

    //clear the existing actors and init mapper,actor that about to be placed in the scene
	clearActors();
	mMapper->SetInputData(mPolyData);
	mActor->SetMapper(mMapper);
	mRenderer->AddActor(mActor);

	//do the rendering
	GenericRenderEvent();
}

void ModelRender::STLFileRender(const string &inputFileName)
{

	mSTLReader->SetFileName(inputFileName.c_str());
    mSTLReader->Update();
    mPolyData = mSTLReader->GetOutput();
	mBounds = mPolyData->GetBounds();

    //clear the existing actors and init mapper,actor that about to be placed in the scene
	clearActors();
	mMapper->SetInputData(mPolyData);
	mActor->SetMapper(mMapper);
	mRenderer->AddActor(mActor);

	//do the rendering
    GenericRenderEvent();
}

void ModelRender::RestModel() {

    //clear all the filter applied to model
    this->clearActors();
    mMapper->SetInputData(mPolyData);
    mActor->SetMapper(mMapper);
    mRenderer->AddActor(mActor);
    GenericRenderEvent();

}

const vtkSmartPointer<vtkActor>& ModelRender::GetActor() const{
    return this->mActor;
}

const vtkSmartPointer<vtkCamera> &ModelRender::GetCamera() const{
    return this->mCamera;
}

const vtkSmartPointer<vtkRenderer> &ModelRender::GetRenderer() const{
    return this->mRenderer;
}

const vtkSmartPointer<vtkGenericOpenGLRenderWindow> &ModelRender::GetRenderWindow() const{
    return this->mRenderWindow;
}

const vtkSmartPointer<vtkNamedColors> &ModelRender::GetColor() const{
    return this->mColors;
}

const vtkSmartPointer<vtkPolyData> &ModelRender::GetPolyData() const{
    return this->mPolyData;
}

double *ModelRender::GetBounds() const{
    return this->mBounds;
}


