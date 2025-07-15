#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, j, result = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> j;
        result += j;
    }
    std::cout << (result - n + 1);

    return 0;
}
