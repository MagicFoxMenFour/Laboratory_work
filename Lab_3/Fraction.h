#pragma once
#include <iostream>

template <typename T> //Создаем шаблонный класс
class Fraction 
{
public:
	Fraction(); //Конструктор
	double ByPercent(); //Получение процентного соотношения дроби
	int SumNumberDenominator(); //Сумма цифр знаменателя
	~Fraction() //Деконструктор
	{
		std::cout << "Объект удален" << std::endl;
	}
private:
	T numerator; //Поле числителя
	T denominator; //Поле знаменателя
};
