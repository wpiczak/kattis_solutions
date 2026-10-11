#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int activity_count;
    int classroom_count;
    std::cin >> activity_count >> classroom_count;

    std::vector<std::pair<int, int>> activities(activity_count);
    for (int i = 0; i < activity_count; ++i)
        std::cin >> activities[i].first >> activities[i].second;

    std::ranges::sort(activities, [](const auto &x, const auto &y) {
        return x.second < y.second || (x.second == y.second && x.first < y.first);
    });

    std::multiset<int, std::greater<>> classroom_end_times;
    for (int i = 0; i < classroom_count; ++i)
        classroom_end_times.insert(0);

    int result = 0;
    for (int i = 0; i < activity_count; ++i) {
        auto it = classroom_end_times.upper_bound(activities[i].first);
        if (it != classroom_end_times.end()) {
            classroom_end_times.erase(it);
            classroom_end_times.insert(activities[i].second);
            ++result;
        }
    }

    std::cout << result;

    return 0;
}
