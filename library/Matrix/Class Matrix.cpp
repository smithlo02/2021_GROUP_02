
#include "Matrix class.h by Tan.h"
#include "Vector3D.h from Shiyu.h"


#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846



Matrix::Matrix() {

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            if (i == j) {

                this->MatrixArray[i][j] = 1;
            }
            else {

                this->MatrixArray[i][j] = 0;
            }
        }
    }
    return;
}

// -------------------------------------------------------------------------------------------------
// Constructor to input each value in a 3x3 matrix

Matrix::Matrix(double a, double b, double c,double d, double e, double f,double g, double h, double i) {

    double elements[] = { a, b, c, d, e, f, g, h, i };

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = elements[(i * 3) + j];

        }
    }

    return;
}

// -------------------------------------------------------------------------------------------------
// Matrix copy constructor

Matrix::Matrix(const Matrix& Mat) {

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = Mat.MatrixArray[i][j];

        }

    }

    return;

}





Matrix& Matrix::operator=(const Matrix& Mat) {

    if (&Mat == this) return(*this);

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = Mat.MatrixArray[i][j];

        }

    }

    return(*this);

}



/

Matrix Matrix::operator+(const Matrix &Mat)
{
    Matrix Addition(3,3,0.0);
	unsigned i, j;

    for (i = 0;i < 3; i++) {

        for (j = 0; j < 3; j++) {

            Addition(i, j, this->MatrixArray[i][j] + Mat(i,j);

        }
    }

    return Addition;
}



// -------------------------------------------------------------------------------------------------
// Matrix subtraction operator to subtract 2 matrices

Matrix Matrix::operator-(const Matrix& Mat)
{
    Matrix Subtraction(3,3,0.0);

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            Subtraction(i, j, this->MatrixArray[i][j] - Mat(i,j);

        }
    }

    return Subtraction;
}



// -------------------------------------------------------------------------------------------------
// Matrix multiplication operator (with another 3x3 matix)

Matrix Matrix::operator*(const Matrix& Mat)
{
    Matrix Multiple(3,3,0.0);
    unsigned i, j, k;

    double temp = 0.0;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            temp = 0.0;

            for (k = 0; k < 3; k++) {

                temp += this->MatrixArray[i][k] * Mat(k,j);

            }

            Multiple(i, j, temp);

        }

    }

    return Multiple;

}



Vector3D Matrix::operator*(const Vector3D& Vec)
{
    Vector3D MultVec;

    double TempVecArray[3];

    unsigned i;

    for (i = 0; i < 3; i++) {

    
        double TempValue = (Vec.X_coordinate* this->MatrixArray[i][0]
            + Vec.Y_coordinate * this->MatrixArray[i][1]
            + Vec.Z_coordinate * this->MatrixArray[i][2]);

        TempVecArray[row] = TempValue;

    }

    
    MultVec.X_coordinate = TempVecArray[0];
    MultVec.Y_coordinate= TempVecArray[1];
    MultVec.Z_coordinate = TempVecArray[2];

    return MultVec;
}


Matrix Matrix::operator*(double Scalar)
{
    Matrix MultMat(3,3,0.0);

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            MulMat(i, j, this->MatrixArray[i][j] * Scalar);

        }

    }

    return MultMat;
}



Matrix Matrix::Inverse()
{

    // Error check to make sure the matrix is not singular i.e. Determinant = 0
    double Det = this->Determinant();


    // If the matrix is singular the identity matrix is returned
    if (Det == 0)
    {
        // Identity matrix
        Matrix Mat;

        return Mat;
    }


    
    Matrix InverseMat((this->MatrixArray[1][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[1][2]),

        (this->MatrixArray[1][0] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][0] * this->MatrixArray[1][2]),

        (this->MatrixArray[1][0] * this->MatrixArray[2][1])
        - (this->MatrixArray[2][0] * this->MatrixArray[1][1]),

        (this->MatrixArray[0][1] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][1] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[2][2])
        - (this->MatrixArray[2][0] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[2][1])
        - (this->MatrixArray[2][0] * this->MatrixArray[0][1]),

        (this->MatrixArray[0][1] * this->MatrixArray[1][2])
        - (this->MatrixArray[1][1] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[1][2])
        - (this->MatrixArray[1][0] * this->MatrixArray[0][2]),

        (this->MatrixArray[0][0] * this->MatrixArray[1][1])
        - (this->MatrixArray[1][0] * this->MatrixArray[0][1]));




    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            if ((((i* 3) + j) % 2) == 1) {

                // Declare Value and pass a pointer so GetElement can update its value
                double Value;
                InverseMat.GetElement(i, j, &Value);

                InverseMat.SetElement(i, j, (Value * -1));

            }

        }
    }

    // Transpose the matrix
    InverseMat = InverseMat.Transpose();

    // Divide by the determinant
    InverseMat = InverseMat * ((double)1 / Det);

    return InverseMat;

}




Matrix Matrix::Transpose()
{
    Matrix Transpose;

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            Transpose(i, j, this->MatrixArray[i][j]);

        }

    }

    return Transpose;

}


void Matrix::RotateX(double Theta) {
    this->SetMatrix(1, 0, 0,
	      0, cos((Theta * PI) / 180), -sin((Theta * PI) / 180),
		  0, sin((Theta * PI) / 180),cos((Theta * PI) / 180));

}



void Matrix::RotateY(double Theta) {

    this->SetMatrix(cos((Theta * PI) / 180), 0, sin((Theta * PI) / 180),
          0, 1,  0, 
		  -sin((Theta * PI) / 180), 0,cos((Theta * PI) / 180));

}


void Matrix::RotateZ(double Theta) {

    this->SetMatrix(cos((Theta * PI) / 180), -sin((Theta * PI) / 180),  0,
        sin((Theta * PI) / 180),cos((Theta * PI) / 180),0,
	    0, 0, 1);

}


void Matrix::SetMatrix(double a, double b, double c, double d, double e, double f, double g, double h, double i) {

    double elements[] = { a, b, c, d, e, f, g, h, i };

    unsigned i, j;

    for (i = 0; i < 3; i++) {

        for (j = 0; j < 3; j++) {

            this->MatrixArray[i][j] = elements[(i * 3) + j];

        }
    }
}


void Matrix::OutputMatrix() {
   
    unsigned i, j;

    for (i = 0; i < 3; 	i++) {

        for (j = 0; j < 3; j++) {

            if (i == j) {
            	
            	cout<< "Matrix" <<endl;
                cout << this->MatrixArray[i][j] <<endl;
            }
            else {

                cout<<w "error" <<endl;
            }
        }
    }
    return;
}





