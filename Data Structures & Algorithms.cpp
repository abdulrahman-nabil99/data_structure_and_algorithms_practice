#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
    //Rectangle r1 = { 5,5 };
    //cout << "Area of the rectangle (r1: Length = " << r1.length << " Height = " << r1.heigth << ") = ";
    //cout << r1.heigth * r1.length << endl;
    //cout << "Size of r1 is " << sizeof(r1) << "bytes" << endl;

    #pragma endregion

    #pragma region Pointers & Reference
    int* arr = (int*)malloc(5 * sizeof(int));
    int* arr2 = new int[5];
    Rectangle r = { 5,4 };
    int five = 5;
    int *fiveP;
    Rectangle* rP = new Rectangle{ 4,5 };
    Rectangle* rP2 = (Rectangle*)malloc(sizeof(Rectangle));
    rP2->length = 9;
    rP2->heigth = 11;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    fiveP = &five;
    int &fiveR = five;
    int fiveFive = 55;
    fiveR = fiveFive;
    cout << *fiveP << endl;
    cout << arr << endl;
    cout << five << endl;
    cout << rP->length << endl;
    cout << rP2->heigth << endl;

    free(arr);
    free(rP2);
    delete[] arr2;
    delete rP;
    #pragma endregion

    return 0;
}
