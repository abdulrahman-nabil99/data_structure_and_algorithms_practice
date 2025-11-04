#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int16_t length;
    int16_t heigth;
    char app;
};

int main()
{
    #pragma region Array Basics
    /*
    int A1[5];
    int A2[3] = { 2,4,6 };
    int A3[11] = { 10};
    for (int i = 0; i < sizeof(A1)/sizeof(int); i++) {
        A1[i] = i;
    }
    cout << "Size of A3 = ";
    cout << sizeof(A3) << endl;
    cout << "Count of A3 = ";
    cout << sizeof(A3) / sizeof(int) << endl;
    for (int j : A3) {
        printf("%d\n", j);
    }
    */
    #pragma endregion

    #pragma region Structures
    Rectangle r1 = { 5,5 };
    cout << "Area of the rectangle (r1: Length = " << r1.length << " Height = " << r1.heigth << ") = ";
    cout << r1.heigth * r1.length << endl;
    cout << "Size of r1 is " << sizeof(r1) << "bytes" << endl;

    #pragma endregion

    return 0;
}
