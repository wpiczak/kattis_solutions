#include <iostream>

bool is_vowel(const char letter) {
    return letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U';
}

bool is_pleasant(const std::string& word, const int index) {
    if (index < 2) return true;
    if (is_vowel(word[index - 2]) && is_vowel(word[index - 1]) && is_vowel(word[index])) return false;
    if (!is_vowel(word[index - 2]) && !is_vowel(word[index - 1]) && !is_vowel(word[index])) return false;
    return true;
}

long long solve(std::string& word, const int index = 0) {
    if (index == word.length()) return word.contains('L') ? 1 : 0;
    if (word[index] != '_') return is_pleasant(word, index) ? solve(word, index + 1) : 0;

    long long result = 0;

    word[index] = 'A';
    if (is_pleasant(word, index)) result += 5 * solve(word, index + 1);

    word[index] = 'L';
    if (is_pleasant(word, index)) result += solve(word, index + 1);

    word[index] = 'Z';
    if (is_pleasant(word, index)) result += 20 * solve(word, index + 1);

    word[index] = '_';

    return result;
}

int main() {
    std::string word;
    std::cin >> word;

    std::cout << solve(word) << '\n';

    return 0;
}
