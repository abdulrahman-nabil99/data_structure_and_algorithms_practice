#pragma once
#include <iostream>

template<class T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
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

    void preorder(Node<T>* node) const {
        if (!node) return;
        std::cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node<T>* node) const {
        if (!node) return;
        inorder(node->left);
        std::cout << node->value << " ";
        inorder(node->right);
    }

    void postorder(Node<T>* node) const {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->value << " ";
    }

    int count(Node<T>* node) const {
        if (!node) return 0;
        return count(node->left) + count(node->right) + 1;
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
    BinaryTree() {
        _root = nullptr;
    }
    ~BinaryTree() {
        destroy(_root);
        _root = nullptr;
    }
#pragma endregion
#pragma region Methods
    void create_binary_tree() {
        std::cout << "Please Enter The Root Value: ";

        T temp;
        if (!(std::cin >> temp)) {
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
            std::cout << "Enter Left Value For {" << current->value << "}: ";
            std::cin >> leftValue;
            if (leftValue != T{}) {
                current->left = new Node<T>{ leftValue, nullptr, nullptr };
                que.enqueue(current->left);
            }

            // right child
            T rightValue;
            std::cout << "Enter Right Value For {" << current->value << "}: ";
            std::cin >> rightValue;
            if (rightValue != T{}) {
                current->right = new Node<T>{ rightValue, nullptr, nullptr };
                que.enqueue(current->right);
            }
        }
    }
    void preorder() const {
        preorder(_root);
        std::cout << std::endl;
    }

    void i_preorder() {
        if (!_root) return;
        LinkedListStack<Node<T>*> stk;
        Node<T>* current = _root;
        while (current || !stk.isEmpty()) {
            if (current) {
                std::cout << current->value << " ";
                stk.push(current);
                current = current->left;
            }
            else {
                stk.pop(current);
                current = current->right;
            }
        }
        std::cout << std::endl;
    }

    void inorder() const {
        inorder(_root);
        std::cout << std::endl;
    }


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


    void postorder() const {
        postorder(_root);
        std::cout << std::endl;
    }

    void level_order() const {
        if (!_root) {
            std::cout << "Tree is empty\n";
            return;
        }

        LinkedListQueue<Node<T>*> q;
        q.enqueue(_root);

        Node<T>* current;
        while (q.dequeue(current)) {
            std::cout << current->value << " ";

            if (current->left)
                q.enqueue(current->left);

            if (current->right)
                q.enqueue(current->right);
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

    int count() const{
        if (!_root) return 0;
        int nodes_count = count(_root);

        return nodes_count;

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
#pragma endregion

};