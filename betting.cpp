#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double a;
    std::cin >> a;
    std::cout << 100 / a << '\n';
    std::cout << 100 / (100 - a) << '\n';

    return 0;
}
