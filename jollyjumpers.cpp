#include <algorithm>
#include <iostream>
#include <vector>

bool is_jolly_sequence(const std::size_t sequence_length) {
    std::vector<bool> differences(sequence_length - 1);

    int previous;
    std::cin >> previous;
    for (int i = 1; i < sequence_length; ++i) {
        int current;
        std::cin >> current;

        const int delta = std::abs(current - previous);
        if (delta > 0) differences[delta - 1] = true;

        previous = current;
    }

    return std::all_of(differences.begin(), differences.end(), [](const auto& x) { return x; });
}

int main() {
    int sequence_length;
    std::cin >> sequence_length;

    while (std::cin) {
        if (is_jolly_sequence(sequence_length)) std::cout << "Jolly\n";
        else std::cout << "Not jolly\n";

        std::cin >> sequence_length;
    }

    return 0;
}
