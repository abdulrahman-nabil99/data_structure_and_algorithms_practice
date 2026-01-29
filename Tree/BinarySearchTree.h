#pragma once
#include <iostream>

template<class T>
class BinarySearchTree {
private:
    Node<T>* _root;
    void destroy(Node<T>* node) {
        if (!node) return;

        destroy(node->left);
        destroy(node->right);

        delete node;
    }

    int height(Node<T>* node) const {
        int lh, rh;
        if (!node) return 0;
        lh = height(node->left);
        rh = height(node->right);
        if (lh > rh)
            return lh + 1;
        return rh + 1;
    }

public:
#pragma region CTORS
    BinarySearchTree() {
        _root = nullptr;
    }
    ~BinarySearchTree() {
        destroy(_root);
        _root = nullptr;
    }
#pragma endregion
#pragma region Methods
    void i_inorder() {
        if (!_root) return;
        LinkedListStack<Node<T>*> stk;
        Node<T>* current = _root;
        while (current || !stk.isEmpty()) {
            if (current) {
                stk.push(current);
                current = current->left;
            }
            else {
                stk.pop(current);
                std::cout << current->value << " ";
                current = current->right;
            }
        }
        std::cout << std::endl;
    }
    int i_count() const {
        if (!_root) return 0;

        int nodesCount = 0;
        LinkedListQueue<Node<T>*> q;

        q.enqueue(_root);

        Node<T>* current;
        while (q.dequeue(current)) {
            nodesCount++;

            if (current->left)
                q.enqueue(current->left);

            if (current->right)
                q.enqueue(current->right);
        }

        return nodesCount;
    }

    int height() const {
        if (!_root) return 0;
        int tree_level = height(_root);
        return tree_level;
    }

    int i_leaf_nodes() const {
        if (!_root) return 0;

        int nodesCount = 0;
        LinkedListQueue<Node<T>*> q;

        q.enqueue(_root);

        Node<T>* current;
        while (q.dequeue(current)) {
            if (!current->left && !current->right) {
                nodesCount++;
                continue;
            }

            if (current->left)
                q.enqueue(current->left);

            if (current->right)
                q.enqueue(current->right);
        }

        return nodesCount;
    }

    int i_internal_nodes() const {
        if (!_root) return 0;

        int nodesCount = 0;
        LinkedListQueue<Node<T>*> q;

        q.enqueue(_root);

        Node<T>* current;
        while (q.dequeue(current)) {
            if (current->right || current->left) {
                nodesCount++;
            }

            if (current->left)
                q.enqueue(current->left);

            if (current->right)
                q.enqueue(current->right);
        }

        return nodesCount;
    }

    bool i_insert(const T value) {
        Node<T>* current = _root;
        Node<T>* parent = nullptr;

        while (current) {
            parent = current;

            if (value == current->value)
                return false;

            current = (value > current->value) ? current->right : current->left;
        }

        Node<T>* newNode = new(std::nothrow) Node<T>{ value, nullptr, nullptr };
        if (!newNode) return false;

        if (!parent) {
            _root = newNode;
        }
        else if (value > parent->value) {
            parent->right = newNode;
        }
        else {
            parent->left = newNode;
        }

        return true;
    }

    bool i_search(const T value, T& outValue) const {
        Node<T>* current = _root;

        while (current) {
            if (current->value == value) {
                outValue = current->value;
                return true;
            }
            current = (value > current->value) ? current->right : current->left;
        }

        return false;
    }

    bool i_min(T& outValue) const {
        if (!_root)
            return false;

        Node<T>* current = _root;
        while (current->left)
            current = current->left;

        outValue = current->value;
        return true;
    }

    bool i_max(T& outValue) const {
        if (!_root)
            return false;

        Node<T>* current = _root;
        while (current->right)
            current = current->right;

        outValue = current->value;
        return true;
    }
#pragma endregion

};