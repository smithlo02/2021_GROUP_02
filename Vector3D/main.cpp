#include <iostream>
#include"Vector3D2.h"

int main()
{
    vector a,b,c;

    //set the vector
    a.set_vector(22, 88, -1.2);
    b.set_vector(88, 39.79, 4.78);

    //get the vector values
    c = a.get_vector();

    //print the vector
    c.display_vector();

    //operation
    std::cout << "a+b=";

    //addition
    (a + b).display_vector();

    //subtraction
    std::cout << "b-c=";
    (b - c).display_vector();

    //inner product
    std::cout << "a*b=";
    (a * b).display_vector();

    //outer product
    std::cout << "a^b=";
    (a ^ b).display_vector();


}
