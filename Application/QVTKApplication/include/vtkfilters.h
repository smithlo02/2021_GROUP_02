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

/** @file
* The declarations of the vtk filters class
*/

///The VTkFilters class is used for handling the filtering events
///
///The class is using the so-called Singleton designed mode as there is no point of creating more than one instance of this class
class VTkFilters: public QObject
{
	Q_OBJECT

public slots:
    ///This method is used for outline filtering
	/** Outline Filter
	* only keeps the outline of the model
	*/
	void OutLineFiltering();

    ///This method is used for smoothing filtering
	/** Smoothing filter
	* This function uses smoothing filtering
	*/
	void SmoothFiltering();

    ///This method is used for clip filtering
	/** Clip filter
	* This filter clips the model on the z axis
	*/
	void ClipFiltering();

    ///This method is used for contour filtering
	/** Contour filter
	* This filter shows the contours of the 3D model as isosurfaces
	*/
	void ContourFiltering();

    ///This method is used for delaunay2d filtering
	/** Delauney 2D filter
	* This filter renders the model only out of triangular shapes instead of smooth curves
	*/
	void Delaunay2DFiltering();

    ///This method is used for shrink filtering
	/** Shrink filter
	* the shrink filter shrinks each face of the model showing the model in an exploded view
	*/
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
