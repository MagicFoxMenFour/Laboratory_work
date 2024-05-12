#include "CMyData.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void CMyData::Open() //Открытие файла
{
	string name; //Получаем на вход имя файла
	cin >> name;
	f_myData.SetName(name); //Устанавливаем имя файла глобальному экземпляру класса
	MyData.open(name, ios::app | ios::in | ios::binary); //Открываем файл в режими бинарного чтения и записи
}

void CMyData::Close() //Закрываем файл
{
	MyData.close();
}

void CMyData::Read() //Считываем данные файла
{
	string buf;
	getline(MyData, buf); //Переписываем значение из файла в переменную построчно
	cout << buf << endl;
	MyData.close(); //Переоткрываем файл
	MyData.open(name, ios::app | ios::in | ios::binary);
}

void CMyData::Write() //Записываем в файл
{
	string let;
	cout << "Идет запись в файл: " << endl;
	cin.ignore();
	getline(cin, let); //Записываем строчку в переменную
	MyData << let; //Добавляем ее в файл
	MyData.close(); //переоткрываем файл
	MyData.open(name, ios::app | ios::in | ios::binary);
}

void CMyData::GetPosition()
{
	int point = MyData.tellg();
	cout << point << endl;
}

void CMyData::GetLength() //Получаем длину файл
{
	int point = MyData.tellg();
	MyData.seekg(0, ios::end); //Переходим в конец файл
	int length = MyData.tellg(); //получаем длину
	MyData.seekg(0, point); //Возвращаем в обратное место
	cout << length << endl;
}

void CMyData::Seek()
{

}

void CMyData::SetName(string name) //Устанавливаем имя
{
	this->name = name;
}

CMyData f_myData;