#include <algorithm>
#include <iostream>
#include <vector>

bool case_1(const std::vector<int>& array) {
    std::size_t i = 0;
    std::size_t j = array.size() - 1;
    while (i < j) {
        if (array[i] + array[j] == 7777) return true;
        if (array[i] + array[j] < 7777) ++i;
        if (array[i] + array[j] > 7777) --j;
    }

    return false;
}

bool case_2(const std::vector<int>& array) {
    for (std::size_t i = 0; i + 1 < array.size(); ++i)
        if (array[i] == array[i + 1]) return false;
    return true;
}

int case_3(const std::vector<int>& array) {
    int value = array[0];
    int frequency = 1;
    for (std::size_t i = 1; i < array.size(); ++i) {
        if (frequency > array.size() / 2) return value;
        if (array[i] == value) ++frequency;
        else {
            value = array[i];
            frequency = 1;
        }
    }

    return -1;
}

void case_4(const std::vector<int>& array) {
    if (array.size() % 2 == 0) {
        std::size_t i = array.size() / 2;
        std::cout << array[i - 1] << ' ' << array[i];
    } else std::cout << array[array.size() / 2];
}

void case_5(const std::vector<int>& array) {
    bool is_first = true;
    for (const int& integer : array) {
        if (integer >= 100 && integer <= 999) {
            if (is_first) is_first = false;
            else std::cout << ' ';
            std::cout << integer;
        } else if (integer >= 1000) return;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    int action;
    std::cin >> size >> action;

    std::vector<int> numbers(size);
    for (int i = 0; i < size; ++i)
        std::cin >> numbers[i];

    std::sort(numbers.begin(), numbers.end());

    if (action == 1) {
        if (case_1(numbers)) std::cout << "Yes";
        else std::cout << "No";
    } else if (action == 2) {
        if (case_2(numbers)) std::cout << "Unique";
        else std::cout << "Contains duplicate";
    } else if (action == 3) std::cout << case_3(numbers);
    else if (action == 4) case_4(numbers);
    else if (action == 5) case_5(numbers);

    return 0;
}
