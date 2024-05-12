#pragma once
#include "Function.h"
#include <string>

class Line : public Function
{
	public:
		Line(); //Конструктор
		const std::string& GetName(); 
		void Calculate(); //Калькулятор
	protected:
		std::string name; //Имя
		double a; //Коэфиценты
		double b;
};

extern Line f_line;