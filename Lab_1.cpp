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
	
	deque<int>q;
	int n, x, D;

	cout << "Введите размер очереди (не менее 2-х элементов): ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << endl << "Введите " << i + 1 << " элемент очереди: ";
		cin >> x;
		q.push_back(x);
	}

	int* P1 = &q.front();
	int* P2 = &q.back();

	cout << endl << "Введите число D: ";
	cin >> D;

	q.push_back(D);
	q.pop_front();

	cout << endl << *P1 << endl;


	for (int i = 0; i < n; i++) {
		cout << q.front() << " ";
		q.pop_front();
	}

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

int main() {
	setlocale(LC_ALL, "Russian");
	
	deque<string>processor;
	int x;
	string name, frequency, cores;

	do {
		cout << "Введите наименование процессора: " << endl;
		cin >> name;
		processor.push_back(name);
		cout << "Введите тактовую частоту процессора (в гГц): " << endl;
		cin >> frequency;
		processor.push_back(frequency);
		cout << "Введите количетсов ядер процессора: " << endl;
		cin >> cores;
		processor.push_back(cores);
		
		cout << "Добавить новый процессор (1) или завершить ввод (2)?" << endl;
		cin >> x;
	} while (x == 1);

	int size = processor.size();

	for (int i = 1; i <= size; i++) {
		
		if ((i-1) % 3 == 0) {
			cout << "Процессор №" << ((i - 1) / 3) + 1 << ": ";
		}

		cout << processor.front() << " ";

		if (i % 3 == 0) {
			cout << endl;
		}

		processor.pop_front();
	}

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

vector<int>stack, dop_stack;

void push(int el) {
	stack.push_back(el);
}

void pop() {
	stack.pop_back();
}

void dop_pop() {
	dop_stack.pop_back();
}

void dop_push(int el) {
	dop_stack.push_back(el);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x = 1;

	cout << "Вводите элементы стека: " << endl;

	int size = -1;

	while (x != 0) {
		cin >> x;
		push(x);
		size++;
	};

	pop();

	cout << "Исходный стек: " << endl;

	for (int i = 0; i < size; i++) {
		cout << stack.back() << " ";
		dop_push(stack.back());
		pop();
	}

	for (int i = 0; i < size; i++) {
		push(dop_stack.back());
		dop_pop();
	}

	for (int i = 0; i < 3; i++) {
		pop();
	}

	int sum = 0;
	cout << endl << "Обновлённый стек: " << endl;

	while (stack.size() != 0) {
		sum += stack.back();
		cout << stack.back() << " ";
		pop();
	}

	cout << endl << "Сумма элементов стека равна " << sum;

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

deque<double>que;

void enqueue(double el) {
	que.push_back(el);
}

void dequeue() {
	que.pop_front();
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	double x = 1;

	cout << "Вводите элементы очереди: " << endl;

	while (x != 0) {
		cin >> x;
		if (x != 0) {
			enqueue(x);
		}
	}

	cout << "Исходная очередь: ";
	
	for (int i = 0; i < que.size(); i++) {
		cout << que.front() << " ";
		enqueue(que.front());
		dequeue();
	}

	for (int i = 0; i < 2; i++) {
		dequeue();
	}

	enqueue(5.0);
	
	cout << endl << "Обновлённая очередь: ";

	double sum = 0.0;

	for (int i = 0; i < que.size(); i++) {
		if (abs(que.front()) > 12.0) {
			sum += que.front();
		}
		cout << que.front() << " ";
		enqueue(que.front());
		dequeue();
	}

	cout << endl << "Сумма элементов очереди, по модулю больших 12, равна " << sum;
	
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
	
	deque<int>que_1, que_2;

	int x = 1, N;

	cout << "Вводите элементы 1 очереди: " << endl;

	while (x != 0) {
		cin >> x;
		if (x != 0) {
			que_1.push_back(x);
		}
	}

	x = 1;

	cout << "Вводите элементы 2 очереди: " << endl;

	while (x != 0) {
		cin >> x;
		if (x != 0) {
			que_2.push_back(x);
		}
	}

	cout << "Введите число N (> 0): ";
	cin >> N;
	
	int* P1 = &que_1.front();
	int* P2 = &que_1.back();
	int* P3 = &que_2.front();
	int* P4 = &que_2.back();

	if (que_1.size() < N) {
		while (!que_1.empty()) {
			que_2.push_back(que_1.front());
			que_1.pop_front();
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			que_2.push_back(que_1.front());
			que_1.pop_front();
		}
	}

	if (que_1.empty()) {
		cout << "Начало первой очереди: nil" << endl << "Конец первой очереди: nil" << endl;
	}
	else {
		cout << "Начало первой очереди: " << P1 << endl << "Конец первой очереди: " << P2 << endl;
	}
	cout << "Начало второй очереди: " << P3 << endl << "Конец второй очереди: " << P4;

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
	
	vector <double> list;

	double x = 1;

	cout << "Вводите элементы списка (0 - конец списка): " << endl;

	while (x != 0) {
		cin >> x;
		list.push_back(x);
	}

	list.pop_back();

	cout << "Исходный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

	for (int i = 0; i < list.size(); i++) {
		if (list[i] > 0) {
			auto iter = list.cbegin();
			list.erase(iter + i + 1);
			break;
		}
	}

	cout << endl << "Преобразованный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

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
	
	vector <int> list;
	int x = 1;
	double sr, sum = 0.0;

	cout << "Вводите элементы списка (0 - конец списка): " << endl;

	while (x != 0) {
		cin >> x;
		list.push_back(x);
	}

	list.pop_back();

	cout << "Исходный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
		if (i != 1 && i != 2) {
			sum += list[i];
		}
	}

	sr = sum / (list.size() - 2);
	cout << endl << "Среднее арифметическое элементов списка (без 2 и 3 элементов) равно " << sr;

	return 0;
}



/*Создать линейный однонаправленный список из вещественных 
чисел. Удалить из списка первый элемент меньший по модулю 5.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	vector <double> list;

	double x = 1;

	cout << "Вводите элементы списка (0 - конец списка): " << endl;

	while (x != 0) {
		cin >> x;
		list.push_back(x);
	}

	list.pop_back();

	cout << "Исходный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

	for (int i = 0; i < list.size(); i++) {
		if (abs(list[i]) < 5) {
			auto iter = list.cbegin();
			list.erase(iter + i);
			break;
		}
	}

	cout << endl << "Преобразованный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

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

	vector <double> list;

	double x = 1, sum = 0, number = 0;

	cout << "Вводите элементы списка (0 - конец списка): " << endl;

	while (x != 0) {
		cin >> x;
		list.push_back(x);
	}

	list.pop_back();

	cout << "Исходный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

	for (int i = 0; i < list.size(); i++) {
		if (list[i] <= 15) {
			sum += list[i];
			number++;
		}

		if (list[i] > 25) {
			auto iter = list.cbegin();
			list.erase(iter + i);
		}
	}

	cout << endl << "Среднее арифметическое элементов списка, меньших либо равных 15 равно: " << sum / number;

	cout << endl << "Преобразованный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

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

vector <double> list;

double Next(int i) {
	return list[i++];
}

double Prev(int i) {
	return list[i--];
}


int main() {
	setlocale(LC_ALL, "Russian");

	double x = 1;

	cout << "Вводите элементы списка (0 - конец списка): " << endl;

	while (x != 0) {
		cin >> x;
		list.push_back(x);
	}

	list.pop_back();


	cout << "Исходный список: ";
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}

	cout << endl << "Обратный список: ";

	int i = list.size() - 1;
	while (i != -1) {
		cout << Prev(i) << " ";
		i--;
	}
	return 0;
}
