#include <iostream>
#include <vector>

static int solve(const std::vector<std::pair<int, int>> &gallery, const int k) {
    std::vector left(gallery.size(), std::vector(k + 1, std::numeric_limits<int>::max()));
    std::vector right(gallery.size(), std::vector(k + 1, std::numeric_limits<int>::max()));

    for (int i = 0; i < gallery.size(); i++) {
        left[i][0] = 0;
        right[i][0] = 0;
    }

    if (k > 0) {
        left[0][1] = gallery[0].first;
        right[0][1] = gallery[0].second;
    }

    for (int i = 1; i < gallery.size(); i++) {
        for (int j = 1; j <= k; j++) {
            int previous = std::min(left[i - 1][j], right[i - 1][j]);
            if (left[i - 1][j - 1] != std::numeric_limits<int>::max())
                left[i][j] = std::min(left[i - 1][j - 1] + gallery[i].first, previous);
            if (right[i - 1][j - 1] != std::numeric_limits<int>::max())
                right[i][j] = std::min(right[i - 1][j - 1] + gallery[i].second, previous);
        }
    }

    return std::min(left[gallery.size() - 1][k], right[gallery.size() - 1][k]);
}

int main() {
    int length;
    int closed_count;
    std::cin >> length >> closed_count;

    while (length > 0 || closed_count > 0) {
        std::vector<std::pair<int, int>> gallery(length);
        int total_value = 0;
        for (int i = 0; i < length; i++) {
            std::cin >> gallery[i].first >> gallery[i].second;
            total_value += gallery[i].first + gallery[i].second;
        }

        std::cout << total_value - solve(gallery, closed_count) << '\n';
        std::cin >> length >> closed_count;
    }

    return 0;
}
