#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int obstacle_count;
    int cave_height;
    std::cin >> obstacle_count >> cave_height;

    std::vector<int> stalagmites;
    std::vector<int> stalactites;

    for (int i = 0; i < obstacle_count; ++i) {
        int height;
        std::cin >> height;

        if (i & 1) stalactites.push_back(height);
        else stalagmites.push_back(height);
    }

    std::ranges::sort(stalagmites);
    std::ranges::sort(stalactites);

    int minimum_collision_count = obstacle_count;
    int possible_level_count = 0;
    for (int height = 1; height <= cave_height; ++height) {
        const auto first_it = std::ranges::lower_bound(stalagmites, height);
        const auto second_it = std::ranges::lower_bound(stalactites, cave_height - height + 1);
        const int collision_count = static_cast<int>((stalagmites.end() - first_it) + (stalactites.end() - second_it));

        if (collision_count < minimum_collision_count) {
            minimum_collision_count = collision_count;
            possible_level_count = 1;
        } else if (collision_count == minimum_collision_count) ++possible_level_count;
    }

    std::cout << minimum_collision_count << ' ' << possible_level_count << '\n';

    return 0;
}
