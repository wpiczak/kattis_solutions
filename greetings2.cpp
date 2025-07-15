#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    std::string e = input.substr(1, input.length() - 2);
    std::cout << 'h' << e << e << 'y';

    return 0;
}
