#include "Menu.h"
#include <iostream>
#include "Function.h"

using namespace std;

Menu::Menu(vector<Function*> _pObject) //Вызов конструктора
{
	for (Function* i : _pObject) //Заполнение массива с функциями
	{
		pObject.push_back(i);
	}
	pObject.push_back(0); //Условие выхода
}

Function* Menu::SelectObject() //Вывод списка функци1
{
	int nItem = pObject.size(); //Количество функций
	cout << "=====================================\n";
	cout << "Select one of the following function in:\n"; 
	for (int i = 0; i < nItem; i++) //Перебор функций
	{
		cout << i + 1 << ". "; //Описание функций
		if (pObject[i])
		{
			cout << pObject[i]->GetName() << endl;
		}
		else //Условие выхода
		{
			cout << "Exit " << endl;
		}
	}
	int item = SelectItem(nItem);
	return pObject[item - 1];
}

int Menu::SelectItem(int nItem)  //Выбор функции
{
	cout << "-----------\n";
	int item;
	while (true) 
	{
		cin >> item;
		if ((item > 0) && (item <= nItem)) //Если есть функция
		{
			break;
		}
		else
		{
			cout << "Error__" << endl;
		}
	}
	return item;
};