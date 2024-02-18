/*Создать очередь вещественных значений, для реализации используя
односвязные списки. Реализовать операции добавления (enqueue) и
удаления (dequeue) элемента из очереди. Добавьте в очередь числа 2.2, 1.2,
2.0, 5.2 и распечатайте содержимое очереди. Удалите 2 элемента из
очереди, затем добавьте в очередь число 2.9 и распечатайте очередь еще
раз. Найдите сумму элементов очереди.*/


#include <iostream>

using namespace std;

struct Node {
  float value;
  Node* next;
};

class Queue {
  private:
    Node* front;
    Node* rear;

  public:
    Queue() {
      front = rear = nullptr;
    }

    void enqueue(float value) {
      Node* newNode = new Node;
      newNode->value = value;
      newNode->next = nullptr;

      if (isEmpty()) {
        front = rear = newNode;
      } else {
        rear->next = newNode;
        rear = newNode;
      }
    }

    float dequeue() {
      if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return -1;
      }

      float value = front->value;
      Node* temp = front;
      front = front->next;

      if (front == nullptr) {
        rear = nullptr;
      }

      delete temp;

      return value;
    }

    bool isEmpty() {
      return front == nullptr;
    }

    void printQueue() {
      if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return;
      }

      Node* temp = front;
      while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
      }

      cout << endl;
    }

    float sumOfQueue() {
      float sum = 0;
      Node* temp = front;
      while (temp != nullptr) {
        sum += temp->value;
        temp = temp->next;
      }
      return sum;
    }
};

int main() {
  Queue queue;

  // Добавление элементов в очередь
  queue.enqueue(2.2);
  queue.enqueue(1.2);
  queue.enqueue(2.0);
  queue.enqueue(5.2);

  // Печать содержимого очереди
  cout << "Содержимое очереди: ";
  queue.printQueue();

  // Удаление элементов из очереди
  queue.dequeue();
  queue.dequeue();

  // Добавление нового элемента
  queue.enqueue(2.9);

  // Печать содержимого очереди
  cout << "Содержимое очереди после удаления и добавления: ";
  queue.printQueue();

  // Вычисление суммы элементов очереди
  float sum = queue.sumOfQueue();
  cout << "Сумма элементов очереди: " << sum << endl;

  return 0;
}
