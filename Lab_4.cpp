/*Создать очередь строковых значений, для реализации используя односвязные списки. Реализовать операции добавления (enqueue) и
удаления(dequeue) элемента из очереди. Добавьте в очередь строки
«one», «two», «three», «four», «five», «six», «seven» и распечатайте
содержимое очереди. Удалите 4 элемента из очереди, затем
добавьте в очередь строки «eight», «nine» и распечатайте очередь еще
раз. Найдите количество строк, состоящих из 4 символов.*/


#include <iostream>
#include <string>

using namespace std;

struct Node {
  string value;
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

    void enqueue(string value) {
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

    string dequeue() {
      if (isEmpty()) {
        cout << "Очередь пуста!" << endl;
        return "";
      }

      string value = front->value;
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

    int countStringsWithLength(int length) {
      int count = 0;
      Node* temp = front;
      while (temp != nullptr) {
        if (temp->value.length() == length) {
          count++;
        }
        temp = temp->next;
      }
      return count;
    }
};

int main() {
  Queue queue;

  // Добавление элементов в очередь
  queue.enqueue("one");
  queue.enqueue("two");
  queue.enqueue("three");
  queue.enqueue("four");
  queue.enqueue("five");
  queue.enqueue("six");
  queue.enqueue("seven");

  // Печать содержимого очереди
  cout << "Содержимое очереди: ";
  queue.printQueue();

  // Удаление элементов из очереди
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();

  // Добавление новых элементов
  queue.enqueue("eight");
  queue.enqueue("nine");

  // Печать содержимого очереди
  cout << "Содержимое очереди после удаления и добавления: ";
  queue.printQueue();

  // Вычисление количества строк из 4 символов
  int count = queue.countStringsWithLength(4);
  cout << "Количество строк из 4 символов: " << count << endl;

  return 0;
}
