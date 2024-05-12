#include "Triangle.h"
#include "math.h"
#include <iostream>

using namespace std;

// Конструктор с параметрами для задания катетов
RightTriangle::RightTriangle(double leg1, double leg2) : legH(leg1), legW(leg2) {}

// Геттеры для катетов
double RightTriangle::getLegH() const {
    return legH;
}

double RightTriangle::getLegW() const {
    return legW;
}

// Сеттеры для катетов
void RightTriangle::setLegH(double newLegH) {
    legH = newLegH;
}

void RightTriangle::setLegW(double newLegW) {
    legW = newLegW;
}

// Вычисление гипотенузы
double RightTriangle::getHypotenuse() const {
    return sqrt(pow(legH, 2) + pow(legW, 2));
}
