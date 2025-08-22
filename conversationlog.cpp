#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int message_count;
    std::cin >> message_count;

    std::unordered_map<std::string, std::unordered_set<std::string>> usage;
    std::unordered_map<std::string, int> frequency;
    std::unordered_set<std::string> users;

    for (int i = 0; i < message_count; ++i) {
        std::string user;
        std::cin >> user;

        users.insert(user);

        while (std::cin.peek() != '\n') {
            std::string word;
            std::cin >> word;

            auto& users_of_current_word = usage.insert({word, std::unordered_set<std::string>{}}).first->second;
            users_of_current_word.insert(user);

            frequency.insert({word, 0}).first->second += 1;
        }
    }

    std::vector<std::pair<std::string, int>> result;
    for (const auto& [word, frequency] : frequency)
        if (usage[word].size() == users.size())
            result.emplace_back(word, frequency);

    std::sort(
        result.begin(), result.end(), [](const auto& x, const auto& y) {
            return x.second > y.second || (x.second == y.second && x.first < y.first);
        }
    );

    if (result.empty()) std::cout << "ALL CLEAR";
    else for (const auto& [word, _] : result) std::cout << word << '\n';

    return 0;
}
