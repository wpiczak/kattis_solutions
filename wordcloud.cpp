#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int max_width;
    int word_count;
    std::cin >> max_width >> word_count;

    int case_index = 0;
    while (max_width != 0 || word_count != 0) {
        std::vector<std::pair<std::string, int>> words;

        for (int i = 0; i < word_count; ++i) {
            std::string word;
            int frequency;
            std::cin >> word >> frequency;

            if (frequency >= 5) words.emplace_back(word, frequency);
        }

        std::sort(words.begin(), words.end());

        const int max_frequency = std::max_element(words.begin(), words.end(), [](const auto& x, const auto& y) {
            return x.second < y.second;
        })->second;

        int total_height = 0;
        int current_height = 0;
        int current_width = 0;

        for (const auto& [word, frequency] : words) {
            const int height = 8 + std::ceil(40.0 * (frequency - 4.0) / (max_frequency - 4.0));
            const int width = std::ceil(9.0 * word.length() * height / 16.0);

            if (current_width + width > max_width) {
                total_height += current_height;

                current_width = width + 10;
                current_height = height;
            } else {
                current_width += width + 10;
                if (height > current_height) current_height = height;
            }
        }

        total_height += current_height;

        std::cout << "CLOUD " << ++case_index << ": " << total_height << '\n';
        std::cin >> max_width >> word_count;
    }

    return 0;
}
