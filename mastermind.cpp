#include <array>
#include <iostream>

int main() {
    std::array<int, 26> frequency{};

    int length;
    std::cin >> length;

    std::string code;
    std::string guess;
    std::cin >> code >> guess;

    int r = 0;
    for (int i = 0; i < length; ++i) {
        if (code[i] == guess[i]) {
            guess[i] = '-';
            ++r;
        } else ++frequency[code[i] - 'A'];
    }

    int s = 0;
    for (int i = 0; i < length; ++i) {
        if (guess[i] == '-') continue;
        if (frequency[guess[i] - 'A'] > 0) {
            --frequency[guess[i] - 'A'];
            ++s;
        }
    }

    std::cout << r << ' ' << s;

    return 0;
}
