#include <iostream>
#include "Function.h"
#include "Exp.h"
#include "Line.h"
#include "Menu.h"
#include "Diskriminant.h"
#include "MenuFile.h"

using namespace std;

// Абстрактный базовый класс для функций
class Function {
public:
    virtual void calculate() const = 0; 
    virtual string getName() const = 0;
    virtual ~Function() {}
};

// Класс для экспоненциальной функции
class ExponentialFunction : public Function {
public:
    void calculate() const override {
        // Реализация вычисления экспоненциальной функции
        cout << "Вычисление экспоненциальной функции...\n";
    }
    string getName() const override { return "Экспоненциальная функция"; }
};

// Класс для линейной функции
class LinearFunction : public Function {
public:
    void calculate() const override {
        // Реализация вычисления линейной функции
        cout << "Вычисление линейной функции...\n";
    }
    string getName() const override { return "Линейная функция"; }
};

// Класс для вычисления дискриминанта
class DiscriminantFunction : public Function {
public:
    void calculate() const override {
        // Реализация вычисления дискриминанта
        cout << "Вычисление дискриминанта...\n";
    }
    string getName() const override { return "Дискриминант"; }
};

// Класс для меню
class Menu {
private:
    vector

            case 2: {
                MenuFile menuFile;
                while (menuFile.processAction()) {} // Выполняем действия меню, пока пользователь не выберет выход
                break;
            }
            default:
                return 1;
        }
    } while (true); // Бесконечный цикл, пока пользователь не выберет выход

    return 0;
}
