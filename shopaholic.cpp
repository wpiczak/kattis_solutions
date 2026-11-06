#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i)
        std::cin >> prices[i];

    std::ranges::sort(prices, std::greater());

    long long total_discount = 0;
    for (int i = 2; i < n; i += 3)
        total_discount += prices[i];

    std::cout << total_discount;

    return 0;
}
