#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    if (input[0] == '5' && input[1] == '5' && input[2] == '5')
        std::cout << 1;
    else std::cout << 0;

    return 0;
}
