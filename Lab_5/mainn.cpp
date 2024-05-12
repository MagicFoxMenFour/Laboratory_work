#include <iostream>
#include "BinaryTree.h"

template 
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Рекурсивная функция для вставки узла
    Node* insertNode(Node* node, const T& value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        } else {
            // Дубликаты игнорируются
            return node;
        }
        return node;
    }

    // Рекурсивная функция для поиска узла
    Node* searchNode(Node* node, const T& value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    // Рекурсивная функция для удаления узла
    Node* removeNode(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = removeNode(node->left, value);
        } else if (value > node->data) {
            node->right = removeNode(node->right, value);
        } else {
            // Узел с одним или без потомков
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Узел с двумя потомками: получаем преемника (наименьший в правом поддереве)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
        return node;
    }

    // Находит узел с минимальным значением в поддереве
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    // Вставка значения
    void insert(const T& value) {
        root = insertNode(root, value);
    }

    // Поиск значения
    bool search(const T& value) {
        return searchNode(root, value) != nullptr;
    }

    // Удаление значения
    void remove(const T& value) {
        root = removeNode(root, value);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");

    BinaryTree<int> intTree; // Дерево для целых чисел

    // Вставка элементов
    intTree.insert(8);
    intTree.insert(3);
    intTree.insert(10);
    intTree.insert(1);
    intTree.insert(6);
    intTree.insert(14);
    intTree.insert(4);
    intTree.insert(7);
    intTree.insert(13);

    // Проверка наличия элементов
    cout << "Поиск элемента 6: " << (intTree.search(6) ? "Найден" : "Не найден") << endl;
    cout << "Поиск элемента 15: " << (intTree.search(15) ? "Найден" : "Не найден") << endl;

    // Удаление элемента
    intTree.remove(10);

    // Повторная проверка наличия элемента
    cout << "Поиск элемента 10 после удаления: " << (intTree.search(10) ? "Найден" : "Не найден") << endl;

    return 0;
}
