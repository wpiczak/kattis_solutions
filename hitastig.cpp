#include <iostream>

int main() {
    int n;
    std::cin >> n;

    long long max = -1e18;
    long long min = 1e18;

    for (int i = 0; i < n; ++i) {
        long long temp;
        std::cin >> temp;

        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }

    std::cout << max << ' ' << min;

    return 0;
}
