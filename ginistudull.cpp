#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<double> income(n);
    for (int i = 0; i < n; ++i)
        std::cin >> income[i];

    std::sort(income.begin(), income.end());

    double a = 0;
    double b = 0;
    for (int i = 0; i < n; ++i) {
        a += i * income[i];
        b += income[i];
    }

    a *= 2;
    b *= static_cast<double>(n);

    const double gini_coefficient = a / b - static_cast<double>(n - 1) / static_cast<double>(n);
    std::cout << std::setprecision(16) << gini_coefficient;

    return 0;
}
