#include <iomanip>
#include <iostream>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string message;
    std::cin >> message;

    int white_space = 0;
    int lowercase_letters = 0;
    int uppercase_letters = 0;
    int symbols = 0;

    for (const char chr : message) {
        if (chr == '_') ++white_space;
        else if (chr >= 'a' && chr <= 'z') ++lowercase_letters;
        else if (chr >= 'A' && chr <= 'Z') ++uppercase_letters;
        else ++symbols;
    }

    const double total = white_space + lowercase_letters + uppercase_letters + symbols;

    std::cout << std::setprecision(16);
    std::cout << white_space / total << '\n';
    std::cout << lowercase_letters / total << '\n';
    std::cout << uppercase_letters / total << '\n';
    std::cout << symbols / total << '\n';

    return 0;
}
