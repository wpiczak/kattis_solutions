#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t, result = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> t;
        if (t < 0) result++;
    }
    std::cout << result;

    return 0;
}
