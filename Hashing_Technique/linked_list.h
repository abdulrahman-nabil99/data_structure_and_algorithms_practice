#pragma once
#include <iostream>

template<class T>
struct Node {
    T data;
    Node* next = nullptr;
};

template<class T>
class LinkedList {
private:
    Node<T>* head = nullptr;

public:
    ~LinkedList() {
        Node<T>* curr = head;
        while (curr) {
            Node<T>* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }

    void add_items(T* items, int size) {
        for (int i = 0; i < size; i++) {
            Node<T>* newNode = new Node<T>{ items[i], nullptr };

            if (!head) {
                head = newNode;
            }
            else {
                Node<T>* curr = head;
                while (curr->next) curr = curr->next;
                curr->next = newNode;
            }
        }
    }

    void display() {
        if (!head) return;
        Node<T>* curr = head;
        int i = 1;
        do {
            std::cout << "Node #" << i++ << ": " << curr->data << ", ";
            curr = curr->next;
        } while (curr && curr != head);
        std::cout << std::endl;
    }

    int count() {
        if (!head) return 0;
        Node<T>* curr = head;
        int counter = 0;
        while (curr != nullptr) {
            counter++;
            curr = curr->next;
        }
        return counter;
    }

    T sum() {
        Node<T>* curr = head;
        T total = T();
        if (!head) return total;

        while (curr != nullptr) {
            total += curr->data;
            curr = curr->next;
        }

        return total;
    }

    T max() {
        Node<T>* curr = head;
        if (!head) return T();

        T maxVal = head->data;
        while (curr != nullptr) {
            maxVal = curr->data > maxVal ? curr->data : maxVal;
            curr = curr->next;
        }
        return maxVal;
    }

    const Node<T>* search(const T& item) const {
        const Node<T>* curr = head;
        while (curr) {
            if (curr->data == item)
                return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    void insert(T item, int index) {
        if (index < 0) return;

        Node<T>* curr = head;
        Node<T>* previous = nullptr;
        int i = 0;
        int size = count();

        while (i < index && i < size) {
            previous = curr;
            curr = curr->next;
            i++;
        }

        Node<T>* newNode = new Node<T>{ item, curr };

        if (i == 0)
            head = newNode;
        else
            previous->next = newNode;
    }

    void insert_sorted(T item) {
        Node<T>* newNode = new Node<T>{ item, nullptr };

        if (!head || item < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node<T>* curr = head;

        while (curr->next && curr->next->data < item) {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void delete_node(T item) {
        if (!head) return;

        Node<T>* curr = head;
        Node<T>* previous = nullptr;

        while (curr) {
            if (curr->data == item) {
                if (!previous)
                    head = curr->next;
                else
                    previous->next = curr->next;

                delete curr;
                return;
            }

            previous = curr;
            curr = curr->next;
        }
    }

    bool is_linear() {
        if (!head || !head->next) return true;

        Node<T>* singlePtr = head;
        Node<T>* doublePtr = head;

        do {
            singlePtr = singlePtr->next;
            doublePtr = doublePtr->next;
            doublePtr = doublePtr ? doublePtr->next : doublePtr;
        } while (singlePtr && doublePtr && singlePtr != doublePtr);

        return singlePtr != doublePtr;
    }

    bool is_circular() {
        if (!head) return false;

        Node<T>* current = head;
        while (current) {
            current = current->next;

            if (current == head)
                return true;
        }

        return false;
    }
};