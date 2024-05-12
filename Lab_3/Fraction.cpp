#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

// Шаблонный конструктор
template 
Fraction::Fraction() {
    cout << "Введите числитель: " << endl;
    cin >> numerator;
    cout << "Введите знаменатель: " << endl;
    cin >> denominator;

    // Проверка на ноль в знаменателе
    if (denominator == 0) {
        throw runtime_error("Знаменатель не может быть равен нулю!");
    }
}

// Шаблонная функция для вычисления процентного соотношения
template 
double Fraction::ByPercent() const {
    return (static_cast(numerator) / denominator) * 100;
}

// Шаблонная функция для суммирования цифр знаменателя
template 
int Fraction::SumNumberDenominator() const {
    string numStr = to_string(denominator);
    int sum = 0;
    for (char digit : numStr) {
        if (isdigit(digit)) {
            sum += digit - '0';
        }
    }
    return sum;
}
