#ifndef VTKFILTERS_H
#define VTKFILTERS_H
#include<vtkSmartPointer.h>
#include<qobject.h>
class vtkActor;
class vtkDelaunay2D;
class vtkVertexGlyphFilter;
class vtkPolyDataMapper;
class vtkOutlineFilter;
class vtkSmoothPolyDataFilter;
class vtkDataSetSurfaceFilter;
class vtkClipDataSet;
class vtkCutter;
class vtkShrinkFilter;
class vtkDataSetMapper;


///The VTkFilters class is used for handling the filtering events
///
///The class is using the so-called Singleton designed mode as there is no point of creating more than one instance of this class
class VTkFilters: public QObject
{
	Q_OBJECT

public slots:
    ///This method is used for outline filtering
	void OutLineFiltering();

    ///This method is used for smoothing filtering
	void SmoothFiltering();

    ///This method is used for clip filtering
	void ClipFiltering();

    ///This method is used for contour filtering
	void ContourFiltering();

    ///This method is used for delaunay2d filtering
	void Delaunay2DFiltering();

    ///This method is used for shrink filtering
	void ShrinkFiltering();

	
public:
    ///This method is used for retrieving the surface filter to convert unstructuredGrid to PolyData
    ///@return return a vtkSmartPointer points to the surface filter
	const vtkSmartPointer<vtkDataSetSurfaceFilter>& GetSurfaceFilter() const{ return mSurfacefilter; };

    ///This method is used for retrieving the Singleton
    ///@returns return the reference to the Singleton
	static VTkFilters& GetInstance();

private:

     ///This is the default constructor
     VTkFilters();


     vtkSmartPointer<vtkActor> mOutlineActor;
	 vtkSmartPointer<vtkActor> mContourActor;
	 vtkSmartPointer<vtkActor> mMeshActor;
	 vtkSmartPointer<vtkActor> mPointActor;
	 vtkSmartPointer<vtkActor> mSmoothedActor;
	 vtkSmartPointer<vtkDelaunay2D> mDelaunay;
	 vtkSmartPointer<vtkVertexGlyphFilter> mGlyphFilter;
	 vtkSmartPointer<vtkPolyDataMapper> mOutlineMapper;
     vtkSmartPointer<vtkPolyDataMapper> mContourMapper;
	 vtkSmartPointer<vtkPolyDataMapper> mMeshMapper;
	 vtkSmartPointer<vtkPolyDataMapper> mPointMapper;
	 vtkSmartPointer<vtkDataSetMapper>  mDataSetMapper;
	 vtkSmartPointer<vtkPolyDataMapper> mSmoothedMapper;
	 vtkSmartPointer<vtkOutlineFilter> mOutlinefilter;
	 vtkSmartPointer<vtkSmoothPolyDataFilter> mSmoothfilter;
	 vtkSmartPointer<vtkDataSetSurfaceFilter> mSurfacefilter;
     vtkSmartPointer<vtkClipDataSet> mClipfilter;
	 vtkSmartPointer<vtkCutter> mContourfilter;
	 vtkSmartPointer<vtkShrinkFilter> mShrinkfilter;

};
#endif // VTKFILTERS_H
