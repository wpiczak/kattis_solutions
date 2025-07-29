#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> words;
    bool is_first = true;
    do {
        words.clear();

        int max_length = 0;
        std::string input;
        while (std::getline(std::cin, input) && !input.empty()) {
            std::reverse(input.begin(), input.end());
            words.push_back(input);
            if (input.length() > max_length) max_length = static_cast<int>(input.length());
        }

        if (is_first) is_first = false;
        else if (!words.empty()) std::cout << '\n';

        std::sort(words.begin(), words.end());
        for (auto& word : words) {
            std::reverse(word.begin(), word.end());
            std::cout << std::setw(max_length) << word << '\n';
        }
    } while (!words.empty());

    return 0;
}
