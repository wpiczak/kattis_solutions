#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int world_count;
    std::cin >> world_count;

    std::vector<int> populations(world_count);
    for (int i = 0; i < world_count; ++i)
        std::cin >> populations[i];

    long long death_count = 0;
    for (int i = world_count - 1; i >= 1; --i) {
        if (populations[i] > populations[i - 1])
            continue;

        if (populations[i] == 0) {
            std::cout << '1';
            return 0;
        }

        death_count += populations[i - 1] - populations[i] + 1;
        populations[i - 1] = populations[i] - 1;
    }

    std::cout << death_count;

    return 0;
}
