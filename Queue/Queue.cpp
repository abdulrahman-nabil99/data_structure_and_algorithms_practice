#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
class ArrayQueue
{
private:
	T* _items;
	size_t _size = 0;
	int _rear = -1;

public:
	#pragma region CTRs
	ArrayQueue(size_t size) : _size(size){
		_items = new T[_size];
	}
    // Copy constructor
    ArrayQueue(const ArrayQueue& other) : _size(other._size), _rear(other._rear) {
        _items = new T[_size];
        for (int i = 0; i <= _rear; ++i)
            _items[i] = other._items[i];
    }

    // Copy assignment
    ArrayQueue& operator=(const ArrayQueue& other) {
        if (this != &other) {
            delete[] _items;
            _size = other._size;
            _rear = other._rear;
            _items = new T[_size];
            for (int i = 0; i <= _rear; ++i)
                _items[i] = other._items[i];
        }
        return *this;
    }

	~ArrayQueue() {
		delete[]_items;
	}

    void shift_elements() {
        for (int i = 0; i < _rear; i++) 
            _items[i] = _items[i + 1];
        _rear--;
    }
	#pragma endregion

    #pragma region Methods
    bool enqueue(const T& element) {
        if (is_full()) {
            return false;
        }
        _items[++_rear] = element;
        return true;
    }
    bool dequeue(T& outValue) {
        if (is_empty()) {
            return false;
        }
        outValue = _items[0];
        shift_elements();
        return true;
    }
    bool is_full() const {
        return _size == _rear + 1;
    }
    bool is_empty() const {
        return _rear < 0;
    }

    void display() const
    {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i <= _rear; ++i) {
            cout << _items[i] << " ";
        }
        cout << "\n";
    }
    #pragma endregion

};

template<class T>
class CircularQueue
{
private:
    T* _items;
    size_t _capacity;
    size_t _count;
    size_t _front;
    size_t _rear;

public:
#pragma region CTRs

    explicit CircularQueue(size_t capacity)
        : _capacity(capacity), _count(0), _front(0), _rear(0)
    {
        _items = new T[_capacity];
    }

    // Copy constructor
    CircularQueue(const CircularQueue& other)
        : _capacity(other._capacity),
        _count(other._count),
        _front(other._front),
        _rear(other._rear)
    {
        _items = new T[_capacity];
        for (size_t i = 0; i < _capacity; ++i)
            _items[i] = other._items[i];
    }

    // Copy assignment
    CircularQueue& operator=(const CircularQueue& other)
    {
        if (this != &other) {
            delete[] _items;
            _capacity = other._capacity;
            _count = other._count;
            _front = other._front;
            _rear = other._rear;
            _items = new T[_capacity];
            for (size_t i = 0; i < _capacity; ++i)
                _items[i] = other._items[i];
        }
        return *this;
    }

    ~CircularQueue() {
        delete[] _items;
    }

#pragma endregion

#pragma region Methods

    bool enqueue(const T& value)
    {
        if (is_full())
            return false;

        _items[_rear] = value;
        _rear = (_rear + 1) % _capacity;
        ++_count;
        return true;
    }

    bool dequeue(T& outValue)
    {
        if (is_empty())
            return false;

        outValue = _items[_front];
        _front = (_front + 1) % _capacity;
        --_count;
        return true;
    }

    bool is_empty() const {
        return _count == 0;
    }

    bool is_full() const {
        return _count == _capacity;
    }

    size_t size() const {
        return _count;
    }

    size_t capacity() const {
        return _capacity;
    }

    void display() const
    {
        if (is_empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (size_t i = 0; i < _count; ++i) {
            size_t index = (_front + i) % _capacity;
            cout << _items[index] << " ";
        }
        cout << "\n";
    }

#pragma endregion
};

template<class T>
struct Node
{
    Node<T>* next;
    T value;
};
template<class T>
class LinkedListQueue {
private:
    Node<T>* _head;
    Node<T>* _rear;
public:
    #pragma region CTORS
    LinkedListQueue() : _head(nullptr), _rear(nullptr) {}

    ~LinkedListQueue() {
        while (_head) {
            Node<T>* temp = _head;
            _head = _head->next;
            delete temp;
        }
    }

    LinkedListQueue(const LinkedListQueue&) = delete;
    LinkedListQueue& operator=(const LinkedListQueue&) = delete;
    #pragma endregion

    #pragma region Methods
    bool is_full() const {
        Node<T>* item = new(std::nothrow) Node<T>;
        if (!item) return true;
        delete item;
        return false;
    }
    bool is_empty() const {
        return _head == nullptr;
    }
    bool enqueue(const T& item) {
        Node<T>* node = new(std::nothrow) Node<T>;
        if (!node) return false;
        node->value = item;
        node->next = nullptr;
        if (!_head) {
            _head = _rear = node;
        }
        else {
            _rear->next = node;
            _rear = _rear->next;
        }
        return true;
    }
    bool dequeue(T& outValue) {
        if (is_empty())
            return false;

        Node<T>* front = _head;
        outValue = front->value;
        _head = _head->next;

        if (!_head)
            _rear = nullptr;

        delete front;
        return true;
    }

    void display() const {
        if (is_empty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        Node<T>* current = _head;
        while (current) {
            cout << current->value;
            if (current->next)
                cout << " -> ";
            current = current->next;
        }
        cout << "\n";
    }
    #pragma endregion
};

int main()
{
    cout << "Queue!!\n";
    LinkedListQueue<int> que;

    int value;
    que.enqueue(11);
    que.enqueue(12);
    que.enqueue(13);
    que.enqueue(14);
    que.dequeue(value);
    que.dequeue(value);

    que.display();
}
