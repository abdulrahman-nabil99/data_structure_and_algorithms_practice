#pragma once
#include <algorithm> 
#include <new>
#include <iostream>

template<class T>
struct AVLNode {
    T value;
    int height;
    AVLNode<T>* left;
    AVLNode<T>* right;
};

template<class T>
class AVLTree {
private:
    AVLNode<T>* _root = nullptr;

    void destroy(AVLNode<T>* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    static int h(AVLNode<T>* n) { return n ? n->height : 0; }

    static void update_height(AVLNode<T>* n) {
        if (!n) return;
        n->height = 1 + std::max(h(n->left), h(n->right));
    }

    static int balance_factor(AVLNode<T>* n) {
        return n ? (h(n->left) - h(n->right)) : 0;
    }

    // Basic rotations (return new subtree root)
    static AVLNode<T>* rotate_right(AVLNode<T>* y) { // LL fix
        AVLNode<T>* x = y->left;
        AVLNode<T>* T2 = x->right;

        x->right = y;
        y->left = T2;

        update_height(y);
        update_height(x);
        return x;
    }

    static AVLNode<T>* rotate_left(AVLNode<T>* x) { // RR fix
        AVLNode<T>* y = x->right;
        AVLNode<T>* T2 = y->left;

        y->left = x;
        x->right = T2;

        update_height(x);
        update_height(y);
        return y;
    }

    static AVLNode<T>* ll_rotation(AVLNode<T>* node) { 
        return rotate_right(node); 
    }

    static AVLNode<T>* rr_rotation(AVLNode<T>* node) { 
        return rotate_left(node); 
    }

    static AVLNode<T>* lr_rotation(AVLNode<T>* node) { // Left-Right
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    static AVLNode<T>* rl_rotation(AVLNode<T>* node) { // Right-Left
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    AVLNode<T>* insert_rec(AVLNode<T>* node, const T& value, bool& inserted) {
        if (!node) {
            auto* newNode = new(std::nothrow) AVLNode<T>{ value, 1, nullptr, nullptr };
            inserted = (newNode != nullptr);
            return newNode;
        }

        if (value == node->value) {
            inserted = false;
            return node;
        }

        if (value < node->value)
            node->left = insert_rec(node->left, value, inserted);
        else
            node->right = insert_rec(node->right, value, inserted);

        if (!inserted) return node; 

        update_height(node);
        int bf = balance_factor(node);

        if (bf > 1 && value < node->left->value)        return ll_rotation(node); // LL
        if (bf > 1 && value > node->left->value)        return lr_rotation(node); // LR
        if (bf < -1 && value > node->right->value)      return rr_rotation(node); // RR
        if (bf < -1 && value < node->right->value)      return rl_rotation(node); // RL

        return node;
    }

    void pretty_print(AVLNode<T>* node, int space) const {
        if (!node) return;

        const int INDENT = 6;
        space += INDENT;

        // Print right subtree first
        pretty_print(node->right, space);

        // Print current node
        std::cout << std::endl;
        for (int i = INDENT; i < space; i++)
            std::cout << ' ';

        std::cout << node->value << "(h=" << node->height << ")";

        // Print left subtree
        pretty_print(node->left, space);
    }

public:
    AVLTree() = default;
    ~AVLTree() {
        destroy(_root);
        _root = nullptr;
    }

    bool i_insert(const T value) {
        bool inserted = false;
        _root = insert_rec(_root, value, inserted);
        return inserted;
    }

    void display_pretty() const {
        if (!_root) {
            std::cout << "[empty tree]\n";
            return;
        }
        pretty_print(_root, 0);
        std::cout << "\n";
    }
};
