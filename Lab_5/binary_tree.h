#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T>* root;

    void destroyTree(BinaryTreeNode<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(T value) {
        if (!root) {
            root = new BinaryTreeNode<T>(value);
            return;
        }

        BinaryTreeNode<T>* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left) {
                    current = current->left;
                } else {
                    current->left = new BinaryTreeNode<T>(value);
                    return;
                }
            } else {
                if (current->right) {
                    current = current->right;
                } else {
                    current->right = new BinaryTreeNode<T>(value);
                    return;
                }
            }
        }
    }

    // You can implement other methods like search, delete, etc.

    void printInOrder(BinaryTreeNode<T>* node) {
        if (node) {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void printInOrderTraversal() {
        printInOrder(root);
        std::cout << std::endl;
    }
};

#endif // BINARY_TREE_H
