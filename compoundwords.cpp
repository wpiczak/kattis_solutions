#include <iostream>
#include <set>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word)
        words.push_back(word);

    std::set<std::string> result;
    for (int i = 0; i < words.size(); ++i)
        for (int j = 0; j < words.size(); ++j)
            if (i != j)
                result.insert(words[i] + words[j]);

    for (const auto& compound_word : result)
        std::cout << compound_word << '\n';

    return 0;
}
