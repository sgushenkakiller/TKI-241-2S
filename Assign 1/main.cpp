#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>

/**
 * @brief Читает целые числа из файла и выводит их на экран
 * @param filename Имя файла для чтения
 */
void printNumbersFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    // Используем istream_iterator для чтения чисел из файла
    std::istream_iterator<std::string> input(file);
    std::istream_iterator<std::string> end;

    // Используем ostream_iterator для вывода чисел в cout
    std::ostream_iterator<std::string> output(std::cout, " ");

    // Копируем числа из файла в вывод с помощью алгоритма copy
    std::copy(input, end, output);

    std::cout << std::endl;
    file.close();
}

/**
 * @brief Точка входа в программу
 * @return 0 в случае успешного выполнения, 1 в случае ошибки
 */
int main() {
    try {
        const std::string filename = "numbers.txt"; // Имя файла с числами

        printNumbersFromFile(filename);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}