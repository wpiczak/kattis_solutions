#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    while (n != 0) {
        std::array<char, 32> bits{};
        std::fill(bits.begin(), bits.end(), '?');

        while (n--) {
            std::string instruction;
            std::cin >> instruction;

            if (instruction == "CLEAR") {
                int i;
                std::cin >> i;
                bits[i] = '0';
            } else if (instruction == "SET") {
                int i;
                std::cin >> i;
                bits[i] = '1';
            } else if (instruction == "OR") {
                int i, j;
                std::cin >> i >> j;

                if (bits[i] == '1' || bits[j] == '1') bits[i] = '1';
                else if (bits[i] == '0' && bits[j] == '0') bits[i] = '0';
                else bits[i] = '?';
            } else if (instruction == "AND") {
                int i, j;
                std::cin >> i >> j;

                if (bits[i] == '0' || bits[j] == '0') bits[i] = '0';
                else if (bits[i] == '1' && bits[j] == '1') bits[i] = '1';
                else bits[i] = '?';
            }
        }

        std::reverse(bits.begin(), bits.end());
        for (const char& bit : bits) std::cout << bit;
        std::cout << '\n';

        std::cin >> n;
    }

    return 0;
}
