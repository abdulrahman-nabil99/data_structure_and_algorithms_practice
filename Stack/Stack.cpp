#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
class ArrayStack {
private:
    int _size = 0;
    int _index = -1;
    T* _stackArray;
public:
    #pragma region CTRS
    // Constructor
    ArrayStack(int size) {
        _size = size;
        _stackArray = new T[_size];
    }

    // Copy constructor
    ArrayStack(const ArrayStack& other) : _size(other._size), _index(other._index) {
        _stackArray = new T[_size];
        for (int i = 0; i <= _index; ++i)
            _stackArray[i] = other._stackArray[i];
    }

    // Copy assignment
    ArrayStack& operator=(const ArrayStack& other) {
        if (this != &other) {
            delete[] _stackArray;
            _size = other._size;
            _index = other._index;
            _stackArray = new T[_size];
            for (int i = 0; i <= _index; ++i)
                _stackArray[i] = other._stackArray[i];
        }
        return *this;
    }

    ~ArrayStack() {
        delete[] _stackArray;
    }
    #pragma endregion

    #pragma region Methods
    bool push(const T& element) {
        if (isFull()) {
            return false;
        }
        _stackArray[++_index] = element;
        return true;
    }

    bool pop(T& outValue) {
        if (isEmpty()) {
            return false;
        }
        outValue = _stackArray[_index--];
        return true;
    }

    bool peek(T& outValue) const {
        if (isEmpty())
            return false;

        outValue = _stackArray[_index];
        return true;
    }

    bool peekAt(int position, T& outValue) const {
        int target = (_index - position + 1);
        if (_index < 0 || target < 0 || target > _index)
            return false;
        outValue = _stackArray[target];
        return true;
    }

    int size() const {
        return _index + 1;
    }

    bool isEmpty() const {
        return size() == 0;
    }

    bool isFull() const {
        return size() == _size;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        int currentSize = size();
        cout << "[Top] ";
        for (int i = 1; i <= currentSize; i++) {
            T element;
            bool hasValue = peekAt(i, element);
            if (hasValue)
                cout << element;
            if (i != currentSize) {
                cout << " -> ";
            }
        }
        cout << " [Bottom]\n";
        cout << "\n";
    }
    #pragma endregion

};


int main()
{
    cout << "STACK!\n";
    ArrayStack<int> stack(5);
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.display();
}

