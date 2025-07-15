#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int g, t, n, j, weight = 0;
    std::cin >> g >> t >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> j;
        weight += j;
    }
    std::cout << (g - t) * 9 / 10 - weight;

    return 0;
}
