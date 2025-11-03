#include <iostream>
#include <stdio.h>

int main()
{
    #pragma region Array Basics
    int A1[5];
    int A2[3] = { 2,4,6 };
    int A3[11] = { 10};
    for (int i = 0; i < sizeof(A1)/sizeof(int); i++) {
        A1[i] = i;
    }
    std::cout << "Size of A3 = ";
    std::cout << sizeof(A3) << std::endl;
    std::cout << "Count of A3 = ";
    std::cout << sizeof(A3) / sizeof(int) << std::endl;
    for (int j : A3) {
        printf("%d\n", j);
    }
    #pragma endregion


    return 0;
}

