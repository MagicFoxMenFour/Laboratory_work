#ifndef EXCHANGEMANAGER_H
#define EXCHANGEMANAGER_H

#include "ExchangeRequest.h"
#include <vector>

class ExchangeManager {
public:
    void addRequest(const ExchangeRequest& request); // Добавление заявки
    void findMatches(); // Поиск совпадений
    void printAllRequests() const; // Вывод всех заявок

private:
    std::vector<ExchangeRequest> requests; // Список заявок
};

#endif // EXCHANGEMANAGER_H
