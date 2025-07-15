#include <array>
#include <iostream>
#include <limits>

int main() {
    std::array<std::string, 26> encoding = {
        "2",
        "22",
        "222",
        "3",
        "33",
        "333",
        "4",
        "44",
        "444",
        "5",
        "55",
        "555",
        "6",
        "66",
        "666",
        "7",
        "77",
        "777",
        "7777",
        "8",
        "88",
        "888",
        "9",
        "99",
        "999",
        "9999"
    };

    int case_count;
    std::cin >> case_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < case_count; ++i) {
        std::string message;
        std::getline(std::cin, message);

        std::cout << "Case #" << (i + 1) << ": ";

        char last_key = '?';
        for (const auto& letter : message) {
            if (letter == ' ') {
                if (last_key == '0') std::cout << ' ';
                std::cout << '0';
                last_key = '0';
            } else {
                if (last_key == encoding[letter - 'a'][0]) std::cout << ' ';
                std::cout << encoding[letter - 'a'];
                last_key = encoding[letter - 'a'][0];
            }
        }

        std::cout << '\n';
    }

    return 0;
}
