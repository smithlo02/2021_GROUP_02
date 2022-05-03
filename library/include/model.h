#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <vector3d.h>
#include <material.h>
#include <cell.h>
#include <memory>

/** @file
* The source file for the model class declarations
*/


class Model
{
    friend class ModelRender;

public:

    void Read_from_A_file(const string &fileName);  //function to Read VTk style data from a file

    void Write_to_A_file(const string &fileName);   //function to write VTK style data to a file 

    /** Vertices Parser
    * A function to parse the vertices from a line of a .mod file that begins with "v" indicating a vector
    * The vector is push_back into a vector array
    */
    void vertices_parser(const string &dataline);   //function to parse the vertices and push_back into a vector array

    /** Material Parser
    * A function to parse the material information from a line of a .mod file that begins with "m" indicating a material
    * The material is push_back into a material array
    */
    void material_parser(const string &dataline);   //function to parse the materials and push_back into a material array 

    /** Cell Parser
    * A function to parse the cell information from a line of a .mod file that begins with "c" indicating a cell
    * The cell is push_back into a cell array
    * This funtion is only used for cells of index < 10
    */
    void cell_parser(const string &dataline);       //function to parse the cells of index<10 and push_back into a cell array   

    /** Cell Parser
    * A function to parse the cell information from a line of a .mod file that begins with "c" indicating a cell
    * The cell is push_back into a cell array
    * This funtion is only used for cells of 10 < index < 100
    */
    void cell_parser_index_greater_than_10(const string &dataline);   //function to parse the cells of index >=10 and push_back into a cell array 

    /** Cell Parser
    * A function to parse the cell information from a line of a .mod file that begins with "c" indicating a cell
    * The cell is push_back into a cell array
    * This funtion is only used for cells of index > 100
    */
    void cell_parser_index_greater_than_100(const string &dataline);   //function to parse the cells of index >=100 and push_back into a cell array 

    /** Get number of materials
    * A method to get the number of materials in the model
    */
    int get_material_num()const;   //function to get the number of materials 

    /** Get number of vertices
    * A method to get the number of vertices in the model
    */
    int get_vertex_num()const;    //function to get the number of the vertices

    /** Get number of cells
    * A method to get the number of cells within the model
    */
    int get_Cell_num()const;      //function to get the number of the cells

    /** Get type of cell
    * A function to get the type of cell at a specified index that is passed as an integer
    */
    char get_cell_type(const int &cell_ID)const;   //function to get the type of a cell of a specified ID
    
    /** Get vector coordinates of the center of a cell
    * A function to get the vector coordinates at the center of a cell specified with its index that is passed as an integer
    */
    vector3D get_center(const int &cell_ID)const;   //function to get the center of a cell of a specified ID

    /** Get the vertices of a cell
    * A function that gets the vertices of a cell whos index is specified as an integer passed to it
    * The returned value is a pointer to the first vertices within the array of vertices for the cell
    */
    vector3D* get_vertices(const int &cell_ID); //function to get the all the vertices of a cell of a specified ID


private:
    /** Array to store vector points
    * A c++ vector array to store the vectors in the model
    */
    vector<vector3D> points; //array to store vertices

    /** Array to store the materials
    * A c++ vector array that stores the materials that are in the model
    */
    vector<Material> Materials;  //array to store materials 

    /** Array to store the cells
    * A c++ vector array that stores the cells that are in the model
    */
    vector<unique_ptr<Cell>> Cells;    //array to store cells 
};
#endif 
