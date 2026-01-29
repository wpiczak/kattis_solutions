#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

constexpr std::array<std::pair<int, int>, 10> position = {
    {
        {1, 3},
        {0, 0},
        {1, 0},
        {2, 0},
        {0, 1},
        {1, 1},
        {2, 1},
        {0, 2},
        {1, 2},
        {2, 2}
    }
};

void generate(const int current, const int length, std::vector<int>& output) {
    if (length == 0) return;
    const int last_digit = current % 10;
    for (int i = 0; i < 10; ++i) {
        if (position[i].first < position[last_digit].first) continue;
        if (position[i].second < position[last_digit].second) continue;
        output.push_back(current * 10 + i);
        generate(current * 10 + i, length - 1, output);
    }
}

std::vector<int> generate(const int length) {
    std::vector<int> solution;
    for (int i = 1; i < 10; ++i) {
        solution.push_back(i);
        generate(i, length - 1, solution);
    }
    return solution;
}

int main() {
    std::vector<int> solution = generate(3);
    std::ranges::sort(solution);

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int n;
        std::cin >> n;

        const auto it = std::ranges::lower_bound(solution, n);
        if (it == solution.begin()) std::cout << *it << '\n';
        else {
            if (n - *std::prev(it) <= *it - n)
                std::cout << *std::prev(it) << '\n';
            else std::cout << *it << '\n';
        }
    }

    return 0;
}
