#include <iostream>

int main() {
    unsigned long long tiling_count[16];
    tiling_count[0] = 1;
    tiling_count[1] = 3;

    for (int i = 2; i < 16; i++)
        tiling_count[i] = 4 * tiling_count[i - 1] - tiling_count[i - 2];

    int n;
    std::cin >> n;
    while (n != -1) {
        if (n & 1) std::cout << 0 << '\n';
        else std::cout << tiling_count[n / 2] << '\n';
        std::cin >> n;
    }

    return 0;
}
