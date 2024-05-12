#include <iostream>
#include "Apartment.h"
#include "ExchangeRequest.h"
#include "ExchangeManager.h"

using namespace std;

// Функция для ввода данных квартиры
Apartment inputApartmentData(const string& apartmentType) {
    Apartment apartment;
    cout << "\nВведите данные для " << apartmentType << " квартиры:\n";
    cout << "  Количество комнат: ";
    cin >> apartment.numRooms;
    cout << "  Площадь (кв. м): ";
    cin >> apartment.area;
    cout << "  Этаж: ";
    cin >> apartment.floor;
    cout << "  Район: ";
    cin >> apartment.district;
    return apartment;
}

int main() {
    setlocale(LC_ALL, "Russian");

    ExchangeManager manager;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить заявку на обмен\n";
        cout << "2. Найти совпадения\n";
        cout << "3. Вывести все заявки\n";
        cout << "4. Выйти\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Apartment wanted = inputApartmentData("требуемой");
            Apartment available = inputApartmentData("предлагаемой");

            double maxAreaDifference;
            cout << "  Введите максимально допустимую разницу в площади (в %): ";
            cin >> maxAreaDifference;
            maxAreaDifference /= 100; // Преобразование процентов в доли

            ExchangeRequest request(wanted, available, maxAreaDifference);
            manager.addRequest(request);
            break;
        }
        case 2:
            cout << "\nСовпадения:\n";
            manager.findMatches();
            break;
        case 3:
            manager.printAllRequests();
            break;
        case 4:
            cout << "\nВыход...\n";
            break;
        default:
            cout << "\nНеверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 4);

    return 0;
}
