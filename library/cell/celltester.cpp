#include <iostream>
#include <string>
#include <cell.h>

using namespace std;

// cell header and source code complete. Needs testing.

int main()
{
    cout << "Program to test the cell class" << endl;

//---------------------------------------------------------------------------------------------------------//
                              //// Preparations Necessary for Cell Tests ////
//---------------------------------------------------------------------------------------------------------//
        // Material to be used    
        material A_Material(7, 8960, "basic1", 0xb87373);    // Material A
        material B_Material(8, 26159, "basic2", 0xFDFBFB);  // Material B
        
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

        // Set the ID's of each Vector Point
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
                                            H_vectE, H_vectF, H_vectG, H_vectH};            //


//--start--------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------//
                                        //// Cell Tests ////
//---------------------------------------------------------------------------------------------------------//
    
    // Create:
        
        cell cell_fromdefault; // An empty default cell
        cell cell_fromvalues(1, 'c', T_allVects, A_Material, 600.900, 4020, T_cog); // A cell with specific fromvalues
        cell cell_copier(cell_fromvalues);  // Copy a cell

    // Obtain fromvalues from a cell:
        char copiedID = cell_copier.getcellID();  // ID
        char copiedType = cell_copier.getcellType(); // Type
        vector<Vector3D> copiedPoints = cell_copier.getPoints();   // Vector Points
        material copiedMaterial = cell_copier.getcellMaterial();         // Material
        float copiedWeight = cell_copier.getcellWeight();  // Weight
        Vector3D copiedCOG = cell_copier.getcellCentreOfGravity();  // Centre of Gravity
        float copiedVolume = cell_copier.getcellVolume();  // Volume
        
    // Set fromvalues of a cell:
        cell_fromdefault.setcellID(23);    // ID
        cell_fromdefault.setcellType('f');  // Type
        cell_fromdefault.setMaterial(B_Material);            // Material
        cell_fromdefault.setPoints(H_allVects);   // Vector Points

    // Calculate for a cell:
        cell_fromdefault.calc_cellVolume();    // ~ The volume ~
        cell_fromdefault.calc_cellWeight();    // ~ The weight
        cell_fromdefault.calc_cellCentreOfGravity();    // The centre of gravity

    // Change points of a cell:
        cell_fromvalues.replace_Point(3, P_vectC); // Replace an existing point with a new one
        cell_fromvalues.add_Point(P_vectE);   // Add a point to the end of a vector of points
        cell_fromvalues.insert_Point(123, P_vectA);  // Insert a point between a vector of points incorrectly
        cell_fromvalues.insert_Point(1, P_vectA);  // Insert a point between a vector of points correctly
    

//---------------------------------------------------------------------------------------------------------//
                                        //// Tetrahedron Tests ////
//---------------------------------------------------------------------------------------------------------//

    // Create:
        tetrahedron tetrahedron_fromdefault;    // An empty default tetrahedron
        tetrahedron tetrahedron_fromvalues;     // A tetrahedron with specific individual points
        tetrahedron tetrahedron_fromvector;     // A tetrahedron with points from a vector
        tetrahedron tetrahedron_fromcopier;     // Copy a tetrahedron

    // Obtain fromvalues from a tetrahedron:
        // ID
        // Type
        // Material
        // Vector Points
        // Volume
        // Weight
        // Centre of Gravity
    
    // Set fromvalues of a tetrahedron:
        // ID
        // Type
        // Material
        // Vector Points
        // Volume
        // Weight
        // Centre of Gravity

    // Change points of a tetrahedron:
        // Replace an existing point with a new one
        // ~ Try to add a point to the end of a vector of points ~
        // ~ Try to insert a point between a vector of points ~

    // Calculate for a tetrahedron:
        // The volume
        // The weight
        // The centre of gravity

//---------------------------------------------------------------------------------------------------------//
                                        //// Hexahedron Tests ////
//---------------------------------------------------------------------------------------------------------//

    // Create:
        // An empty default hexahedron
        // A hexahedron with specific individual points
        // A hexahedron with points from a vector

    // Copy a hexahedron

    // Obtain fromvalues from a hexahedron:
        // ID
        // Type
        // Material
        // Vector Points
        // Volume
        // Weight
        // Centre of Gravity
    
    // Set fromvalues of a hexahedron:
        // ID
        // Type
        // Material
        // Vector Points
        // Volume
        // Weight
        // Centre of Gravity

    // Change points of a hexahedron:
        // Replace an existing point with a new one
        // ~ Try to add a point to the end of a vector of points ~
        // ~ Try to insert a point between a vector of points ~

    // Calculate for a hexahedron:
        // The volume
        // The weight
        // The centre of gravity

//---------------------------------------------------------------------------------------------------------//
                                        //// Pyramid Tests ////
//---------------------------------------------------------------------------------------------------------//
    
    // Create:
        // An empty default pyramid
        // A pyramid with specific individual points
        // A pyramid with points from a vector

    // Copy a pyramid

    // Obtain fromvalues from a pyramid:
        // ID
        // Type
        // Material
        // Vector Points
        // Volume
        // Weight
        // Centre of Gravity
    
    // Set fromvalues of a pyramid:
        // ID
        // Type
        // Material
        // Vector Points
        // Volume
        // Weight
        // Centre of Gravity

    // Change points of a pyramid:
        // Replace an existing point with a new one
        // ~ Try to add a point to the end of a vector of points ~
        // ~ Try to insert a point between a vector of points ~

    // Calculate for a pyramid:
        // The volume
        // The weight
        // The centre of gravity

//--end----------------------------------------------------------------------------------------------------//

    return 0;
}
