#pragma once
#include <iostream>
#include "CFile.h"
#include <string>
#include <fstream>

class CMyData : public CFile //Подкласс файла, наследуемый от базового файла
{
	public:
		void Open(); //Реализация функций наследника
		void Close();
		void Seek();
		void Read();
		void Write();
		void GetPosition();
		void GetLength();
		std::fstream& GetMyData() //Возвращает переменную файла
		{
			return MyData; 
		}
		void SetName(std::string name); //Устанавливает имя файла
	private:
		std::fstream MyData; //Файл
		std::string name; //Имя файла
};

extern CMyData f_myData; //Экземпляр файла