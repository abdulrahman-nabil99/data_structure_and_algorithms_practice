#pragma once
#include <iostream>
template<class T>
struct QueueNode
{
    QueueNode<T>* next;
    T value;
};
template<class T>
class LinkedListQueue {
private:
    QueueNode<T>* _head;
    QueueNode<T>* _rear;
public:
#pragma region CTORS
    LinkedListQueue() : _head(nullptr), _rear(nullptr) {}

    ~LinkedListQueue() {
        while (_head) {
            QueueNode<T>* temp = _head;
            _head = _head->next;
            delete temp;
        }
    }

    LinkedListQueue(const LinkedListQueue&) = delete;
    LinkedListQueue& operator=(const LinkedListQueue&) = delete;
#pragma endregion

#pragma region Methods
    bool is_full() const {
        QueueNode<T>* item = new(std::nothrow) QueueNode<T>;
        if (!item) return true;
        delete item;
        return false;
    }
    bool is_empty() const {
        return _head == nullptr;
    }
    bool enqueue(const T& item) {
        QueueNode<T>* node = new(std::nothrow) QueueNode<T>;
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

        QueueNode<T>* front = _head;
        outValue = front->value;
        _head = _head->next;

        if (!_head)
            _rear = nullptr;

        delete front;
        return true;
    }

    QueueNode<T>* front() {
        return _head;
    }

    void display() const {
        if (is_empty()) {
            std::cout << "Queue is empty\n";
            return;
        }

        QueueNode<T>* current = _head;
        while (current) {
            std::cout << current->value;
            if (current->next)
                std::cout << " -> ";
            current = current->next;
        }
        std::cout << "\n";
    }
#pragma endregion
};