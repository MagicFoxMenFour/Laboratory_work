#include "Line.h"
#include <iostream>
#include <string>

using namespace std;

void Line::Calculate() //Калькулятор
{
	cout << "Уравнение вида: y = " << name << endl; //Получение значения х
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите x: ";
	cin >> x;
	cout << "y = " << a*x + b << endl; //Вывод результата
}

Line::Line() //Конструктор
{
	this->name = "ax + b";
}

const string& Line::GetName() //Возвращает имя
{
	return name;
}

Line f_line;