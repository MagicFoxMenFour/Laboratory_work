#include "Diskriminant.h"
#include <iostream>
#include "Function.h"

using namespace std;

Diskriminant::Diskriminant() //Конструктор
{
	this->name = "ax^2 + bx + c";
}

void Diskriminant::Calculate() //Калькулятор
{
	cout << "Уравнение вида: y = " << name << endl; //Получение коэфицентов и значения х
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите c: ";
	cin >> c;
	cout << "Введите x: ";
	cin >> x;
	cout << "y = " << a * x * x + b * x + c << endl; //Вывод результата
}

const string& Diskriminant::GetName() //Возвращает имя
{
	return name;
}

Diskriminant f_dis;