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

int main() {
    std::vector<int> V = { 1, 2, 3, 4, 5, 6, 7, 8 }; 
    std::string filename = "output.txt";

    writeUniqueFromSecondHalf(filename, V);

    return 0;
}
