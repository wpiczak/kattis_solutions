#include <iostream>
#include <queue>

namespace {
    struct fraction {
        int numerator;
        int denominator;

        std::strong_ordering operator<=>(const fraction &other) const {
            return numerator * other.denominator <=> other.numerator * denominator;
        }

        bool operator==(const fraction &other) const {
            return numerator * other.denominator == other.numerator * denominator;
        }
    };
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int city_count;
    int box_count;
    std::cin >> city_count >> box_count;

    while (city_count != -1 && box_count != -1) {
        std::priority_queue<fraction> city_states;
        for (int i = 0; i < city_count; ++i) {
            int size;
            std::cin >> size;

            city_states.emplace(size, 1);
        }

        for (int i = 0; i < box_count - city_count; ++i) {
            auto [size, assigned_box_count] = city_states.top();
            city_states.pop();
            city_states.emplace(size, assigned_box_count + 1);
        }

        auto [size, assigned_box_count] = city_states.top();
        std::cout << size / assigned_box_count + (size % assigned_box_count != 0 ? 1 : 0) << '\n';

        std::cin >> city_count >> box_count;
    }

    return 0;
}
