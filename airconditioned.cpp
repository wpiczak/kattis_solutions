#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i)
        std::cin >> intervals[i].first >> intervals[i].second;

    std::ranges::sort(intervals);

    int result = 0;
    int start = -1;
    int end = -1;
    for (int i = 0; i < n; ++i) {
        if (intervals[i].first > end) {
            std::tie(start, end) = intervals[i];
            ++result;
        } else {
            start = intervals[i].first;
            if (intervals[i].second < end) end = intervals[i].second;
        }
    }

    std::cout << result;

    return 0;
}
