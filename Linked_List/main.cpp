#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
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
        Node<T>* curr = head;
        int i = 1;
        while (curr) {
            std::cout << "Node #" << i++ << ": " << curr->data << std::endl;
            curr = curr->next;
        }
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
        T max = head->data;
        while (curr != nullptr) {
            max = curr->data > max ? curr->data : max;
            curr = curr->next;
        }
        return max;
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
        if (i == 0) {
            Node<T>* newNode = new Node<T>{ item, curr };
            head = newNode;
        }
        else {
            Node<T>* newNode = new Node<T>{ item, curr };
            previous->next = newNode;
        }
    }

    void deleteNode(T item) {
        if (!head) return;

        Node<T>* curr = head;
        Node<T>* previous = nullptr;

        while (curr) {
            if (curr->data == item) {
                if (!previous) {
                    head = curr->next;
                }
                else {
                    previous->next = curr->next;
                }
                delete curr;
                return;
            }
            previous = curr;
            curr = curr->next;
        }
    }
};


void main() {
    int* items = new int[5];
    items[0] = 75;
    items[1] = 22;
    items[2] = 33;
    items[3] = 44;
    items[4] = 55;    
    LinkedList<int>* linkedList = new LinkedList<int>;
    //head->data = 5;
    //head->next = new Node<int>;
    //head->next->data = 6;
    //linkedList->add_items(items, 5);
    linkedList->display();
    cout << "count = " << linkedList->count() << endl;
    cout << "sum = " << linkedList->sum() << endl;
    cout << "max = " << linkedList->max() << endl;
    cout << "search(44) = " << (linkedList->search(44)? linkedList->search(44)->data : -1) << endl;
    cout << "insert(3,0) " << endl;
    linkedList->insert(3, 0);
    linkedList->display();
    cout << "insert(7,3) " << endl;
    linkedList->insert(7, 3);
    linkedList->display();
    cout << "insert(102,10) " << endl;
    linkedList->insert(102, 10);
    linkedList->display();
    cout << "insert(104,8) " << endl;
    linkedList->insert(104, 7);
    linkedList->display();

    delete linkedList;
    return;
}