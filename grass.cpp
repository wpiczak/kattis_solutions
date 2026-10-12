#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

static int find_minimum_interval_cover(
    const double start, const double end,
    std::vector<std::pair<double, double>> intervals
) {
    std::ranges::sort(intervals);

    int cover_size = 0;
    double current_end = start;
    for (int i = 0; i < intervals.size();) {
        if (intervals[i].first <= current_end && intervals[i].second > current_end) {
            int j = i++;
            while (i < intervals.size()) {
                if (intervals[i].first > current_end) break;
                if (intervals[i].second > intervals[j].second) j = i;
                ++i;
            }

            ++cover_size;
            current_end = intervals[j].second;
        } else ++i;

        if (current_end >= end) break;
    }

    if (start == end && cover_size > 0) return 1;
    if (start < end && current_end >= end) return cover_size;
    return -1;
}

constexpr double EPSILON = 1e-6;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int interval_count;
    double length;
    double width;
    std::cin >> interval_count >> length >> width;

    while (std::cin) {
        std::vector<std::pair<double, double>> intervals;
        for (int i = 0; i < interval_count; ++i) {
            double position;
            double radius;
            std::cin >> position >> radius;

            if (2 * radius <= width) continue;

            const double delta = std::sqrt(radius * radius - width * width / 4);
            intervals.emplace_back(position - delta - EPSILON, position + delta + EPSILON);
        }

        std::cout << find_minimum_interval_cover(0, length, intervals) << '\n';

        std::cin >> interval_count >> length >> width;
    }

    return 0;
}
