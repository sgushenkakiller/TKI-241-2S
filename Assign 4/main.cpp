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
 * @brief Главная функция: считывает данные с ввода и вызывает алгоритм подсчета.
 * @return Код завершения программы (0 — успех).
 */
int main() {
    int K;
    std::cout << "Введите положительное число K: ";
    std::cin >> K;

    std::cout << "Введите элементы вектора (Ctrl+D / Ctrl+Z для завершения): ";

    std::vector<int> V;
    int x;
    while (std::cin >> x) {
        V.push_back(x);
    }

    int result = countElementsWithAbsLEK(K, V);

    std::cout << "Количество элементов, для которых |x| ≤ " << K << ": " << result << std::endl;

    return 0;
}
