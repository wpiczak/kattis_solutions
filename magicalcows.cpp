#include <array>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cow_capacity;
    int initial_farm_count;
    int visit_count;

    std::cin >> cow_capacity >> initial_farm_count >> visit_count;

    std::vector<std::size_t> farm_counts(cow_capacity + 1);
    for (int i = 0; i < initial_farm_count; ++i) {
        int count;
        std::cin >> count;

        ++farm_counts[count];
    }

    std::array<std::size_t, 51> cow_counts{};
    for (int i = 0; i < 50; ++i) {
        cow_counts[i] = std::accumulate(farm_counts.begin(), farm_counts.end(), 0ULL);

        std::vector<std::size_t> new_farm_counts(cow_capacity + 1);
        for (int j = 1; j <= cow_capacity; ++j) {
            if (2 * j <= cow_capacity)
                new_farm_counts[2 * j] += farm_counts[j];
            else new_farm_counts[j] += 2 * farm_counts[j];
        }

        farm_counts = std::move(new_farm_counts);
    }
    cow_counts[50] = std::accumulate(farm_counts.begin(), farm_counts.end(), 0ULL);

    for (int i = 0; i < visit_count; ++i) {
        int day;
        std::cin >> day;
        std::cout << cow_counts[day] << '\n';
    }

    return 0;
}
