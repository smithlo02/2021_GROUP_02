#ifndef MODELRENDER_H
#define MODELRENDER_H
#include<vtkSmartPointer.h>
#include<qobject.h>
class vtkCubeSource;
class vtkSphereSource;
class vtkConeSource;
class vtkCylinderSource;
class vtkDiskSource;
class vtkLineSource;
class vtkSTLReader;
class vtkPolyDataMapper;
class vtkGenericOpenGLRenderWindow;
class vtkActor;
class vtkCamera;
class vtkPolyData;
class vtkRenderer;
class vtkNamedColors;
class vtkAxesActor;
class vtkOrientationMarkerWidget;
using namespace std;



///The ModelRender class is used for handling the ModelRender events
///
///The class is using the so-called Singleton designed mode as there is no point of creating more than one instance of this class
class ModelRender: public QObject
{
    Q_OBJECT

public slots:

    ///This method is used for rendering a cube
    void CubeRenderEventHandler();

    ///This method is used for rendering a Cone
    void ConeRenderEventHandler();

    ///This method is used for rendering a sphere
    void SphereRenderEventHandler();

    ///This method is used for rendering a cylinder
    void CylinderRenderEventHandler();

    ///This method is used for rendering a Disk
    void DiskRenderEventHandler();

    ///This method is used for rendering a Line
    void LineRenderEventHandler();

    ///This method is used for rendering a pyramid
    void PyramidRenderEventHandler();

    ///This method is used for rendering a Tetrahedron
    void TetrahedronRenderEventHandler();

    ///This method is used for rendering a Hexahedron
    void HexahedronRenderEventHandler();

    ///This method is used for removing all the filters applied to the model
    void RestModel();


public:
    ///This method is used for rendering the Mod model
    ///@param inputFileName The path to the .Mode file
    void ModFileRender(const string& inputFileName);

    ///This method is used for rendering the STL model
    ///@param inputFileName The path to the .STL file
    void STLFileRender(const string& inputFileName);

    ///This method is used for retrieving the model Actor
    ///@returns return a vtkSmartPointer points to the Actor
    const vtkSmartPointer<vtkActor>& GetActor() const;

    ///This method is used for retrieving the current camera
    ///@returns return a vtkSmartPointer points to the current camera
    const vtkSmartPointer<vtkCamera>& GetCamera() const;

    ///This method is used for retrieving the Renderer
    ///@returns return a vtkSmartPointer points to the renderer
    const vtkSmartPointer<vtkRenderer>& GetRenderer() const;

    ///This method is used for retrieving the RenderWindow
    ///@returns return a vtkSmartPointer points to the RenderWindow
    const vtkSmartPointer<vtkGenericOpenGLRenderWindow>& GetRenderWindow() const;

    ///This method is used for retrieving the NamedColor
    ///@return return a vtkSmartPointer points to the NamedColor
    const vtkSmartPointer<vtkNamedColors>& GetColor() const;

    ///This method is used for retrieving the PolyData
    ///@return return a vtkSmartPointer points to the PolyData
    const vtkSmartPointer<vtkPolyData>& GetPolyData() const;

    ///This method is used for retrieving the Bounds
    ///@return return a vtkSmartPointer points to the Bounds
    double* GetBounds() const;

    ///This method is used for retrieving the Singleton
    ///@returns return the reference to the Singleton
    static ModelRender& GetInstance();
   
private:
     ///This is the default constructor
     ModelRender();

     ///This method is used for clearing all the Actor in the scene
     void clearActors();

     ///This method is used for placing the Actor in the scene
     void GenericRenderEvent();


     double* mBounds;
     vtkSmartPointer<vtkAxesActor> mAxes;
     vtkSmartPointer<vtkOrientationMarkerWidget> mWidget;
     vtkSmartPointer<vtkGenericOpenGLRenderWindow> mRenderWindow;
     vtkSmartPointer<vtkPolyData> mPolyData;
     vtkSmartPointer<vtkNamedColors> mColors;
     vtkSmartPointer<vtkCamera> mCamera;
     vtkSmartPointer<vtkRenderer> mRenderer;
     vtkSmartPointer<vtkActor> mActor;
     vtkSmartPointer<vtkPolyDataMapper> mMapper;
     vtkSmartPointer<vtkCubeSource> mCubeSource;
     vtkSmartPointer<vtkSphereSource> mSphereSource;
     vtkSmartPointer<vtkConeSource> mConeSource;
     vtkSmartPointer<vtkCylinderSource> mCylinderSource;
     vtkSmartPointer<vtkDiskSource> mDiskSource;
     vtkSmartPointer<vtkLineSource> mLineSource;
     vtkSmartPointer<vtkSTLReader> mSTLReader;

};

#endif 
