#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int swather_count;
    int stage_count;
    std::cin >> swather_count >> stage_count;

    std::vector<std::vector<int>> duration(swather_count, std::vector<int>(stage_count));
    for (int i = 0; i < swather_count; ++i)
        for (int j = 0; j < stage_count; ++j)
            std::cin >> duration[i][j];

    for (int j = 0; j < stage_count; ++j) {
        for (int i = 0; i < swather_count; ++i) {
            if (i == 0 && j > 0)
                duration[i][j] += duration[i][j - 1];
            if (i > 0 && j == 0)
                duration[i][j] += duration[i - 1][j];
            if (i > 0 && j > 0)
                duration[i][j] += std::max(duration[i][j - 1], duration[i - 1][j]);
        }
    }

    bool is_first = true;
    for (int i = 0; i < swather_count; ++i) {
        if (is_first) is_first = false;
        else std::cout << ' ';
        std::cout << duration[i][stage_count - 1];
    }

    return 0;
}
