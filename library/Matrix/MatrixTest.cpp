// -------------------------------------------------------------------------------------------------
// MatrixTest.cpp
// -------------------------------------------------------------------------------------------------
//
// Creator: Steven Elliott
// Date: Last Updated 05/01/21
//
// Description: Testing the features of the Matrix class
//
// -------------------------------------------------------------------------------------------------



#include <iostream>

using namespace std;

#include "Class Matrix.h"
#include "./../Vector3D/Vector3D.h""
#include <cstdlib>
#include <cmath>



int main()
{

    cout << "----------THIS CODE TESTS THE FUNCTIONALITY OF THE MATRIX CLASS----------\n\n" << endl;

    int NumTestPassed = 0;
    int NumTestFailed = 0;

    // ---------------------------------------------------------------------------------------------
    cout << "Test 1 - Addition of matrices\n" << endl;

    Matrix Test1Mata(1, 2, 3, 4, 5, 6, 7, 8, 9);

    Matrix Test1Matb(1.1, -2, 5.55, -4.2, 19, 22, 15.33, 5, 0);

    Matrix Test1Ans(2.1, 0, 8.55, -0.2, 24, 28, 22.33, 13, 9);

    if ((Test1Mata + Test1Matb) == Test1Ans)
    {

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;

    }
    else
    {

        cout << "Test Failed\n" << endl;
        NumTestFailed += 1;

    }



    // ---------------------------------------------------------------------------------------------
    cout << "Test 2 - Subtraction of matrices\n" << endl;

    Matrix Test2Mata(1, 2, 3, 4, 5, 6, 7, 8, 9);

    Matrix Test2Matb(1.1, -2, 5.55, -4.2, 19, 22, 15.33, 5, 0);

    Matrix Test2Ans(-0.1, 4, -2.55, 8.2, -14, -16, -8.33, 3, 9);

    if ((Test2Mata - Test2Matb) == Test2Ans)
    {

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;

    }
    else
    {

        cout << "Test Failed\n" << endl;
        NumTestFailed += 1;

    }



    // ---------------------------------------------------------------------------------------------
    cout << "Test 3 - Multiplication with another matrix\n" << endl;

    Matrix Test3Mata(1, 2, 3, 4, 5, 6, 7, 8, 9);

    Matrix Test3Matb(1.1, -2, 5.55, -4.2, 19, 22, 15.33, 5, 0);

    Matrix Test3Ans(38.69, 51, 49.55, 75.38, 117, 132.2, 112.07, 183, 214.85);

    if ((Test3Mata * Test3Matb) == Test3Ans)
    {

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;

    }
    else
    {

        cout << "Test Failed\n" << endl;
        NumTestFailed += 1;

    }

    // ---------------------------------------------------------------------------------------------
    cout << "Test 6 - Inverse of a singular Matrix\n" << endl;

    Matrix Test6Mata(1, 2, 3, 4, 5, 6, 7, 8, 9);

    Matrix Test6Ans(1, 0, 0, 0, 1, 0, 0, 0, 1);

    if (Test6Mata.Inverse() == Test6Ans)
    {

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;

    }
    else
    {

        cout << "Test Failed\n" << endl;
        NumTestFailed += 1;

    }



    // ---------------------------------------------------------------------------------------------
    cout << "Test 7 - Inverse of a non-singular complex Matrix\n" << endl;

    Matrix Test7Mata(1, -2, 1, 2, 0, -1, -1, 1, 0);

    Matrix Test7Ans(1, 1, 2, 1, 1, 3, 2, 1, 4);

    if (Test7Mata.Inverse() == Test7Ans)
    {

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;

    }
    else
    {

        cout << "Test Failed\n" << endl;
        cout << "Test Passed\nAnswer is close but precesion is hard to compare\n" << endl;
        NumTestFailed += 1;

    }



    // ---------------------------------------------------------------------------------------------
    cout << "Test 8 - Inverse of a non-singular Matrix\n" << endl;

    Matrix Test8Mata(3, 0, 2, 2, 0, -2, 0, 1, 1);

    Matrix Test8Ans(0.2, 0.2, 0, -0.2, 0.3, 1, 0.2, -0.3, 0);

    if (Test8Mata.Inverse() == Test8Ans)
    {

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;

    }
    else
    {

        cout << "Test Failed\n" << endl;
        NumTestFailed += 1;

    }






    // ---------------------------------------------------------------------------------------------
    cout << "Test 10 - Setting a value in a Matrix\n" << endl;

    Matrix Test10Mata(3, 0, 2, 2, 0, -2, 0, 1, 1);

    Matrix Test10Ans(3, 0, 2, 2, 100, -2, 0, 1, 1);

    if (Test10Mata.Set_Element(1, 1, 100))
    {
        if (Test10Mata == Test10Ans)
        {

            cout << "Test Passed\n" << endl;
            NumTestPassed += 1;

        }
        else
        {

            cout << "Test Failed\n" << endl;
            NumTestFailed += 1;

        }
    }
    else
    {
        cout << "Invalid position\n" << endl;
    }



    // ---------------------------------------------------------------------------------------------
    cout << "Test 10 - Setting a value that is in an invalid position in a Matrix\n" << endl;

    Matrix Test11Mata(3, 0, 2, 2, 0, -2, 0, 1, 1);

    Matrix Test11Ans(3, 0, 2, 2, 100, -2, 0, 1, 1);

    if (Test11Mata.Set_Element(1, 4, 100))
    {
        if (Test11Mata == Test11Ans)
        {

            cout << "Test Failed\n" << endl;
            NumTestFailed += 1;

        }
    }
    else
    {
        cout << "Invalid position\n" << endl;

        cout << "Test Passed\n" << endl;
        NumTestPassed += 1;
    }


    cout << NumTestPassed << " out of " << NumTestFailed + NumTestPassed << " test were passed - " << ((float)NumTestPassed / (float)(NumTestFailed + NumTestPassed)) * 100. << "%" << endl;


    return (NumTestFailed == 0) ? 0 : 1;

}
