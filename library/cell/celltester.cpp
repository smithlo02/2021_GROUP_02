//------------------------------------------------------------------------------------------------------------------
// file: celltester.cpp
// Copyright: Samuel Ajayi - [20278110]
// Required header files: iostream, string, cell.h
//------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "cell.h"

using namespace std;

// Almost complete. Need to add assignment operators.

int main()
{
    cout << "Program to test the cell class" << endl;

//---------------------------------------------------------------------------------------------------------//
                              //// Preparations Necessary for Cell Tests ////
//---------------------------------------------------------------------------------------------------------//
        
        // Materials to be used    
        material A_Material(7, 8960, 0xb87373, "colour 1");    // Material A
        material B_Material(8, 26159, 0xFDFBFB, "colour 2");  // Material B
        
        // Vector3D points for the cells
            // Tetrahedron
            Vector3D    T_vectA(0, 0, 0), T_vectB(1, 1, 0), T_vectC(1, 0, 1), T_vectD(0, 1, 1);

            // Pyramid
            Vector3D    P_vectA(-1, -1, 0), P_vectB(1, -1, 0), P_vectC(1, 1, 0), P_vectD(-1, 1, 0), 
                        P_vectE(0, 0, 2);

            // Hexahedron
            Vector3D    H_vectA(-1, -1, -1), H_vectB(1, -1, -1), H_vectC(1, 1, -1), H_vectD(-1, 1, -1), 
                        H_vectE(-1, -1, 1), H_vectF(1, -1, 1), H_vectG(1, 1, 1), H_vectH(-1, 1, 1);

                // Centres of Gravity
                Vector3D T_cog, P_cog, H_cog;

        // Set the ID's of each Individual Vector Point
            // Tetrahedron              
            T_vectA.setID(0);           
            T_vectB.setID(1);           
            T_vectC.setID(2);           
            T_vectD.setID(3);           
                                        
            // Pyramid
            P_vectA.setID(0);
            P_vectB.setID(1);
            P_vectC.setID(2);
            P_vectD.setID(3);
            P_vectE.setID(4);

            // Hexahedron
            H_vectA.setID(0);
            H_vectB.setID(1);
            H_vectC.setID(2);
            H_vectD.setID(3);
            H_vectE.setID(4);
            H_vectF.setID(5);
            H_vectG.setID(6);
            H_vectH.setID(7);

        // Vectors of Vector3D points for each shape
             vector<Vector3D> T_allVects = {T_vectA, T_vectB, T_vectC, T_vectD};            // Tetrhahedron
             vector<Vector3D> H_allVects = {P_vectA, P_vectB, P_vectC, P_vectD, P_vectE};   // Pyramid
             vector<Vector3D> P_allVects = {H_vectA, H_vectB, H_vectC, H_vectD,             // Hexahedron
                                            H_vectE, H_vectF, H_vectG, H_vectH};            


//--start--------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------//
                                        //// Cell Tests ////
//---------------------------------------------------------------------------------------------------------//
    
    // Create:
        cell cell_fromDefault;                                                      // An empty default cell
        cell cell_fromValues(1, 'c', T_allVects, A_Material, 600.900, 4020, T_cog); // A cell with specific members
        cell cell_copier(cell_fromValues);                                          // Copy a cell

    // Set members of a cell:
        cell_fromDefault.setcellID(23);             // ID
        cell_fromDefault.setcellType('f');          // Type
        cell_fromDefault.setMaterial(B_Material);   // Material
        cell_fromDefault.setPoints(H_allVects);     // Vector Points

    // Calculate for a cell:
        cell_fromDefault.calc_cellVolume();             // ~ The volume ~
        cell_fromDefault.calc_cellWeight();             // ~ The weight
        cell_fromDefault.calc_cellCentreOfGravity();    // The centre of gravity

    // Get members of a cell:
        char findID = cell_fromDefault.getcellID();                     // ID
        char findType = cell_fromDefault.getcellType();                 // Type
        material findMaterial = cell_fromDefault.getcellMaterial();     // Material
        vector<Vector3D> copiedPoints = cell_fromDefault.getPoints();   // Vector Points
        float findWeight = cell_fromDefault.getcellWeight();            // Weight
        Vector3D findCOG = cell_fromDefault.getcellCentreOfGravity();   // Centre of Gravity
        float findVolume = cell_fromDefault.getcellVolume();            // Volume

    // Change points of a cell:
        cell_fromValues.replace_Point(3, P_vectC);  // Replace an existing point with a new one
        cell_fromValues.add_Point(P_vectE);         // Add a point to the end of a vector of points
        cell_fromValues.insert_Point(123, P_vectA); // Insert a point between a vector of points incorrectly
        cell_fromValues.insert_Point(1, P_vectA);   // Insert a point between a vector of points correctly
    

//---------------------------------------------------------------------------------------------------------//
                                        //// Tetrahedron Tests ////
//---------------------------------------------------------------------------------------------------------//

    // Create:
        tetrahedron tetrahedron_fromDefault;                                        // An empty default tetrahedron
        tetrahedron tetrahedron_fromPoints(T_vectA, T_vectB, T_vectC, T_vectD);     // A tetrahedron with specific individual points
        tetrahedron tetrahedron_fromVector(T_allVects);                             // A tetrahedron with points from a vector
        tetrahedron tetrahedron_copier(tetrahedron_fromVector);                     // Copy a tetrahedron

    // Set members of of a tetrahedron:
        tetrahedron_fromDefault.setcellID(23);             // ID
        tetrahedron_fromDefault.setcellType('f');          // Type
        tetrahedron_fromDefault.setMaterial(A_Material);   // Material
        tetrahedron_fromDefault.setPoints(H_allVects);     // Vector Points

    // Calculate for a tetrahedron:
        tetrahedron_fromDefault.calc_cellVolume();             // ~ The volume ~
        tetrahedron_fromDefault.calc_cellWeight();             // ~ The weight
        tetrahedron_fromDefault.calc_cellCentreOfGravity();    // The centre of gravity
    
    // Get members of a tetrahedron:
        char tetrahedron_copiedID = tetrahedron_copier.getcellID();                 // ID
        char tetrahedron_copiedType = tetrahedron_copier.getcellType();             // Type
        material tetrahedron_copiedMaterial = tetrahedron_copier.getcellMaterial(); // Material
        vector<Vector3D> copiedPoints = tetrahedron_copier.getPoints();             // Vector Points
        float copiedWeight = tetrahedron_copier.getcellWeight();                    // Weight
        Vector3D copiedCOG = tetrahedron_copier.getcellCentreOfGravity();           // Centre of Gravity
        float copiedVolume = tetrahedron_copier.getcellVolume();                    // Volume
    
    // Change points of a tetrahedron:
        tetrahedron_fromVector.replace_Point(3, P_vectC);  // Replace an existing point with a new one
        tetrahedron_fromVector.add_Point(P_vectD);         // Add a point to the end of a vector of points
        tetrahedron_fromVector.insert_Point(123, P_vectA); // Insert a point between a vector of points incorrectly
        tetrahedron_fromVector.insert_Point(1, P_vectA);   // Insert a point between a vector of points correctly

//---------------------------------------------------------------------------------------------------------//
                                        //// Hexahedron Tests ////
//---------------------------------------------------------------------------------------------------------//

    // Create:
        hexahedron hexahedron_fromDefault;                                          // An empty default hexahedron
        hexahedron hexahedron_fromPoints    (H_vectA, H_vectB, H_vectC, H_vectD,    // A hexahedron with specific individual points
                                             H_vectE, H_vectF, H_vectG, H_vectH);   
        hexahedron hexahedron_fromVector(H_allVects);                               // A hexahedron with points from a vector
        hexahedron hexahedron_copier(hexahedron_fromVector);                        // Copy a hexahedron

    // Set members of of a hexahedron:
        hexahedron_fromDefault.setcellID(23);             // ID
        hexahedron_fromDefault.setcellType('f');          // Type
        hexahedron_fromDefault.setMaterial(B_Material);   // Material
        hexahedron_fromDefault.setPoints(H_allVects);     // Vector Points

    // Calculate for a hexahedron:
        hexahedron_fromDefault.calc_cellVolume();           // ~ The volume ~
        hexahedron_fromDefault.calc_cellWeight();           // ~ The weight
        hexahedron_fromDefault.calc_cellCentreOfGravity();  // The centre of gravity
    
    // Get members of a hexahedron:
        char                hexahedron_copiedID         = hexahedron_copier.getcellID();                // ID
        char                hexahedron_copiedType       = hexahedron_copier.getcellType();              // Type
        material            hexahedron_copiedMaterial   = hexahedron_copier.getcellMaterial();          // Material
        vector<Vector3D>    hexahedron_copiedPoints     = hexahedron_copier.getPoints();                // Vector Points
        float               hexahedron_copiedWeight     = hexahedron_copier.getcellWeight();            // Weight
        Vector3D            hexahedron_copiedCOG        = hexahedron_copier.getcellCentreOfGravity();   // Centre of Gravity
        float               hexahedron_copiedVolume     = hexahedron_copier.getcellVolume();            // Volume
    
    // Change points of a hexahedron:
        hexahedron_fromVector.replace_Point(3, T_vectC);  // Replace an existing point with a new one
        hexahedron_fromVector.add_Point(T_vectD);         // Add a point to the end of a vector of points
        hexahedron_fromVector.insert_Point(123, T_vectA); // Insert a point between a vector of points incorrectly
        hexahedron_fromVector.insert_Point(1, T_vectA);   // Insert a point between a vector of points correctly

//---------------------------------------------------------------------------------------------------------//
                                        //// Pyramid Tests ////
//---------------------------------------------------------------------------------------------------------//
    
    // Create:
        pyramid pyramid_fromDefault;                                                // An empty default pyramid
        pyramid pyramid_fromPoints(P_vectA, P_vectB, P_vectC, P_vectD, P_vectE);    // A pyramid with specific individual points
        pyramid pyramid_fromVector(P_allVects);                                     // A pyramid with points from a vector
        pyramid pyramid_copier(pyramid_fromVector);                                 // Copy a pyramid

    // Set members of of a pyramid:
        pyramid_fromDefault.setcellID(23);             // ID
        pyramid_fromDefault.setcellType('f');          // Type
        pyramid_fromDefault.setMaterial(A_Material);   // Material
        pyramid_fromDefault.setPoints(P_allVects);     // Vector Points

    // Calculate for a pyramid:
        pyramid_fromDefault.calc_cellVolume();             // ~ The volume ~
        pyramid_fromDefault.calc_cellWeight();             // ~ The weight
        pyramid_fromDefault.calc_cellCentreOfGravity();    // The centre of gravity
    
    // Get members of a pyramid:
        char pyramid_copiedID = pyramid_copier.getcellID();                     // ID
        char pyramid_copiedType = pyramid_copier.getcellType();                 // Type
        material pyramid_copiedMaterial = pyramid_copier.getcellMaterial();     // Material
        vector<Vector3D> pyramid_copiedPoints = pyramid_copier.getPoints();     // Vector Points
        float pyramid_copiedWeight = pyramid_copier.getcellWeight();            // Weight
        Vector3D pyramid_copiedCOG = pyramid_copier.getcellCentreOfGravity();   // Centre of Gravity
        float pyramid_copiedVolume = pyramid_copier.getcellVolume();            // Volume
    
    // Change points of a pyramid:
        pyramid_fromVector.replace_Point(3, H_vectC);  // Replace an existing point with a new one
        pyramid_fromVector.add_Point(H_vectD);         // Add a point to the end of a vector of points
        pyramid_fromVector.insert_Point(123, H_vectA); // Insert a point between a vector of points incorrectly
        pyramid_fromVector.insert_Point(1, H_vectA);   // Insert a point between a vector of points correctly

//--end----------------------------------------------------------------------------------------------------//

    return 0;
}
