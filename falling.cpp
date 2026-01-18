#include <iostream>

long long sqrt(const long long n) {
    long long p = 1;
    while (n / p > 0) p <<= 2;

    long long result = 0;
    while (p > 1) {
        p >>= 2;
        result <<= 1;
        if ((result + 1) * (result + 1) <= n / p)
            result += 1;
    }

    return result;
}

int main() {
    long long distance;
    std::cin >> distance;

    for (long long n = sqrt(distance - 1) + 1; n <= distance; ++n) {
        if (const long long m = sqrt(n * n - distance); n * n - m * m == distance) {
            std::cout << m << ' ' << n << '\n';
            return 0;
        }
    }

    std::cout << "impossible\n";

    return 0;
}
