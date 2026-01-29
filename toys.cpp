#include <iostream>

int solve(const int n, const int k) {
    if (n == 1) return 0;
    return (solve(n - 1, k) + k) % n;
}

int main() {
    int n;
    int k;
    std::cin >> n >> k;

    std::cout << solve(n, k);

    return 0;
}
