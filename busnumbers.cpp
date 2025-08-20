#include <array>
#include <iomanip>
#include <iostream>

int first_bus(int index, const std::array<bool, 1001>& buses) {
    while (!buses[index] && index < 1001) ++index;
    return index;
}

int last_bus(int index, const std::array<bool, 1001>& buses) {
    while (buses[index + 1] && index + 1 < 1001) ++index;
    return index;
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::array<bool, 1001> buses{};
    for (int i = 0; i < n; ++i) {
        int number;
        std::cin >> number;
        buses[number] = true;
    }

    int first = first_bus(0, buses);
    while (first < 1001) {
        const int last = last_bus(first, buses);
        if (first == last)
            std::cout << first << ' ';
        else if (first == last - 1)
            std::cout << first << ' ' << last << ' ';
        else std::cout << first << '-' << last << ' ';

        first = first_bus(last + 1, buses);
    }

    return 0;
}
