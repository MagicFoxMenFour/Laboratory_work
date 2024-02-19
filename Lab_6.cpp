/*Создать линейный однонаправленный список строк. Удалить из
списка первую строку, заканчивающуюся на цифру*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
  string value;
  Node* next;
};

Node* head = nullptr;

void insertAtEnd(string value) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void deleteFirstNodeEndingWithDigit() {
  if (head == nullptr) {
    return;
  }

  if (isdigit(head->value[head->value.length() - 1])) {
    head = head->next;
    return;
  }

  Node* previous = nullptr;
  Node* current = head;
  while (current != nullptr && !isdigit(current->value[current->value.length() - 1])) {
    previous = current;
    current = current->next;
  }

  if (current != nullptr) {
    previous->next = current->next;
    delete current;
  }
}

void printList() {
  Node* temp = head;
  while (temp != nullptr) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  // Вставка элементов в список
  insertAtEnd("one");
  insertAtEnd("two2");
  insertAtEnd("three");
  insertAtEnd("four4");
  insertAtEnd("five");

  // Печать списка
  cout << "Список до удаления: ";
  printList();

  // Удаление первой строки, 
