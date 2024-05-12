#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "B.h"
#include <stdexcept>

template <typename T, typename U>
class BinaryTree {
private:
    B<U> serverObj;

public:
    BinaryTree() {}  // Конструктор по умолчанию

    void insert(const T& value) {
        try {
            serverObj.insert(value);
        } catch (const std::exception& e) {
            throw std::runtime_error("Ошибка при вставке элемента: " + std::string(e.what()));
        }
    }

    void remove(const T& value) {
        try {
            serverObj.remove(value);
        } catch (const std::exception& e) {
            throw std::runtime_error("Ошибка при удалении элемента: " + std::string(e.what()));
        }
    }

    bool search(const T& value) {
        try {
            return serverObj.search(value);
        } catch (const std::exception& e) {
            throw std::runtime_error("Ошибка при поиске элемента: " + std::string(e.what()));
        }
    }
};

#endif // BINARYTREE_H
