#include <iostream>
#include <set>

constexpr long long sqrt(const long long number) {
    if (number < 2) return number;

    short shift = 2;
    while (number >> shift != 0)
        shift += 2;

    long long result = 0;
    while (shift >= 0) {
        result = result << 1;

        const long long temp = result ^ 1;
        if (temp * temp <= number >> shift)
            result = temp;

        shift -= 2;
    }

    return result;
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    std::set<long long> result;
    for (int i = 1; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            result.insert(i - 1);
            result.insert(n / i - 1);
        }
    }

    bool is_first = true;
    for (const long long m : result) {
        if (is_first) is_first = false;
        else std::cout << ' ';
        std::cout << m;
    }

    return 0;
}
