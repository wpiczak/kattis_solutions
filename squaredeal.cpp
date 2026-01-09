#include <algorithm>
#include <array>
#include <iostream>

bool check_first_layout(const std::array<std::pair<int, int>, 3>& sizes) {
    if (sizes[0].first != sizes[1].first || sizes[1].first != sizes[2].first)
        return false;
    return sizes[0].first == sizes[0].second + sizes[1].second + sizes[2].second;
}

bool check_second_layout(const std::array<std::pair<int, int>, 3>& sizes) {
    if (sizes[0].first != sizes[1].first || sizes[0].second + sizes[1].second != sizes[2].second)
        return false;
    return sizes[0].first + sizes[2].first == sizes[2].second;
}

void reorient(std::array<std::pair<int, int>, 3>& sizes, const int layout) {
    for (int i = 0; i < 3; ++i) {
        if ((layout & (1 << i)) == 0) continue;
        std::swap(sizes[i].first, sizes[i].second);
    }
}

int main() {
    std::array<std::pair<int, int>, 3> sizes;
    for (int i = 0; i < 3; ++i) {
        int height;
        int width;
        std::cin >> height >> width;
        sizes[i] = {height, width};
    }

    std::ranges::sort(sizes);
    do {
        for (int i = 0; i < 8; ++i) {
            reorient(sizes, i);

            if (check_first_layout(sizes) || check_second_layout(sizes)) {
                std::cout << "YES\n";
                return 0;
            }

            reorient(sizes, i);
        }
    } while (std::ranges::next_permutation(sizes).found);

    std::cout << "NO\n";

    return 0;
}
