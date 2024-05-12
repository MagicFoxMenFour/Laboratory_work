#ifndef EXCHANGEREQUEST_H
#define EXCHANGEREQUEST_H

#include "Apartment.h"

class ExchangeRequest {
public:
    ExchangeRequest(const Apartment& wanted, const Apartment& available);

    bool matchApartments() const; // Проверка совпадения квартир
    void print() const; // Вывод информации о заявке

private:
    Apartment wantedApartment; // Требуемая квартира
    Apartment availableApartment; // Доступная квартира
};

#endif // EXCHANGEREQUEST_H
