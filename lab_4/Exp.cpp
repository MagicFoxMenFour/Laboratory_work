#include "Exp.h"
#include "math.h"
#include <iostream>
#include <string>

using namespace std;

void Exp::Calculate() //Калькулятор
{
	cout << "Уравнение вида: y = " << name << endl; //Получение коэфицентов и значения х
	cout << "Введите x: ";
	cin >> x;
	cout << "y = " << exp(x) << endl; //Вывод результата
}


Exp::Exp() //Конструктор
{
	this->name = "e ^ x";
}

const string& Exp::GetName() //Возвращает имя
{
	return name;
}

Exp f_exp;