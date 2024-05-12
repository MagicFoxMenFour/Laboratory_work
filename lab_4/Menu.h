#pragma once
#include "Function.h"
#include <vector>

class Menu //Класс меню функций
{
	public: 
		Menu(std::vector<Function*>); //Конструктор
		Function* SelectObject(); // Выбор функции
	private:
		int SelectItem(int);
		std::vector<Function*> pObject;
};