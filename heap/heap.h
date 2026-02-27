#include <algorithm>
#include <iostream>

template<class T>
class Heap {
private:
	T* _heapArray;
	size_t _capacity;
	size_t _size;

    void siftDown(size_t i) {
        while (true) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left >= _size)
                break;

            size_t largest = left;

            if (right < _size && _heapArray[right] > _heapArray[left])
                largest = right;

            if (!(_heapArray[largest] > _heapArray[i]))
                break;

            std::swap(_heapArray[i], _heapArray[largest]);
            i = largest;
        }
    }
    void siftUp(size_t i) {
        while (i > 0) {
            size_t parent = (i - 1) / 2;
            if (!(_heapArray[i] > _heapArray[parent]))
                break;

            std::swap(_heapArray[i], _heapArray[parent]);
            i = parent;
        }
    }

public:
    Heap(const Heap&) = delete;
    Heap& operator=(const Heap&) = delete;
    Heap(size_t capacity)
        : _capacity(capacity), _size(0)
    {
        _heapArray = new T[_capacity];
    }
    ~Heap() {
        delete[] _heapArray;
    }
	bool is_full() const { return _capacity == _size; }
    bool is_empty() const { return _size == 0; }
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }

    bool insert(const T& element) {
        if (is_full()) return false;

        size_t i = _size;
        T temp = element;

        while (i > 0 && temp > _heapArray[(i - 1) / 2]) {
            _heapArray[i] = _heapArray[(i - 1) / 2];
            i = (i - 1) / 2;
        }

        _heapArray[i] = temp;
        _size++;

        return true;
    }

    bool remove(const T& element) {
        size_t i = 0;
        bool found = false;

        while (i < _size) {
            if (_heapArray[i] == element) {
                found = true;
                break;
            }
            i++;
        }

        if (!found)
            return false;

        _heapArray[i] = _heapArray[--_size];

        if (i == _size)
            return true;

        size_t parent = (i - 1) / 2;

        if (i > 0 && _heapArray[i] > _heapArray[parent])
            siftUp(i);
        else
            siftDown(i);

        return true;
    }

    bool inplace_insert(const T* source, size_t n) {
        if (!source) return false;
        if (n > _capacity) return false;

        std::copy_n(source, n, _heapArray);
        _size = n;

        if (_size <= 1)
            return true;

        size_t last = (_size - 2) / 2;
        while (true) {
            siftDown(last);
            if (last == 0) break;
            last--;
        }

        return true;
    }

    bool removeTop(T& out) {
        if (_size == 0) return false;

        out = _heapArray[0];
        _heapArray[0] = _heapArray[--_size];

        if (_size > 0) siftDown(0);
        return true;
    }
    const T* peek() const {
        return (_size == 0) ? nullptr : &_heapArray[0];
    }
    void display() const {
        if (_size == 0) {
            std::cout << "Heap is empty\n";
            return;
        }

        std::cout << "Heap elements: ";
        for (size_t i = 0; i < _size; i++) {
            std::cout << _heapArray[i] << " ";
        }
        std::cout << "\n";
    }
    void displayTree() const {
        if (_size == 0) {
            std::cout << "Heap is empty\n";
            return;
        }

        size_t levelCount = 1;
        size_t index = 0;

        while (index < _size) {
            size_t printed = 0;

            while (printed < levelCount && index < _size) {
                std::cout << _heapArray[index] << " ";
                index++;
                printed++;
            }

            std::cout << "\n";
            levelCount *= 2;
        }
    }
};
