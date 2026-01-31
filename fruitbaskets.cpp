#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

long long invalid_basket_weight(
    const std::vector<int>& weights,
    const long long weight = 0,
    const int index = 0
) {
    if (weight >= 200) return 0;

    long long result = weight;
    for (int i = index; i < weights.size(); ++i)
        result += invalid_basket_weight(weights, weight + weights[i], i + 1);

    return result;
}

int main() {
    int fruit_count;
    std::cin >> fruit_count;

    std::vector<int> weights(fruit_count);
    for (int i = 0; i < fruit_count; ++i)
        std::cin >> weights[i];
    std::ranges::sort(weights);

    const long long basket_count = 1LL << fruit_count;
    const long long total_basket_weight = basket_count * std::accumulate(weights.begin(), weights.end(), 0LL) / 2;

    std::cout << total_basket_weight - invalid_basket_weight(weights);

    return 0;
}
