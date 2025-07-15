#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::cin >> input;
    bool found = false;
    for (int i = 0; i < input.length() - 1; i++)
        if (input[i] == 's' && input[i + 1] == 's')
            found = true;
    if (found) std::cout << "hiss";
    else std::cout << "no hiss";

    return 0;
}
