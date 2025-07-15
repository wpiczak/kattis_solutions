#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, s;
    std::cin >> r >> s;
    std::cout << (2 * s - r);

    return 0;
}