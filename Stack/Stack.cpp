#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
struct Node {
    T value;
    Node<T>* next;
};

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

template<class T>
class LinkedListStack {
private:
    Node<T>* _top;

public:
    #pragma region CTORS
    LinkedListStack() : _top(nullptr) {}

    ~LinkedListStack() {
        while (_top) {
            Node<T>* temp = _top;
            _top = _top->next;
            delete temp;
        }
    }

    LinkedListStack(const LinkedListStack&) = delete;
    LinkedListStack& operator=(const LinkedListStack&) = delete;
    #pragma endregion

    #pragma region Methods
    bool push(const T& element) {
        Node<T>* item = new(std::nothrow) Node<T>;
        if (!item) return false;

        item->value = element;
        item->next = _top;
        _top = item;

        return true;
    }

    bool pop(T& outValue) {
        if (isEmpty()) return false;

        Node<T>* item = _top;
        _top = _top->next;

        outValue = item->value;
        delete item;

        return true;
    }

    bool isFull() const {
        Node<T>* item = new(std::nothrow) Node<T>;
        if (!item) return true;
        delete item;
        return false;
    }

    bool isEmpty() const{
        return _top == nullptr;
    }

    bool peek(T& outValue) const {
        if (isEmpty())
            return false;

        outValue = _top->value;
        return true;
    }

    bool peekAt(int position, T& outValue) const {
        if (position <= 0) return false;

        Node<T>* current = _top;
        int i = 1;

        while (current) {
            if (i == position) {
                outValue = current->value;
                return true;
            }
            current = current->next;
            i++;
        }

        return false;
    }
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node<T>* current = _top;
        cout << "[Top] ";
        while (current) {
            cout << current->value;
            current = current->next;
            if (current)
                cout << " -> ";
        }
        cout << " [Bottom]\n";
    }
    #pragma endregion
};

int main()
{
    cout << "ARRAY STACK!\n";
    ArrayStack<int> stack(5);
    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.display();

    cout << "LINKEDLIST STACK!\n";
    LinkedListStack<int> linkedStack;
    linkedStack.push(1);
    linkedStack.push(3);
    linkedStack.push(5);
    linkedStack.push(6);
    int value;
    linkedStack.pop(value);
    linkedStack.push(7);
    linkedStack.display();
    linkedStack.peekAt(3, value);
    cout << "PEAK AT (3) = " << value << endl;
}

