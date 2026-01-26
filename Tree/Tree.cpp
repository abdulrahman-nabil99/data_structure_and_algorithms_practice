#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template<class T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
};
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
            cout << current->value;
            if (current->next)
                cout << " -> ";
            current = current->next;
        }
        cout << "\n";
    }
#pragma endregion
};

template<class T>
class BinaryTree {
private:
    Node<T>* _root;
    void destroy(Node<T>* node) {
        if (!node) return;

        destroy(node->left);
        destroy(node->right);

        delete node;
    }

public:
#pragma region CTORS
    BinaryTree(){
        _root = nullptr;
    }
    ~BinaryTree() {
        destroy(_root);
        _root = nullptr;
    }
#pragma endregion
#pragma region Methods
    void create_binary_tree() {
        cout << "Please Enter The Root Value: ";

        T temp;
        if (!(cin >> temp)) {
            return;
        }

        if (temp == T{}) return;

        Node<T>* root = new(std::nothrow) Node<T>;
        if (!root) return;

        root->value = temp;
        root->left = nullptr;
        root->right = nullptr;

        _root = root;
        LinkedListQueue<Node<T>*> que;
        que.enqueue(root);
        Node<T>* current;
        while (que.dequeue(current)) {

            // left child
            T leftValue;
            cout << "Enter Left Value For {" << current->value << "}: ";
            cin >> leftValue;
            if (leftValue != T{}) {
                current->left = new Node<T>{ leftValue, nullptr, nullptr };
                que.enqueue(current->left);
            }

            // right child
            T rightValue;
            cout << "Enter Right Value For {" << current->value << "}: ";
            cin >> rightValue;
            if (rightValue != T{}) {
                current->right = new Node<T>{ rightValue, nullptr, nullptr };
                que.enqueue(current->right);
            }
        }
    }
    void preorder() const {
        preorder(_root);
        cout << endl;
    }

    void preorder(Node<T>* node) const {
        if (!node) return;
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder() const {
        inorder(_root);
        cout << endl;
    }

    void inorder(Node<T>* node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void postorder() const {
        postorder(_root);
        cout << endl;
    }

    void postorder(Node<T>* node) const {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
    void level_order() const {
        if (!_root) {
            cout << "Tree is empty\n";
            return;
        }

        LinkedListQueue<Node<T>*> q;
        q.enqueue(_root);

        Node<T>* current;
        while (q.dequeue(current)) {
            cout << current->value << " ";

            if (current->left)
                q.enqueue(current->left);

            if (current->right)
                q.enqueue(current->right);
        }
        cout << endl;
    }
#pragma endregion

};
int main()
{
    BinaryTree<int> b_tree;
    b_tree.create_binary_tree();
    b_tree.preorder();
    b_tree.level_order();
    b_tree.postorder();
    b_tree.inorder();
}
