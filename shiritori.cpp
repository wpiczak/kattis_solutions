#include <iostream>
#include <unordered_set>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::unordered_set<std::string> words;
    std::string word;
    std::cin >> word;
    words.insert(word);

    bool lost = false;
    char next_char = word.at(word.length() - 1);
    for (int i = 1; i < n; ++i) {
        std::cin >> word;
        if (word.at(0) != next_char || words.count(word) != 0) {
            lost = true;
            std::cout << "Player " << (i % 2 + 1) << " lost";
            break;
        }
        next_char = word.at(word.length() - 1);
        words.insert(word);
    }

    if (!lost) std::cout << "Fair Game";

    return 0;
}
