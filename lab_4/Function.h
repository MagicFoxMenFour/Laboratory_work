#pragma once
#include <string>

class Function //Базовый класс функций
{
	public: 
		virtual const std::string& GetName() = 0; //Возврат имени
		virtual void Calculate() = 0; //Калькулятор функции
	protected:
		double x;
};