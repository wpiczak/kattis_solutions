#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<char, std::pair<int, int>> position = {
    {'q', {0, 0}},
    {'w', {0, 1}},
    {'e', {0, 2}},
    {'r', {0, 3}},
    {'t', {0, 4}},
    {'y', {0, 5}},
    {'u', {0, 6}},
    {'i', {0, 7}},
    {'o', {0, 8}},
    {'p', {0, 9}},
    {'a', {1, 0}},
    {'s', {1, 1}},
    {'d', {1, 2}},
    {'f', {1, 3}},
    {'g', {1, 4}},
    {'h', {1, 5}},
    {'j', {1, 6}},
    {'k', {1, 7}},
    {'l', {1, 8}},
    {'z', {2, 0}},
    {'x', {2, 1}},
    {'c', {2, 2}},
    {'v', {2, 3}},
    {'b', {2, 4}},
    {'n', {2, 5}},
    {'m', {2, 6}}
};

int distance(const char& x, const char& y) {
    return std::abs(position[x].first - position[y].first) + std::abs(position[x].second - position[y].second);
}

int distance(const std::string& first, const std::string& second) {
    int result = 0;
    for (int i = 0; i < first.length(); ++i)
        result += distance(first[i], second[i]);
    return result;
}

int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        std::string typed_word;
        std::cin >> typed_word;

        int entry_count;
        std::cin >> entry_count;

        std::vector<std::pair<int, std::string>> entries;
        for (int j = 0; j < entry_count; ++j) {
            std::string word;
            std::cin >> word;

            entries.emplace_back(distance(word, typed_word), word);
        }

        std::sort(entries.begin(), entries.end());

        for (const auto& [distance, word] : entries)
            std::cout << word << ' ' << distance << '\n';
    }

    return 0;
}
