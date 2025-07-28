#include <array>
#include <iostream>

void print(const std::array<int, 5>& numbers) {
    std::cout << numbers[0];
    for (int i = 1; i < 5; ++i) std::cout << ' ' << numbers[i];
    std::cout << '\n';
}

void bubble_sort(std::array<int, 5>& numbers) {
    for (int i = 1; i < 5; ++i) {
        for (int j = 0; j < 5 - i; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                print(numbers);
            }
        }
    }
}

int main() {
    std::array<int, 5> numbers{};
    for (int i = 0; i < 5; ++i) std::cin >> numbers[i];
    bubble_sort(numbers);

    return 0;
}
