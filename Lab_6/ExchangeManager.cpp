#include "ExchangeManager.h"
#include <iostream>
#include <algorithm>

void ExchangeManager::addRequest(const ExchangeRequest& request) {
    requests.push_back(request);
    checkForMatches(request); // Проверка на совпадения сразу после добавления
}

void ExchangeManager::checkForMatches(const ExchangeRequest& newRequest) {
    for (auto it = requests.begin(); it != requests.end(); ++it) {
        if (it->id != newRequest.id && it->matchApartments(newRequest)) { // Проверка,  что это не та же заявка
            std::cout << "Найдено совпадение!\n";
            it->print();
            std::cout << "-----------------------\n";
            newRequest.print();
            std::cout << "-----------------------\n";

            // Опционально: удаление совпавших заявок
            requests.erase(it); 
            // Важно: если `it`  удалён,  `newRequest`  может  быть  еще  не  добавлен  в  `requests`,  
            // поэтому  нужно  обработать  этот  случай  отдельно
            if (std::find(requests.begin(), requests.end(), newRequest) == requests.end()) {
                requests.erase(std::remove(requests.begin(), requests.end(), newRequest), requests.end());
            }
            return; // Выход из цикла после нахождения совпадения
        }
    }
}

void ExchangeManager::printAllRequests() const {
    if (requests.empty()) {
        std::cout << "Заявок на обмен нет.\n";
        return;
    }
    std::cout << "Все заявки на обмен:\n";
    for (const auto& request : requests) {
        request.print();
        std::cout << "-----------------------\n";
    }
}
