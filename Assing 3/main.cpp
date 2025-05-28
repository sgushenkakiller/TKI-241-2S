#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>

/**
 * @brief Записывает все уникальные числа, находящиеся во второй половине вектора, но отсутствующие в первой половине, в файл.
 * @param name Имя выходного текстового файла.
 * @param V Входной вектор с четным количеством элементов.
 */
void writeUniqueFromSecondHalf(const std::string& name, const std::vector<int>& V) {
    if (V.size() % 2 != 0) {
        std::cerr << "Ошибка: вектор должен содержать четное количество элементов." << std::endl;
        return;
    }

    size_t mid = V.size() / 2;


    std::set<int, std::greater<int>> firstHalf(V.begin(), V.begin() + mid);
    std::set<int, std::greater<int>> secondHalf(V.begin() + mid, V.end());
    std::set<int, std::greater<int>> difference;

   
    std::set_difference(
        secondHalf.begin(), secondHalf.end(),
        firstHalf.begin(), firstHalf.end(),
        std::inserter(difference, difference.begin()),
        std::greater<int>()
    );

    
    std::ofstream outFile(name);
    if (!outFile) {
        std::cerr << "Ошибка при открытии файла: " << name << std::endl;
        return;
    }

    std::ostream_iterator<int> output(outFile, "\n");
    std::copy(difference.begin(), difference.end(), output);
}

/**
 * @return 1 в случае успеха, иначе - 0
 */
int main() {
    std::string filename;
    std::vector<int> V;
    int x;

    std::cout << "Введите имя выходного файла: ";
    std::cin >> filename;

    std::cout << "Введите четное количество целых чисел: ";
    while (std::cin >> x) {
        V.push_back(x);
    }

    writeUniqueFromSecondHalf(filename, V);
    return 0;
}
