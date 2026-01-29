#include <algorithm>
#include <iostream>
#include <vector>

int team_count;
std::vector<bool> is_damaged;
std::vector<bool> has_reserve;

int solve(const int index = 0) {
    if (index == team_count)
        return static_cast<int>(std::ranges::count(is_damaged, true));

    if (has_reserve[index]) {
        int solution = team_count;

        if (index - 1 >= 0 && is_damaged[index - 1]) {
            is_damaged[index - 1] = false;
            solution = std::min(solve(index + 1), solution);
            is_damaged[index - 1] = true;
        }

        if (index + 1 < team_count && is_damaged[index + 1]) {
            is_damaged[index + 1] = false;
            solution = std::min(solve(index + 1), solution);
            is_damaged[index + 1] = true;
        }

        return std::min(solve(index + 1), solution);
    }

    return solve(index + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> team_count;
    is_damaged.resize(team_count);
    has_reserve.resize(team_count);

    int damaged_kayak_count;
    int reserve_kayak_count;
    std::cin >> damaged_kayak_count >> reserve_kayak_count;

    while (damaged_kayak_count--) {
        int index;
        std::cin >> index;
        --index;
        is_damaged[index] = true;
    }

    while (reserve_kayak_count--) {
        int index;
        std::cin >> index;
        --index;
        has_reserve[index] = true;
    }

    for (int i = 0; i < team_count; ++i) {
        if (has_reserve[i] && is_damaged[i]) {
            has_reserve[i] = false;
            is_damaged[i] = false;
        }
    }

    std::cout << solve(0);

    return 0;
}
