#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    int plot_count;
    int circular_house_count;
    int square_house_count;
    std::cin >> plot_count >> circular_house_count >> square_house_count;

    const int house_count = circular_house_count + square_house_count;

    std::vector<int> plot_radii(plot_count);
    std::vector<int> house_radii(house_count);

    for (int i = 0; i < plot_count; ++i)
        std::cin >> plot_radii[i];

    for (int i = 0; i < circular_house_count; ++i)
        std::cin >> house_radii[i];

    for (int i = circular_house_count; i < house_count; ++i) {
        std::cin >> house_radii[i];
        house_radii[i] = std::floor(house_radii[i] / std::sqrt(2));
    }

    std::ranges::sort(plot_radii);
    std::ranges::sort(house_radii);

    int result = 0;
    int plot_index = 0;
    int house_index = 0;
    while (plot_index < plot_count && house_index < house_count) {
        if (plot_radii[plot_index] > house_radii[house_index]) {
            ++house_index;
            ++result;
        }

        ++plot_index;
    }

    std::cout << result;

    return 0;
}
