#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int container_count;
    int color_count;
    std::cin >> container_count >> color_count;

    std::vector<int> containers(container_count);
    for (int i = 0; i < container_count; ++i)
        std::cin >> containers[i];

    std::ranges::sort(containers);

    long long result = 0;
    for (int i = 0; i < color_count; ++i) {
        int needed_paint;
        std::cin >> needed_paint;

        result += *std::ranges::lower_bound(containers, needed_paint) - needed_paint;
    }

    std::cout << result << '\n';

    return 0;
}
