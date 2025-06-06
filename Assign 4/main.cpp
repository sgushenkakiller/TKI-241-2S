#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @class LessAbs
 * @brief Функциональный объект для сравнения абсолютных значений двух чисел.
 */
class LessAbs {
public:
    bool operator()(int a, int b) const {
        return std::abs(a) < std::abs(b);
    }
};

/**
 * @brief Подсчитывает количество элементов вектора, абсолютное значение которых меньше или равно K.
 * @param K Положительное целое число, с которым сравниваются абсолютные значения элементов.
 * @param V Входной вектор целых чисел.
 * @return Количество элементов, удовлетворяющих условию |x| ≤ K.
 */
int countElementsWithAbsLEK(int K, const std::vector<int>& V) {
    if (K <= 0) {
        std::cerr << "Ошибка: K должно быть положительным." << std::endl;
        return 0;
    }

    LessAbs lessAbs;

    auto predicate = [K, lessAbs](int x) {
        return !lessAbs(K, x);
        };

    return std::count_if(V.begin(), V.end(), predicate);
}

/**
 * @brief 
 * @return 1 в случае успеха, иначе - 0
 * 
 */
int main() {
    int k;
    std::cout << "Введите положительное число K: ";
    std::cin >> k;

    std::cout << "Введите элементы вектора:\n";

    std::istream_iterator<int> in_it(std::cin), end;
    std::vector<int> V(in_it, end);
    int result = countElementsWithAbsLEK(k, V);

    std::cout << "Количество элементов, для которых |x| ≤ " << k << ": " << result << std::endl;

    return 0;
}
