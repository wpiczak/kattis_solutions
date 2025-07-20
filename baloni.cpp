#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int balloon_count;
    std::cin >> balloon_count;

    std::vector<int> arrow_count_at_height;
    int total_arrow_count = 0;
    for (int i = 0; i < balloon_count; ++i) {
        int height;
        std::cin >> height;

        if (height >= arrow_count_at_height.size())
            arrow_count_at_height.resize(height + 1);

        if (arrow_count_at_height[height]) {
            --arrow_count_at_height[height];
            ++arrow_count_at_height[height - 1];
        } else {
            ++total_arrow_count;
            ++arrow_count_at_height[height - 1];
        }
    }

    std::cout << total_arrow_count;

    return 0;
}
