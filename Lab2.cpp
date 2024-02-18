/*Создать очередь, информационными полями которой являются:
наименование товара и его стоимость. Добавить в очередь сведения
о новом товаре. Организовать просмотр данных очереди и вычислить
общуюстоимость товаров с наименованием «Ручка шариковая».*/

#include <iostream>
#include <queue>

using namespace std;

struct Product {
  string наименование;
  float стоимость;
};

int main() {
  queue<Product> products;

  // Добавление нового товара
  Product new_product;
  cout << "Введите наименование товара: ";
  cin >> new_product.наименование;
  cout << "Введите стоимость товара: ";
  cin >> new_product.стоимость;
  products.push(new_product);

  // Просмотр данных очереди
  float total_cost_of_pens = 0;
  while (!products.empty()) {
    Product product = products.front();
    products.pop();
    cout << "Наименование: " << product.наименование << endl;
    cout << "Стоимость: " << product.стоимость << endl;
    if (product.наименование == "Ручка шариковая") {
      total_cost_of_pens += product.стоимость;
    }
  }

  cout << "Общая стоимость ручек: " << total_cost_of_pens << endl;

  return 0;
}
