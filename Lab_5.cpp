/*Дан набор из 10 чисел. Создать две очереди: первая должна содержать все
нечетные, а вторая — все четные числа из исходного набора (порядок чисел
в каждой очереди должен совпадать с порядком чисел в исходном наборе).
Вывести указатели на начало и конец первой, а затем второй очереди (одна
из очередей может оказаться пустой; в этом случае вывестидля нее две
константы nil).*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  queue<int> oddQueue;
  queue<int> evenQueue;

  for (int i = 0; i < 10; i++) {
    if (arr[i] % 2 == 0) {
      evenQueue.push(arr[i]);
    } else {
      oddQueue.push(arr[i]);
    }
  }

  // Вывод указателей на начало и конец первой очереди
  cout << "Первая очередь (нечетные числа):" << endl;
  if (!oddQueue.empty()) {
    cout << "Начало: " << &oddQueue.front() << endl;
    cout << "Конец: " << &oddQueue.back() << endl;
  } else {
    cout << "nil" << endl;
    cout << "nil" << endl;
  }

  // Вывод указателей на начало и конец второй очереди
  cout << "Вторая очередь (четные числа):" << endl;
  if (!evenQueue.empty()) {
    cout << "Начало: " << &evenQueue.front() << endl;
    cout << "Конец: " << &evenQueue.back() << endl;
  } else {
    cout << "nil" << endl;
    cout << "nil" << endl;
  }

  return 0;
}
