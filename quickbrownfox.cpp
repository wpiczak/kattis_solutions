#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < case_count; ++i) {
        std::array<int, 26> frequency{};
        std::string input;
        std::getline(std::cin, input);

        for (const char chr : input) {
            if (chr >= 'a' && chr <= 'z') ++frequency[chr - 'a'];
            if (chr >= 'A' && chr <= 'Z') ++frequency[chr - 'A'];
        }

        const bool is_pangram = std::all_of(
            frequency.begin(),
            frequency.end(),
            [](const int n) { return n > 0; }
        );

        if (is_pangram) std::cout << "pangram\n";
        else {
            std::cout << "missing ";
            for (int j = 0; j < 26; ++j)
                if (frequency[j] == 0) std::cout << static_cast<char>('a' + j);
            std::cout << '\n';
        }
    }

    return 0;
}
