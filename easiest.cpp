#include <iostream>

int sum_digits(int n) {
    int result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) break;

        int p = 11;
        while (sum_digits(n * p) != sum_digits(n)) ++p;

        std::cout << p << '\n';
    }

    return 0;
}
