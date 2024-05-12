#ifndef B_H
#define B_H

#include <iostream>

template <typename T>
class B {
public:
    void insert(const T& value) {
        std::cout << "Вставка элемента " << value << " в объект B" << std::endl;
        // Реализация вставки
    }

    void remove(const T& value) {
        std::cout << "Удаление элемента " << value << " из объекта B" << std::endl;
        // Реализация удаления
    }

    bool search(const T& value) {
        std::cout << "Поиск элемента " << value << " в объекте B" << std::endl;
        // Реализация поиска
        return true; // Заглушка для возвращаемого значения
    }
};

#endif // B_H
