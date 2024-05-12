#pragma once
#include "Function.h"

class Exp : public Function
{
	public:
		Exp(); //Конструктор
		const std::string& GetName();
		void Calculate(); //Калькулятор функции
	protected:
		std::string name; //Имя функции
};

extern Exp f_exp;