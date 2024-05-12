#pragma once

class RightTriangle //Класс правильного треугольника
{
	public:
		RightTriangle(); //Конструктор
		double GetlegW(); //Получаем доступ к 1 катету
		double GetlegH(); //Получаем доступ к 2 катету
		void SetlegW(double legW); //Устанавливаем значение 1 ктатета
		void SetlegH(double legH); //Устанавливаем значение 2 ктатета
		double GetHypotenuse(); //Получаем гипотенузу
	private:
		double legW;
		double legH;
};
