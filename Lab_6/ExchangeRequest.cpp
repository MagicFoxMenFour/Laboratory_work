#include "ExchangeRequest.h"
#include <iostream>

using namespace std;

ExchangeRequest::ExchangeRequest(const Apartment& wanted, const Apartment& available, double maxAreaDifference)
    : wantedApartment(wanted), availableApartment(available), acceptableAreaDifference(maxAreaDifference) {}

// Сравнение квартир на основе настраиваемых критериев
bool ExchangeRequest::matchApartments(const ExchangeRequest& otherRequest) const {
    // Проверка совпадения количества комнат и района
    if (wantedApartment.numRooms != otherRequest.availableApartment.numRooms ||
        wantedApartment.district != otherRequest.availableApartment.district) {
        return false;
    }

    // Проверка этажа с учетом допустимого диапазона
    int floorDifference = abs(wantedApartment.floor - otherRequest.availableApartment.floor);
    if (floorDifference > maxFloorDifference) {
        return false;
    }

    // Проверка разницы в площади
    double areaDifference = abs(wantedApartment.area - otherRequest.availableApartment.area);
    if (areaDifference / wantedApartment.area > acceptableAreaDifference) {
        return false;
    }

    return true;
}

// Вывод информации о заявке в консоль
void ExchangeRequest::print() const {
    cout << "Заявка на обмен #" << id << ":\n"; // Добавлен вывод ID заявки

    cout << "\nТребуемая квартира:\n";
    cout << "  Количество комнат: " << wantedApartment.numRooms << endl;
    cout << "  Площадь: " << wantedApartment.area << " кв. м" << endl;
    cout << "  Этаж: " << wantedApartment.floor << endl;
    cout << "  Район: " << wantedApartment.district << endl;

    cout << "\nПредлагаемая квартира:\n";
    cout << "  Количество комнат: " << availableApartment.numRooms << endl;
    cout << "  Площадь: " << availableApartment.area << " кв. м" << endl;
    cout << "  Этаж: " << availableApartment.floor << endl;
    cout << "  Район: " << availableApartment.district << endl;
}
