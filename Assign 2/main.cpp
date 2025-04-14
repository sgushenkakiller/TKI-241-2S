#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

/**
 * @brief Обрабатывает список чисел согласно заданию
 * @param numbers Вектор целых чисел (количество должно делиться на 3
 */
void processNumbers(const std::vector<int>& numbers) {
    if (numbers.size() % 3 != 0) {
        throw std::invalid_argument("Количество чисел должно делиться на 3");
    }

    // Создаем список с использованием istream_iterator (имитация)
    std::list<int> L(numbers.begin(), numbers.end());

    // Вычисляем размер одной трети
    const size_t third = L.size() / 3;

    // Итераторы для разделения списка на трети
    auto first_third_end = L.begin();
    std::advance(first_third_end, third);

    auto second_third_end = first_third_end;
    std::advance(second_third_end, third);

   
    std::cout << "Первая треть (прямой порядок): ";
    std::copy(L.begin(), first_third_end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    
    std::cout << "Вторая треть (обратный порядок): ";
    std::copy(std::reverse_iterator<decltype(second_third_end)>(second_third_end),
        std::reverse_iterator<decltype(first_third_end)>(first_third_end),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

   
    std::cout << "Последняя треть (обратный порядок): ";
    std::copy(L.rbegin(), std::reverse_iterator<decltype(second_third_end)>(second_third_end),
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

/**
 * @brief Точка входа в программу
 * @return 0 в случае успешного выполнения, 1 в случае ошибки
 */
int main() {
    try {
        // Пример входных данных (должно быть кратно 3)
        std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        
        processNumbers(numbers);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}