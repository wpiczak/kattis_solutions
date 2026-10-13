#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int head_count;
    int knight_count;
    std::cin >> head_count >> knight_count;

    while (head_count != 0 && knight_count != 0) {
        std::vector<int> head_diameters(head_count);
        std::vector<int> knight_heights(knight_count);

        for (int i = 0; i < head_count; ++i)
            std::cin >> head_diameters[i];
        for (int i = 0; i < knight_count; ++i)
            std::cin >> knight_heights[i];

        std::ranges::sort(head_diameters);
        std::ranges::sort(knight_heights);

        int cost = 0;
        int head_index = 0;
        int knight_index = 0;
        while (head_index < head_count && knight_index < knight_count) {
            if (head_diameters[head_index] <= knight_heights[knight_index]) {
                cost += knight_heights[knight_index];
                ++head_index;
            }

            ++knight_index;
        }

        if (head_index == head_count) std::cout << cost << '\n';
        else std::cout << "Loowater is doomed!\n";

        std::cin >> head_count >> knight_count;
    }

    return 0;
}
