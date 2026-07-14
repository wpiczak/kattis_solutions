#include <iostream>

int main() {
    std::string text; std::cin >> text;
    std::cout << std::string(text.rbegin(), text.rend()) << '\n';

    return 0;
}
