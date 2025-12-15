#include <array>
#include <iostream>

int main() {
    int participant_count;
    std::cin >> participant_count;

    std::array<int, 6> frequency{};
    std::array<int, 6> winner{};

    for (int i = 0; i < participant_count; ++i) {
        int value;
        std::cin >> value;
        value--;

        ++frequency[value];
        winner[value] = i + 1;
    }

    for (int i = 5; i >= 0; --i) {
        if (frequency[i] == 1) {
            std::cout << winner[i] << '\n';
            return 0;
        }
    }

    std::cout << "none";

    return 0;
}
