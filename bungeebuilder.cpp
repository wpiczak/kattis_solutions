#include <iostream>
#include <limits>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::stack<int> heights;
    int max_distance = 0;
    int min_height = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        int height;
        std::cin >> height;

        if (heights.empty() || heights.top() > height) {
            heights.push(height);
            min_height = std::min(height, min_height);
            continue;
        }

        while (!heights.empty()) {
            const int common_height = std::min(heights.top(), height);
            max_distance = std::max(common_height - min_height, max_distance);

            if (heights.top() > height) break;

            heights.pop();
        }

        if (heights.empty()) min_height = height;
        heights.push(height);
    }

    std::cout << max_distance;

    return 0;
}
