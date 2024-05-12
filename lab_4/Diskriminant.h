#pragma once
#include "Function.h"
#include <string>

class Diskriminant : public Function
{
public:
	Diskriminant(); //Конструктор
	const std::string& GetName();
	void Calculate(); //Калькулятор функции
protected:
	std::string name; //Имя функции
	double a; //Коэфиценты
	double b;
	double c;
};

extern Diskriminant f_dis;