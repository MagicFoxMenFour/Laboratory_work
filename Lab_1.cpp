/*Дано число D и указатели P1 и P2 на начало и конец очереди, 
содержащей не менее двух элементов. Добавить элемент со значением D в 
конец очереди и извлечь из очереди первый (начальный) элемент. Вывести 
значение извлеченного элемента и содержимое очереди. После извлечения 
элемента из очереди освободить память, занимаемую этим элементом.*/

#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n, x, D;

    cout << "Введите размер массива (не менее 2-х элементов): ";
    cin >> n;

    int* arr = new int[n]; 

    for (int i = 0; i < n; i++) {
        cout << endl << "Введите " << i + 1 << " элемент массива: ";
        cin >> x;
        arr[i] = x;
    }

    int* P1 = &arr[0];
    int* P2 = &arr[n-1];

    cout << endl << "Введите число D: ";
    cin >> D;

    // Сдвиг элементов массива влево,  имитируя очередь
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n-1] = D; // Добавление D в конец 

    cout << endl << *P1 << endl; // Вывод первого элемента

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Вывод всех элементов
    }

    delete[] arr; // Освобождение памяти

    return 0;
}


/*Создать очередь, информационными полями которой являются: 
наименование процессора и его тактовая частота и количество ядер. 
Добавить в очередь сведения о новом процессоре. Организовать просмотр 
данных очереди и распечатать данные о многоядерных процессорах*/

#include <iostream>
#include <deque>
#include <string>

using namespace std;

struct Processor {
    string name;
    string frequency;
    int cores;
};

int main() {
    setlocale(LC_ALL, "Russian");

    Processor* processors = nullptr; // Указатель на массив процессоров
    int count = 0; // Количество процессоров
    int x;

    do {
        // Выделение памяти для нового процессора
        Processor* temp = new Processor[count + 1];
        for (int i = 0; i < count; i++) {
            temp[i] = processors[i];
        }
        delete[] processors; 
        processors = temp;

        cout << "Введите наименование процессора: " << endl;
        cin >> processors[count].name;
        cout << "Введите тактовую частоту процессора (в гГц): " << endl;
        cin >> processors[count].frequency;
        cout << "Введите количество ядер процессора: " << endl;
        cin >> processors[count].cores;

        count++;

        cout << "Добавить новый процессор (1) или завершить ввод (2)?" << endl;
        cin >> x;
    } while (x == 1);

    for (int i = 0; i < count; i++) {
        cout << "Процессор №" << i + 1 << ": ";
        cout << processors[i].name << " " 
             << processors[i].frequency << " " 
             << processors[i].cores << endl;
    }

    delete[] processors; // Освобождение памяти

    return 0;
}


/*Создать стек целочисленных значений, для реализации 
используя односвязные списки. Реализовать операции добавления (push) и 
удаления (pop) элемента из стека. Добавьте в стек числа 1, 2, 3, 4, 5 и 
распечатайте содержимое стека. Удалите 3 элемента из стека, и распечатайте 
содержимое стека еще раз. Найдите сумму элементов стека.*/

#include <iostream>
#include <vector> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int x = 1, size = 0;
    int* stack = nullptr; // Указатель на динамический массив (стек)

    cout << "Вводите элементы стека: " << endl;

    while (x != 0) {
        cin >> x;
        
        // Расширение массива для нового элемента
        int* temp = new int[size + 1]; 
        for (int i = 0; i < size; i++) {
            temp[i] = stack[i];
        }
        delete[] stack; // Освобождение старой памяти
        stack = temp;

        stack[size] = x; // Добавление элемента в стек
        size++;
    };

    size--; // Уменьшаем размер,  так как последний введенный элемент - 0

    cout << "Исходный стек: " << endl;
    for (int i = size - 1; i >= 0; i--) {
        cout << stack[i] << " ";
    }

    // Удаление 3 элементов с вершины стека
    size -= 3;

    int sum = 0;
    cout << endl << "Обновлённый стек: " << endl;
    for (int i = size - 1; i >= 0; i--) {
        sum += stack[i];
        cout << stack[i] << " ";
    }

    cout << endl << "Сумма элементов стека равна " << sum;

    delete[] stack; // Освобождение памяти

    return 0;
}


/*Создать очередь вещественных значений, для реализации 
используя односвязные списки. Реализовать операции добавления (enqueue) 
и удаления (dequeue) элемента из очереди. Добавьте в очередь числа 46.5, 3.4, 
32.4, -3.21 и распечатайте содержимое очереди. Удалите 2 элемента из 
очереди, затем добавьте в очередь число 5.0 и распечатайте очередь еще раз. 
Найдите сумму элементов, по модулю больших 12, принадлежащих очереди.*/

#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x = 1;
    int size = 0;
    double* queue = nullptr; // Указатель на динамический массив (очередь)

    cout << "Вводите элементы очереди: " << endl;

    while (x != 0) {
        cin >> x;
        if (x != 0) {
            // Расширение массива для нового элемента
            double* temp = new double[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = queue[i];
            }
            delete[] queue; // Освобождение старой памяти
            queue = temp;

            queue[size] = x; // Добавление элемента в очередь
            size++;
        }
    }

    cout << "Исходная очередь: ";
    for (int i = 0; i < size; i++) {
        cout << queue[i] << " ";
    }

    // Удаление 2 элементов из начала очереди
    for (int i = 0; i < size - 2; i++) {
        queue[i] = queue[i + 2];
    }
    size -= 2;

    // Добавление элемента 5.0 в конец очереди
    double* temp = new double[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = queue[i];
    }
    delete[] queue;
    queue = temp;
    queue[size] = 5.0;
    size++;

    cout << endl << "Обновлённая очередь: ";
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        if (abs(queue[i]) > 12.0) {
            sum += queue[i];
        }
        cout << queue[i] << " ";
    }

    cout << endl << "Сумма элементов очереди, по модулю больших 12, равна " << sum;

    delete[] queue; // Освобождение памяти

    return 0;
}


/*Дано число N (> 0) и две непустые очереди; адреса начала и конца 
первой равны P1 и P2, а второй — P3 и P4. Переместить N начальных 
элементов первой очереди в конец второй очереди. Если первая очередь 
содержит менее N элементов, то переместить из первой очереди во вторую 
все элементы. Вывести новые адреса начала и конца первой, а затем второй 
очереди (для пустой очереди дважды вывести nil). Операции выделения и 
освобождения памяти не использовать.*/

#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int* queue1 = nullptr;
    int* queue2 = nullptr;
    int size1 = 0, size2 = 0;
    int x = 1, N;

    cout << "Вводите элементы 1 очереди (0 для завершения): " << endl;
    while (x != 0) {
        cin >> x;
        if (x != 0) {
            int* temp = new int[size1 + 1];
            for (int i = 0; i < size1; i++) {
                temp[i] = queue1[i];
            }
            delete[] queue1;
            queue1 = temp;
            queue1[size1] = x;
            size1++;
        }
    }

    cout << "Вводите элементы 2 очереди (0 для завершения): " << endl;
    while (x != 0) {
        cin >> x;
        if (x != 0) {
            int* temp = new int[size2 + 1];
            for (int i = 0; i < size2; i++) {
                temp[i] = queue2[i];
            }
            delete[] queue2;
            queue2 = temp;
            queue2[size2] = x;
            size2++;
        }
    }

    cout << "Введите число N (> 0): ";
    cin >> N;

    // Перемещение элементов из queue1 в queue2
    if (size1 < N) {
        for (int i = 0; i < size1; i++) {
            int* temp = new int[size2 + 1];
            for (int j = 0; j < size2; j++) {
                temp[j] = queue2[j];
            }
            delete[] queue2;
            queue2 = temp;
            queue2[size2] = queue1[i];
            size2++;
        }
        delete[] queue1;
        queue1 = nullptr;
        size1 = 0;
    } else {
        for (int i = 0; i < N; i++) {
            int* temp = new int[size2 + 1];
            for (int j = 0; j < size2; j++) {
                temp[j] = queue2[j];
            }
            delete[] queue2;
            queue2 = temp;
            queue2[size2] = queue1[i];
            size2++;
        }
        for (int i = 0; i < size1 - N; i++) {
            queue1[i] = queue1[i + N];
        }
        size1 -= N;
    }

    // Вывод информации об очередях
    if (size1 == 0) {
        cout << "Начало первой очереди: nil" << endl << "Конец первой очереди: nil" << endl;
    } else {
        cout << "Начало первой очереди: " << &queue1[0] << endl 
             << "Конец первой очереди: " << &queue1[size1 - 1] << endl;
    }

    cout << "Начало второй очереди: " << &queue2[0] << endl 
         << "Конец второй очереди: " << &queue2[size2 - 1];

    delete[] queue1;
    delete[] queue2;

    return 0;
}


/*Создать линейный однонаправленный список из вещественных 
чисел. Удалить из списка элемент после первого элемента с положительным 
значением.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x = 1;
    int size = 0;
    double* list = nullptr; // Указатель на динамический массив (список)

    cout << "Вводите элементы списка (0 - конец списка): " << endl;

    while (x != 0) {
        cin >> x;
        
        // Расширение массива для нового элемента
        double* temp = new double[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;

        list[size] = x;
        size++;
    }

    size--; // Уменьшаем размер,  так как последний введенный элемент - 0

    cout << "Исходный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    // Удаление элемента после первого положительного
    for (int i = 0; i < size; i++) {
        if (list[i] > 0 && i < size - 1) { // Проверяем,  что i+1 не выходит за границы
            for (int j = i + 1; j < size - 1; j++) {
                list[j] = list[j + 1];
            }
            size--;
            break;
        }
    }

    cout << endl << "Преобразованный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    delete[] list; // Освобождение памяти

    return 0;
}


/*Создать линейный однонаправленный список из целых чисел. 
Определить среднее арифметическое значений всех элементов списка, кроме 
второго и третьего.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> list;
    int x = 1;
    double sum = 0.0;

    cout << "Введите количество элементов списка: ";
    int count;
    cin >> count;

    cout << "Вводите элементы списка:" << endl;
    for (int i = 0; i < count; i++) {
        cin >> x;
        list.push_back(x);
    }

    cout << "Введите номера двух элементов, которые нужно исключить из расчета среднего арифметического (от 1 до " << count << "): ";
    int excludeIndex1, excludeIndex2;
    cin >> excludeIndex1 >> excludeIndex2;

    // Проверка корректности введенных индексов
    if (excludeIndex1 < 1 || excludeIndex1 > count || excludeIndex2 < 1 || excludeIndex2 > count || excludeIndex1 == excludeIndex2) {
        cout << "Некорректные номера элементов." << endl;
        return 1;
    }

    cout << "Исходный список: ";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    // Подсчет суммы элементов,  исключая заданные
    int elementsToExclude = 0;
    for (int i = 0; i < list.size(); i++) {
        if (i + 1 != excludeIndex1 && i + 1 != excludeIndex2) {
            sum += list[i];
        } else {
            elementsToExclude++;
        }
    }

    double average = sum / (list.size() - elementsToExclude);
    cout << endl << "Среднее арифметическое элементов списка (без элементов №"
         << excludeIndex1 << " и №" << excludeIndex2 << ") равно " << average;

    return 0;
}


/*Создать линейный однонаправленный список из вещественных 
чисел. Удалить из списка первый элемент меньший по модулю 5.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x = 1;
    int size = 0;
    double* list = nullptr; // Указатель на динамический массив (список)
    double threshold; // Порог для удаления

    cout << "Вводите элементы списка (0 - конец списка): " << endl;

    while (x != 0) {
        cin >> x;

        // Расширение массива для нового элемента
        double* temp = new double[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;

        list[size] = x;
        size++;
    }

    size--; // Уменьшаем размер,  так как последний введенный элемент - 0

    cout << "Введите пороговое значение для удаления: ";
    cin >> threshold;

    cout << "Исходный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    // Удаление первого элемента,  меньшего порога по модулю
    for (int i = 0; i < size; i++) {
        if (abs(list[i]) < threshold) {
            // Сдвигаем элементы влево,  перезаписывая удаляемый
            for (int j = i; j < size - 1; j++) {
                list[j] = list[j + 1];
            }
            size--; 
            break; // Выходим из цикла после удаления
        }
    }

    cout << endl << "Преобразованный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    delete[] list; // Освобождение памяти

    return 0;
}


/*Создать линейный однонаправленный список из вещественных 
чисел. Определить среднее значение элементов списка со значениями 
меньше либо равными 15. Удалить из списка элементы, которые больше 25.*/

#include <iostream>
#include <vector> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x = 1, sum = 0, number = 0;
    int size = 0;
    double* list = nullptr; // Указатель на динамический массив (список)
    double upperThreshold, lowerThreshold; // Пороги для вычисления среднего и удаления

    cout << "Вводите элементы списка (0 - конец списка): " << endl;

    while (x != 0) {
        cin >> x;

        // Расширение массива для нового элемента
        double* temp = new double[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;

        list[size] = x;
        size++;
    }

    size--; // Уменьшаем размер,  так как последний введенный элемент - 0

    cout << "Введите верхний порог для вычисления среднего арифметического: ";
    cin >> upperThreshold;
    cout << "Введите нижний порог для удаления элементов: ";
    cin >> lowerThreshold;

    cout << "Исходный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    // Вычисление среднего арифметического и удаление элементов
    for (int i = 0; i < size; i++) {
        if (list[i] <= upperThreshold) {
            sum += list[i];
            number++;
        }

        if (list[i] > lowerThreshold) {
            // Сдвигаем элементы влево,  перезаписывая удаляемый
            for (int j = i; j < size - 1; j++) {
                list[j] = list[j + 1];
            }
            size--; 
            i--; // Уменьшаем индекс,  так как элемент был удален
        }
    }

    cout << endl << "Среднее арифметическое элементов списка, меньших либо равных " 
         << upperThreshold << " равно: " << sum / number;

    cout << endl << "Преобразованный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    delete[] list; // Освобождение памяти

    return 0;
}


/*Дан указатель P1 на начало односвязного линейного списка. 
Преобразовать исходную (односвязную) цепочку в двусвязную, в которой 
каждый элемент связан не только с последующим элементом (с помощью 
поля Next), но и с предыдущим (с помощью поля Prev). Поле Prev первого 
элемента положить равным nil. Вывести на экран преобразованную цепочку в 
обратном порядке.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double x = 1;
    int size = 0;
    double* list = nullptr;

    cout << "Вводите элементы списка (0 - конец списка): " << endl;

    while (x != 0) {
        cin >> x;
        
        // Расширение массива
        double* temp = new double[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        list = temp;

        list[size] = x;
        size++;
    }

    size--; // Уменьшение размера,  так как последний элемент - 0

    cout << "Исходный список: ";
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }

    cout << endl << "Обратный список: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << list[i] << " ";
    }

    delete[] list; // Освобождение памяти

    return 0;
}
