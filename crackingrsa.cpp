#include <iostream>

int main() {
    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int n;
        int e;
        std::cin >> n >> e;

        int p = 2;
        while (n % p != 0) ++p;

        const int totient = (p - 1) * (n / p - 1);
        for (long long d = 1; d < 1'000'000; ++d) {
            if (d * e % totient == 1) {
                std::cout << d << '\n';
                break;
            }
        }
    }

    return 0;
}
