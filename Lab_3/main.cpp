#include <iostream>
#include "Triangle.h"
#include<string>
#include"Fraction.h"

using namespace std;

// Базовый класс для заданий
class Task {
public:
    virtual void execute() = 0; // Виртуальная функция для выполнения задания
    virtual ~Task() {} // Виртуальный деструктор
};

// Класс для задания 1 (прямоугольный треугольник)
class RightTriangleTask : public Task {
private:
    RightTriangle triangle;
public:
    RightTriangleTask() : triangle(3, 4) {} // Конструктор с параметрами для задания катетов
    void execute() override {
        cout << "Гипотенуза прямоугольного треугольника: " 
             << triangle.GetHypotenuse() << endl; 
    }
};

// Класс для задания 2 (дробь)
class FractionTask : public Task {
private:
    Fraction<double> fraction; 
public:
    FractionTask() : fraction(3, 7) {} // Конструктор с параметрами для задания числителя и знаменателя
    void execute() override {
        cout << "Дробь: " << fraction.Numerator << "/" << fraction.Denominator << endl;
        cout << "В процентном соотношении: " << fraction.ByPercent() << "%" << endl; 
        cout << "Сумма цифр знаменателя: " << fraction.SumNumberDenominator() << endl; 
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    // Создаем массив указателей на базовый класс Task
    vector tasks;
    tasks.push_back(new RightTriangleTask());
    tasks.push_back(new FractionTask());

    int taskNumber;
    cout << "Выберите номер задания (1-" << tasks.size() << "): ";
    cin >> taskNumber;

    // Проверка корректности номера задания
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1]->execute(); // Вызываем execute() для выбранного задания
    } else {
        cout << "Такого задания нет" << endl;
    }

    // Освобождаем память
    for (auto task : tasks) {
        delete task;
    }

    return 0;
}
