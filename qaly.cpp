#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    double result;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        double q, y;
        std::cin >> q >> y;
        result += q * y;
    }
    std::cout << result;

    return 0;
}
