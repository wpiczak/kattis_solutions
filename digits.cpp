#include <bits/stdc++.h>

int main() {
    std::string input;
    std::getline(std::cin, input);
    while (input != "END") {
        int i = 1;
        while (input != "1") {
            input = std::to_string(input.length());
            i++;
        }
        std::cout << i << "\n";
        std::getline(std::cin, input);
    }
    return 0;
}
