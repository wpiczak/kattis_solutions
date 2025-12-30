#include <algorithm>
#include <iostream>

int main() {
    std::string word;
    std::cin >> word;

    std::string result;
    for (int i = 1; i < word.length(); ++i) {
        for (int j = i + 1; j < word.length(); ++j) {
            std::string first(word.begin(), word.begin() + i);
            std::string second(word.begin() + i, word.begin() + j);
            std::string third(word.begin() + j, word.end());

            std::ranges::reverse(first);
            std::ranges::reverse(second);
            std::ranges::reverse(third);

            const std::string new_word = first + second + third;
            if (result.empty() || new_word < result) result = new_word;
        }
    }

    std::cout << result << '\n';

    return 0;
}
