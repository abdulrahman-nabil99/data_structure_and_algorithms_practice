#include <iostream>
#include "heap.h"

int main()
{
    Heap<int> h(10);
    h.insert(3);
    h.insert(7);
    h.insert(9);
    h.insert(1);
    h.insert(2);
    h.insert(4);
    h.insert(12);
    h.insert(6);
    h.insert(61);
    h.display();
    h.displayTree();

    h.remove(61);
    h.display();
    h.displayTree();
}
