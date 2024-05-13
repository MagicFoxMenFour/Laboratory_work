/*Дан файл вещественных чисел a.txt Найти количество положительных 
элементов и произведение элементов меньших 1 и больших 0*/
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("a.txt");
    
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }
    
    double num;
    int countPositives = 0;
    double product = 1;
    
    while (file >> num) {
        if (num > 0) {
            countPositives++;
        }
        
        if (num < 1 && num > 0) {
            product *= num;
        }
    }
    
    file.close();
    
    std::cout << "Количество положительных элементов: " << countPositives << std::endl;
    std::cout << "Произведение элементов меньших 1 и больших 0: " << product << std::endl;
    
    return 0;
}


/*Дано 2 файла вещественных чисел а.txt и b.txt. 
Найти произведение отрицательных элементов двух файлов*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file1("a.txt");
    ifstream file2("b.txt");

    float num1;
    float num2;
    double product = 1.0;

    if (file1.is_open() && file2.is_open()) {
        while (file1 >> num1 && file2 >> num2) {
            if (num1 < 0 && num2 < 0) {
                product *= num1 * num2;
            }
        }

        file1.close();
        file2.close();

        cout << "Произведение отрицательных элементов двух файлов: " << product << endl;
    }
    else {
        cout << "Не удалось открыть один из файлов." << endl;
    }

    return 0;
}


/*Из заданного входного файла считать символы и записать 
в новый файл только  большие буквы латинского алфавита.*/

#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");    
    std::ifstream inputFile("input.txt"); // Открываем входной файл для чтения
    std::ofstream outputFile("output.txt"); // Открываем выходной файл для записи

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка открытия входного файла\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Ошибка открытия выходного файла\n";
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            outputFile << ch; // Записываем только большие буквы
        }
    }

    inputFile.close(); // Закрываем входной файл
    outputFile.close(); // Закрываем выходной файл

    std::cout << "Программа успешно завершена\n";

    return 0;
}


/*Организовать файл целых чисел. Найти сумму 
элементов файла, номера которых кратны трем*/
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");    
    std::ifstream file("numbers.txt");
    if (!file) {
        std::cerr << "Ошибка открытия файла.";
        return 1;
    }

    int number, sum = 0, index = 1;
    while (file >> number) {
        if (index % 3 == 0) {
            sum += number;
        }
        index++;
    }

    file.close();

    std::cout << "Сумма элементов файла, номера которых кратны трем: " << sum << std::endl;

    return 0;
}


/*создать текстовый файл с произвольной информацией. 
Организовать просмотр содержимого файла. Организовать чтение и 
обработку данных из файла всоответствии с индивидуальным заданием. 
Сохранить полученные результаты в новый текстовый файл.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    int storagePeriod;
    string type;
    string releaseDate;
    int expirationDate;
};

void createFile(const string& fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << "Name;Price;Storage Period;Type;Release Date;Expiration Date\n";
        file.close();
        cout << "File " << fileName << " created successfully." << endl;
    }
    else {
        cout << "Error creating file " << fileName << endl;
    }
}

void addProductToFile(const string& fileName, const Product& product) {
    ofstream file(fileName, ios::app);
    if (file.is_open()) {
        file << product.name << ";" << product.price << ";" << product.storagePeriod << ";"
            << product.type << ";" << product.releaseDate << ";" << product.expirationDate << "\n";
        file.close();
        cout << "Product added to file " << fileName << " successfully." << endl;
    }
    else {
        cout << "Error adding product to file " << fileName << endl;
    }
}

void printFileContent(const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Error opening file " << fileName << endl;
    }
}

int main() {
    const string fileName = "products.txt";

    createFile(fileName);

    Product product1 = { "Apple", 1.5, 7, "Fruit", "2022-10-01", 10 };
    Product product2 = { "Milk", 2.0, 14, "Dairy", "2022-09-25", 7 };

    addProductToFile(fileName, product1);
    addProductToFile(fileName, product2);

    cout << "Content of file " << fileName << ":" << endl;
    printFileContent(fileName);

    // Reading and processing data from file

    // Saving results to new file
    const string newFileName = "processed_products.txt";
    // code for reading and processing data from file
    // code for saving results to new file

    return 0;
}


/*Дан файл f, компоненты которого являются целыми числами. 
Получить в файле g все компоненты файла f являющиеся чётными числами.*/
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");  
    std::ifstream inputFile("f.txt");
    std::ofstream outputFile("g.txt");

    if (!inputFile) {
        std::cerr << "Не удается открыть файл f.txt\n";
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Не удается создать файл g.txt\n";
        return 1;
    }

    int number;
    while (inputFile >> number) {
        if (number % 2 == 0) {
            outputFile << number << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}


/*В первом файле хранится k матриц размерности m × n, 
во втором - l матриц размерности m × n. Те матрицы из первого файла, 
сумма элементов главной диагонали которых равна 5, перенести в конец 
второго файла. Вывести на экран содержимое первого и второго файлов.*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int k, l, m, n;
    cout << "Введите количество матриц в первом файле: ";
    cin >> k;
    cout << "Введите количество матриц во втором файле: ";
    cin >> l;
    cout << "Введите размерность матриц (m x n): ";
    cin >> m >> n;

    // Открытие файлов для чтения и записи
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");
    ofstream tempFile("temp.txt");
    ofstream file2Append("file2.txt", ios::app);

    // Чтение матриц из первого файла
    for (int i = 0; i < k; i++) {
        vector<vector<int>> matrix(m, vector<int>(n));
        int sumDiagonal = 0;

        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                file1 >> matrix[j][l];
                if (j == l) {
                    sumDiagonal += matrix[j][l];
                }
            }
        }

        if (sumDiagonal == 5) {
            // Запись матрицы в конец второго файла
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < n; l++) {
                    file2Append << matrix[j][l] << " ";
                }
                file2Append << endl;
            }
        }
        else {
            // Запись матрицы во временный файл
            for (int j = 0; j < m; j++) {
                for (int l = 0; l < n; l++) {
                    tempFile << matrix[j][l] << " ";
                }
                tempFile << endl;
            }
        }
    }

    // Вывод содержимого первого файла
    cout << "Содержимое первого файла:" << endl;
    file1.clear();
    file1.seekg(0, ios::beg);
    char ch;
    while (file1.get(ch)) {
        cout << ch;
    }
    cout << " " << endl;
    // Вывод содержимого второго файла
    cout << "Содержимое второго файла:" << endl;
    file2.clear();
    file2.seekg(0, ios::beg);
    while (file2.get(ch)) {
        cout << ch;
    }

    // Закрытие файлов
    file1.close();
    file2.close();
    tempFile.close();
    file2Append.close();

    // Удаление временного файла и переименование его во второй файл
    remove("file2.txt");
    rename("temp.txt", "file2.txt");

    return 0;
}


/*Создать двухмерный массив целого типа размерностью 5×5. 
Ввестизначения для этого массива в StringGrid и записать в бинарный 
файлэлементы этого массива по столбцам. Переписать бинарный файл 
так,чтобы значения элементов каждого столбца были увеличены в два раза.
Распечатать этот массив до и после изменения данных в файле.*/
#include <iostream>
#include <fstream>

int main() {
    setlocale(LC_ALL, "Russian");
    const int rows = 5;
    const int cols = 5;
    int array[rows][cols];

    // Ввод значений в двумерный массив
    std::cout << "Введите значения для двумерного массива 5x5:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }

    // Запись в бинарный файл по столбцам
    std::ofstream outFile("data.bin", std::ios::binary);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            outFile.write(reinterpret_cast<char*>(&array[i][j]), sizeof(int));
        }
    }
    outFile.close();

    // Вывод массива до изменения данных в файле
    std::cout << "Массив до изменения данных в файле:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Увеличение значений элементов каждого столбца в два раза
    std::ifstream inFile("data.bin", std::ios::binary);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            int value;
            inFile.read(reinterpret_cast<char*>(&value), sizeof(int));
            value *= 2;
            array[i][j] = value;
        }
    }
    inFile.close();

    // Вывод массива после изменения данных в файле
    std::cout << "Массив после изменения данных в файле:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}


/*Создать бинарный файл, компонентами которого является структура,содержащая следующие поля:
− название турпоездки;
− стоимость путевки;
− количество групп отправления;
− количество в группе от одной организации (массив, не менее чем
из 5 групп)
− общая стоимость путевки для каждой группы (массив, не менее
чем для 5 групп).
Переписать бинарный файл так, чтобы стоимость путевки была бы снижена на 5% для группы, состоящей из 10 человек от одной организации.*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TourPackage {
    string name;
    float cost;
    int departureGroupsCount;
    int groupSize[5];
    float groupCost[5];
};

int main() {
    TourPackage package;
    
    // Создание бинарного файла и запись данных
    ofstream outFile("tour_packages.bin", ios::out | ios::binary);
    
    package.name = "Отпуск в горах";
    package.cost = 1000.0;
    package.departureGroupsCount = 5;
    
    for (int i = 0; i < 5; ++i) {
        package.groupSize[i] = 10;
        package.groupCost[i] = 1000.0;
    }
    
    outFile.write((char*)&package, sizeof(package));
    outFile.close();
    
    // Изменение стоимости путевки для группы из 10 человек
    ifstream inFile("tour_packages.bin", ios::in | ios::binary);
    ofstream tempFile("temp.bin", ios::out | ios::binary);
    
    while (inFile.read((char*)&package, sizeof(package))) {
        for (int i = 0; i < 5; ++i) {
            if (package.groupSize[i] == 10) {
                package.groupCost[i] *= 0.95; // Снижение стоимости на 5%
            }
        }
        
        tempFile.write((char*)&package, sizeof(package));
    }
    
    inFile.close();
    tempFile.close();
    
    remove("tour_packages.bin");
    rename("temp.bin", "tour_packages.bin");
    
    return 0;
}
