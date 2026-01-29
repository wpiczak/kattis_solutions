#include <algorithm>
#include <iostream>
#include <vector>

int stripe_count;
std::vector<std::string> colors;

std::vector<bool> is_used;
std::vector<int> painting;
std::vector<int> preferred_painting;
std::vector<std::pair<int, int>> forbidden_pairs;

int solve(const int index = 0) {
    if (index == stripe_count) {
        if (preferred_painting.empty())
            preferred_painting = painting;

        return 1;
    }

    int result = 0;
    for (int color = 0; color < stripe_count; ++color) {
        if (is_used[color]) continue;

        if (index - 1 >= 0) {
            int previous = painting[index - 1];

            std::pair pair = {previous, color};
            if (previous > color) pair = {color, previous};

            if (std::ranges::contains(forbidden_pairs, pair)) continue;
        }

        painting.push_back(color);
        is_used[color] = true;
        result += solve(index + 1);
        painting.pop_back();
        is_used[color] = false;
    }

    return result;
}

int main() {
    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        painting.resize(0);
        preferred_painting.resize(0);

        std::cin >> stripe_count;
        is_used.resize(stripe_count);

        colors.resize(stripe_count);
        for (int i = 0; i < stripe_count; ++i)
            std::cin >> colors[i];

        int forbidden_pair_count;
        std::cin >> forbidden_pair_count;

        forbidden_pairs.resize(forbidden_pair_count);
        for (int i = 0; i < forbidden_pair_count; ++i) {
            std::string first_color;
            std::string second_color;
            std::cin >> first_color >> second_color;

            int first = static_cast<int>(std::ranges::find(colors, first_color) - colors.begin());
            int second = static_cast<int>(std::ranges::find(colors, second_color) - colors.begin());
            forbidden_pairs[i] = {std::min(first, second), std::max(first, second)};
        }

        std::cout << solve() << '\n';

        for (const int index : preferred_painting)
            std::cout << colors[index] << ' ';
        std::cout << '\n';
    }

    return 0;
}
