#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k = 0, result = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int j;
        std::cin >> j;

        if (j == -1) continue;
        result += j;
        k++;
    }
    std::cout << std::setprecision(16) << (static_cast<double>(result) / k);

    return 0;
}