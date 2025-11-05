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

void print_array(int [], int);
void swap_int(int&, int&);
void swap_int_pointer(int*, int*);
int* create_int_array(int);
int calculate_rectangle_area(Rectangle);
void update_rectanle_dimensions(Rectangle*, int, int);

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
    //int* arr = (int*)malloc(5 * sizeof(int));
    //int* arr2 = new int[5];
    //Rectangle r = { 5,4 };
    //int five = 5;
    //int *fiveP;
    //Rectangle* rP = new Rectangle{ 4,5 };
    //Rectangle* rP2 = (Rectangle*)malloc(sizeof(Rectangle));
    //rP2->length = 9;
    //rP2->heigth = 11;
    //arr[0] = 1;
    //arr[1] = 2;
    //arr[2] = 3;
    //arr[3] = 4;
    //arr[4] = 5;
    //fiveP = &five;
    //int &fiveR = five;
    //int fiveFive = 55;
    //fiveR = fiveFive;
    //cout << *fiveP << endl;
    //cout << arr << endl;
    //cout << five << endl;
    //cout << rP->length << endl;
    //cout << rP2->heigth << endl;

    //free(arr);
    //free(rP2);
    //delete[] arr2;
    //delete rP;
    #pragma endregion

    #pragma region Functions
    Rectangle r = { 3,5 };
    update_rectanle_dimensions(&r, 7, 8);
    cout << calculate_rectangle_area(r) << endl;
    int intArr[] = { 1,5,3,4,8 };
    int length = sizeof(intArr) / sizeof(intArr[0]);
    print_array(intArr, length);
    int custArr = 8;
    int* mArr = create_int_array(custArr);
    print_array(mArr,custArr);
    int x = 5, y = 6;
    cout << "Before swap" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    swap_int(x, y);
    swap_int_pointer(&x, &y);
    cout << "After swap" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    free(mArr);
    #pragma endregion

    return 0;
}

void print_array(int int_arr[], int length)
{
    cout << "[";
    for (int i = 0; i < length; i++) {
        cout << int_arr[i];
        if (i != length - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void swap_int(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_int_pointer(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* create_int_array(int length)
{
    int* arr = (int*) malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        arr[i] = 0;
    }
    return arr;
}

int calculate_rectangle_area(Rectangle r) {
    return r.heigth * r.length;
}

void update_rectanle_dimensions(Rectangle* r, int length, int height) {
    r->length = length;
    r->heigth = height;
    cout << "Rectangle New Dimensions Are: length = " << r->length << ", height = " << r->heigth << endl;
}