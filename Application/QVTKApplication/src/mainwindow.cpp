#include <MainWindow.h>
#include "ui_MainWindow.h"
#include <modelrender.h>
#include <vtkfilters.h>
#include <qfiledialog.h>
#include <QCheckBox>
#include <vtkJPEGReader.h>
#include <vtkTexture.h>
#include <vtkTextureMapToPlane.h>
#include <vtkPolyDataNormals.h>
#include <vtkTransformTextureCoords.h>
#include <vtkPNGReader.h>
#include <qcolordialog.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCamera.h>
#include <vtkNamedColors.h>
#include <vtkPolyDataMapper.h>


MainWindow::~MainWindow()
{
	delete ui;
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	this->UISetUp();

	this->InitOpenGLWindow();

	this->SignalAndSlotSetUp();
}


void MainWindow::UISetUp()
{
    //trivial UI SetUps
    ui->setupUi(this);
    this->setFixedSize(1300, 900);
    this->setWindowTitle("Group2 project");
    this->setWindowIcon(QIcon(":/Icons/WindowIcon.png"));
    ui->openGLWidget->setFixedSize(1200, 550);
    ui->WebLink->setOpenExternalLinks(true);

    QActionGroup *SourceGroup = new QActionGroup(this);
    SourceGroup->setExclusionPolicy(QActionGroup::ExclusionPolicy::ExclusiveOptional);
    SourceGroup->addAction(ui->actionCube);
    SourceGroup->addAction(ui->actionSphere);
    SourceGroup->addAction(ui->actionCylinder);
    SourceGroup->addAction(ui->actionCone);
    SourceGroup->addAction(ui->actionDisk);
    SourceGroup->addAction(ui->actionLine);
    SourceGroup->addAction(ui->actionPyramid);
    SourceGroup->addAction(ui->actionHexaHedron);
    SourceGroup->addAction(ui->actionTetrahedron);

    ui->SetOpacity->setOrientation(Qt::Horizontal);
    ui->SetOpacity->setMinimum(0);
    ui->SetOpacity->setMaximum(10);
    ui->SetOpacity->setPageStep(1);
    this->setFixedSize(1220, 850);

}



void MainWindow::InitOpenGLWindow()
{

	// init RendererWindow
	ui->openGLWidget->SetRenderWindow(ModelRender::GetInstance().GetRenderWindow().Get());
	ui->openGLWidget->GetRenderWindow()->AddRenderer(ModelRender::GetInstance().GetRenderer());

	// init Camera
	ModelRender::GetInstance().GetCamera()->SetViewUp(0, 1, 0);
	ModelRender::GetInstance().GetCamera()->SetPosition(0, 0, 10);
	ModelRender::GetInstance().GetCamera()->SetFocalPoint(0, 0, 0);

	// init Renderer
	ModelRender::GetInstance().GetRenderer()->SetActiveCamera(ModelRender::GetInstance().GetCamera());
	ModelRender::GetInstance().GetRenderer()->SetBackground(ModelRender::GetInstance().GetColor()->GetColor3d("Black").GetData());
}


void MainWindow::SignalAndSlotSetUp()
{
	// Set the signal and slot connections
	connect(ui->CameraPosition, &QPushButton::clicked, this, &MainWindow::GetCameraPosition);
	connect(ui->GetStatistics, &QPushButton::clicked, this, &MainWindow::ModelStatistics);
	connect(ui->actionFileOpen, &QAction::triggered, this, &MainWindow::FileLoadingEvent);
	connect(ui->actionTexture, &QAction::triggered, this, &MainWindow::ApplyTexture);
	connect(ui->OutlineFilter, &QPushButton::clicked, &(VTkFilters::GetInstance()), &VTkFilters::OutLineFiltering);
	connect(ui->smoothFilter, &QPushButton::clicked, &(VTkFilters::GetInstance()), &VTkFilters::SmoothFiltering);
	connect(ui->ClipFilter, &QPushButton::clicked, &(VTkFilters::GetInstance()), &VTkFilters::ClipFiltering);
	connect(ui->Contourfilter, &QPushButton::clicked, &(VTkFilters::GetInstance()), &VTkFilters::ContourFiltering);
	connect(ui->Delaunay2Dfilter, &QPushButton::clicked, &(VTkFilters::GetInstance()), &VTkFilters::Delaunay2DFiltering);
	connect(ui->Shrinkfilter, &QPushButton::clicked, &(VTkFilters::GetInstance()), &VTkFilters::ShrinkFiltering);
	connect(ui->actionCube, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::CubeRenderEventHandler);
	connect(ui->actionSphere, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::SphereRenderEventHandler);
	connect(ui->actionCylinder, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::CylinderRenderEventHandler);
	connect(ui->actionCone, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::ConeRenderEventHandler);
	connect(ui->actionDisk, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::DiskRenderEventHandler);
	connect(ui->actionLine, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::LineRenderEventHandler);
	connect(ui->actionPyramid, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::PyramidRenderEventHandler);
	connect(ui->actionHexaHedron, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::HexahedronRenderEventHandler);
	connect(ui->actionTetrahedron, &QAction::triggered, &(ModelRender::GetInstance()), &ModelRender::TetrahedronRenderEventHandler);
    connect(ui->ResetModel, &QPushButton::clicked, &(ModelRender::GetInstance()),&ModelRender::RestModel);

    //This method is used for changing the opacity of the model, using Lambda expression for convenience
	connect(ui->SetOpacity, QOverload<int>::of(&QSlider::valueChanged), [=](int currentVal) {
		double OpacityFacotr = static_cast<double>(currentVal) / 10;
		ModelRender::GetInstance().GetActor()->GetProperty()->SetOpacity(OpacityFacotr);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

   //This method is used for changing the model color
	connect(ui->setModelCol, &QPushButton::clicked, [this]() {
		QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
		double Red = static_cast<double>(color.red())/255;
		double Green = static_cast<double>(color.green())/255;
		double Blue = static_cast<double>(color.blue())/255;
		ModelRender::GetInstance().GetActor()->GetProperty()->SetColor(Red, Green, Blue);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for changing the diffuse color
	connect(ui->SetDiffuseColor, &QPushButton::clicked, [this]() {
		QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
		double Red = static_cast<double>(color.red());
		double Green = static_cast<double>(color.green());
		double Blue = static_cast<double>(color.blue());
		ModelRender::GetInstance().GetActor()->GetProperty()->SetDiffuseColor(Red, Green, Blue);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for changing the edge color
	connect(ui->SetEdgeColor, &QPushButton::clicked, [this]() {
		QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
		double Red = static_cast<double>(color.red());
		double Green = static_cast<double>(color.green());
		double Blue = static_cast<double>(color.blue());
		ModelRender::GetInstance().GetActor()->GetProperty()->SetEdgeVisibility(true);
		ModelRender::GetInstance().GetActor()->GetProperty()->SetEdgeColor(Red, Green, Blue);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for changing the background color
	connect(ui->setBackCol, &QPushButton::clicked, [this]() {
		QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
		double Red = static_cast<double>(color.red());
		double Green = static_cast<double>(color.green());
		double Blue = static_cast<double>(color.blue());
		ModelRender::GetInstance().GetRenderer()->SetBackground(Red, Green, Blue);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for changing the representation to wireframe
	connect(ui->wireframe, &QRadioButton::toggled, [this]() {
		ModelRender::GetInstance().GetActor()->GetProperty()->SetRepresentationToWireframe();
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for changing the representation to solid
	connect(ui->Solid, &QRadioButton::toggled, [this]() {
		ModelRender::GetInstance().GetActor()->GetProperty()->SetRepresentationToSurface();
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for changing the representation to vertices
	connect(ui->vertices, &QRadioButton::toggled, [this]() {
		ModelRender::GetInstance().GetActor()->GetProperty()->SetRepresentationToPoints();
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for enable front face culling
	connect(ui->FrontfaceCulling, &QCheckBox::stateChanged, [this](int state) {
		ModelRender::GetInstance().GetActor()->GetProperty()->SetFrontfaceCulling(state);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});

	//This method is used for enable back face culling
	connect(ui->BackfaceCulling, &QCheckBox::stateChanged, [this](int state) {
		ModelRender::GetInstance().GetActor()->GetProperty()->SetBackfaceCulling(state);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	});
}


void MainWindow::GetCameraPosition()
{
	//get the current camera position and display the numbers on the LCD widget
	double *position = ModelRender::GetInstance().GetRenderer()->GetActiveCamera()->GetPosition();
	ui->lcdNumber_x->setMode(QLCDNumber::Dec);
	ui->lcdNumber_Y->setMode(QLCDNumber::Dec);
	ui->lcdNumber_Z->setMode(QLCDNumber::Dec);
	ui->lcdNumber_x->display(position[0]);
	ui->lcdNumber_Y->display(position[1]);
	ui->lcdNumber_Z->display(position[2]);
}


void MainWindow::ModelStatistics()
{
    //get the model statistic and display the numbers on the LCD widget
	ui->NumofCells->setMode(QLCDNumber::Dec);
	ui->NumofPoins->setMode(QLCDNumber::Dec);
	int NumofCells = ModelRender::GetInstance().GetPolyData()->GetNumberOfCells();
	int NumofPoins = ModelRender::GetInstance().GetPolyData()->GetNumberOfPoints();
	ui->NumofCells->display(NumofCells);
	ui->NumofPoins->display(NumofPoins);
}

void MainWindow::FileLoadingEvent()
{
	//open the file and read the data
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("Model Files (*.mod *.stl)"));
	string input_file = fileName.toStdString();

	//detect the file suffix
	const char *path = input_file.c_str();
	QFileInfo fi(path);
	QString ext = fi.completeSuffix();

	//do the model rendering depends upon the suffix detected
	if (ext == "stl")
	{

		ModelRender::GetInstance().STLFileRender(input_file);
	}
	if (ext == "mod")
	{

		ModelRender::GetInstance().ModFileRender(input_file);
	}
}

void MainWindow::ApplyTexture()
{
	//open the file and read the data
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("Model Files (*.jpg *.png)"));
	string input_file = fileName.toStdString();
	//detect the file surfix
	const char *path = input_file.c_str();
	QFileInfo fi(path);
	QString ext = fi.completeSuffix();

	//allocating required variables
	vtkSmartPointer<vtkTexture> texture = vtkSmartPointer<vtkTexture>::New();
	vtkSmartPointer<vtkPolyDataNormals> normal = vtkSmartPointer<vtkPolyDataNormals>::New();
	vtkSmartPointer<vtkTextureMapToPlane> texturePlane = vtkSmartPointer<vtkTextureMapToPlane>::New();
	vtkSmartPointer<vtkTransformTextureCoords> Coords = vtkSmartPointer<vtkTransformTextureCoords>::New();
	vtkSmartPointer<vtkPolyDataMapper> planeMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	vtkSmartPointer<vtkActor> textureActor = vtkSmartPointer<vtkActor>::New();

	//do the data parser
	if (ext == "png")
	{

		// Read the image data
		vtkSmartPointer<vtkPNGReader> PNGReader = vtkSmartPointer<vtkPNGReader>::New();
		PNGReader->SetFileName(input_file.c_str());

		//set up the generic pipeline
		texture->SetInputConnection(PNGReader->GetOutputPort());
		texture->InterpolateOn();
		normal->SetInputData(ModelRender::GetInstance().GetPolyData());
		texturePlane->SetInputConnection(normal->GetOutputPort());
		Coords->SetInputConnection(texturePlane->GetOutputPort());
		Coords->SetScale(1, 1, 1);
		planeMapper->SetInputConnection(Coords->GetOutputPort());
		textureActor->SetMapper(planeMapper);
		textureActor->SetTexture(texture);
		ModelRender::GetInstance().GetRenderer()->AddActor(textureActor);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	}
	if (ext == "jpg")
	{

        // Read the image data
		vtkSmartPointer<vtkJPEGReader> jPEGReader = vtkSmartPointer<vtkJPEGReader>::New();
		jPEGReader->SetFileName(input_file.c_str());

		//set up the generic pipeline
		texture->SetInputConnection(jPEGReader->GetOutputPort());
		texture->InterpolateOn();
		normal->SetInputData(ModelRender::GetInstance().GetPolyData());
		texturePlane->SetInputConnection(normal->GetOutputPort());
		Coords->SetInputConnection(texturePlane->GetOutputPort());
		Coords->SetScale(1, 1, 1);
		planeMapper->SetInputConnection(Coords->GetOutputPort());
		textureActor->SetMapper(planeMapper);
		textureActor->SetTexture(texture);
		ModelRender::GetInstance().GetRenderer()->AddActor(textureActor);
		ModelRender::GetInstance().GetRenderWindow()->Render();
	}
}
