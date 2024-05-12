#include <iostream>
#include <string>
#include <fstream>
#include "MenuFile.h"
#include "CMyData.h"

using namespace std;

int MenuFile::ChoiceFunc()
{
	int end = 1;
	while (end) //Если достигнуто условие, прорамма закрывается
	{
		if (f_myData.GetMyData().is_open()) //Проверка на открытие
		{
			cout << "1. Открыть \n2. Закрыть \n3. Найти \n4. Прочитать \n5. Записать \n6. Получить позицию курсора \n7. Получить длину файла" << endl;
			int num;
			cin >> num;
			switch (num) //Выбор функции
			{
				case 1:
				{
					f_myData.Open();
					break;
				}
				case 2:
				{
					f_myData.Close();
					end = 0;
					break;
				}
				case 3:
				{
					f_myData.Seek();
					break;
				}
				case 4:
				{
					f_myData.Read();
					break;
				}
				case 5:
				{
					f_myData.Write();
					break;
				}
				case 6:
				{
					f_myData.GetPosition();
					break;
				}
				case 7:
				{
					f_myData.GetLength();
					break;
				}
				default:
				{
					end = 0;
					return 1;
				}
			}
		}
		else //Если файл закрыт
		{
			cout << "Откройте файл: " << endl;
			f_myData.Open();
		}
	}
	return 0;
}