#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    long double distance;
    long double sag;
    std::cin >> distance >> sag;

    long double start = 0;
    long double end = 10e18;

    while (end - start > 10e-12) {
        const auto x = (start + end) / 2;
        if (x * std::cosh(distance / (2 * x)) - x > sag) start = x;
        else end = x;
    }

    const auto x = (start + end) / 2;
    std::cout << std::setprecision(16) << 2 * x * std::sinh(distance / (2 * x)) << '\n';

    return 0;
}
