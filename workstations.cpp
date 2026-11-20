#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

namespace {
    struct slot {
        int start;
        int length;

        [[nodiscard]] int end() const { return start + length; }

        bool operator==(const slot &other) const = default;

        auto operator<=>(const slot &other) const = default;
    };
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int researcher_count;
    int standby_duration;
    std::cin >> researcher_count >> standby_duration;

    std::vector<slot> requests(researcher_count);
    for (int i = 0; i < researcher_count; ++i)
        std::cin >> requests[i].start >> requests[i].length;

    std::ranges::sort(requests);

    int unlock_count = 0;
    std::priority_queue<long long, std::vector<long long>, std::greater<>> end_times;

    for (const auto &request: requests) {
        bool found_vacancy = false;
        while (!end_times.empty()) {
            if (end_times.top() + standby_duration < request.start) {
                end_times.pop();
                continue;
            }

            if (end_times.top() <= request.start) {
                end_times.pop();
                found_vacancy = true;
            }

            break;
        }

        if (!found_vacancy) ++unlock_count;
        end_times.push(request.end());
    }

    std::cout << researcher_count - unlock_count;

    return 0;
}
