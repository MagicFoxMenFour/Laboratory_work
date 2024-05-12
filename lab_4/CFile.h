#pragma once
#include <iostream>
#include <string>
#include <fstream>

class CFile //Базовый класс работы с файлами
{
	public:
		virtual void Open() = 0; //Виртуальная функция открытия файла
		virtual void Close() = 0; //Виртуальная функция закрытия файла
		virtual void Seek() = 0; //Виртуальная функция поиска фрагмента в файле
		virtual void Read() = 0; //Виртуальная функция считывания файла
		virtual void Write() = 0; //Виртуальная функция записи в файл
		virtual void GetPosition() = 0; //Виртуальная функция возврата позиции курсора файла
		virtual void GetLength() = 0; //Виртуальная функция возврата размера файла
};