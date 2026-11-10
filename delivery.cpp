#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int address_count;
    int capacity;
    std::cin >> address_count >> capacity;

    std::vector<int> locations(address_count);
    std::vector<int> delivery_counts(address_count);

    int center = 0;
    for (int i = 0; i < address_count; ++i) {
        std::cin >> locations[i] >> delivery_counts[i];
        if (locations[i] < 0) ++center;
    }

    int distance = 0;

    for (int i = 0; i < center;) {
        distance -= locations[i];

        int unused_capacity = capacity;
        while (i < center) {
            if (delivery_counts[i] <= unused_capacity) {
                unused_capacity -= delivery_counts[i];
                delivery_counts[i] = 0;
                ++i;
            } else {
                delivery_counts[i] -= unused_capacity;
                break;
            }
        }
    }

    for (int i = address_count - 1; i >= center;) {
        distance += locations[i];

        int unused_capacity = capacity;
        while (i >= center) {
            if (delivery_counts[i] <= unused_capacity) {
                unused_capacity -= delivery_counts[i];
                delivery_counts[i] = 0;
                --i;
            } else {
                delivery_counts[i] -= unused_capacity;
                break;
            }
        }
    }

    std::cout << 2 * distance;

    return 0;
}
