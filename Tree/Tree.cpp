#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
struct Node {
    T value;
    Node<T>* next;
};
int main()
{
    cout << "Hello World!\n";
}
