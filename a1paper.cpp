#include <cmath>
#include <iomanip>
#include <iostream>

long double length(const int n) {
    return sqrt(sqrt(2)) / pow(sqrt(2), n);
}

int main() {
    int n;
    std::cin >> n;

    bool possible = false;
    long double tape_needed = length(2);

    int required = 2;
    for (int i = 2; i <= n; ++i) {
        int count;
        std::cin >> count;

        if (count >= required) {
            possible = true;
            break;
        }

        required -= count;
        tape_needed += length(i + 1) * required;
        required *= 2;
    }

    if (possible) std::cout << std::setprecision(16) << tape_needed;
    else std::cout << "impossible";

    return 0;
}
