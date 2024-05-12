#include <iostream>
#include <string>
#include "binary_tree.h" 

using namespace std;

int main() {
    BinaryTree<int> intTree; 
    BinaryTree<string> stringTree;

    int intArr[] = { 5, 2, 8, 1, 4, 9, 7, 3, 6 };
    string strArr[] = { "apple", "banana", "orange", "grape", "kiwi" };

    // Вставляем целые числа из массива в дерево
    for (int i = 0; i < sizeof(intArr) / sizeof(int); i++) {
        intTree.insert(intArr[i]); 
    }

    // Вставляем строки из массива в дерево
    for (int i = 0; i < sizeof(strArr) / sizeof(string); i++) {
        stringTree.insert(strArr[i]); 
    }

    // Выводим отсортированные значения с помощью итератора
    cout << "Отсортированные целые числа: ";
    for (auto it = intTree.begin(); it != intTree.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Отсортированные строки: ";
    for (auto it = stringTree.begin(); it != stringTree.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
