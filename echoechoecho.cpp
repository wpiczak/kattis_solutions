#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    std::cout << input << " " << input << " " << input;

    return 0;
}
