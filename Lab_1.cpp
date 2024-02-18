#include <iostream>
#include <stack>

using namespace std;


struct Student {
    string фамилия;
    float средний_бал;
};

int main() {
    setlocale(LC_ALL, "Russian");

    stack<Student> students;

    // Добавление нового студента
    Student new_student;
    cout << "Введите фамилию студента: ";
    cin >> new_student.фамилия;
    cout << "Введите средний балл студента: ";
    cin >> new_student.средний_бал;
    students.push(new_student);

    // Просмотр данных стека
    while (!students.empty()) {
        Student student = students.top();
        students.pop();
        cout << "Фамилия: " << student.фамилия << endl;
        cout << "Средний балл: " << student.средний_бал << endl;
    }

    return 0;
}
