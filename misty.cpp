#include <algorithm>
#include <iostream>
#include <vector>

namespace {
    class disjoint_set {
    public:
        explicit disjoint_set(const std::size_t size) : parent_(size), group_count_{size} {
            for (int i = 0; i < size; ++i) parent_[i] = i;
        }

        int find(const int target) {
            int result = target;
            while (parent_[result] != result)
                result = parent_[result];

            int current = target;
            int next = parent_[target];
            while (next != result) {
                parent_[current] = result;
                current = next;
                next = parent_[current];
            }

            return result;
        }

        void unite(int first, int second) {
            first = find(first);
            second = find(second);

            if (first != second) {
                parent_[first] = second;
                --group_count_;
            }
        }

        [[nodiscard]] std::size_t count() const { return group_count_; }

    private:
        std::vector<int> parent_;
        std::size_t group_count_;
    };

    struct edge {
        int distance{};
        int start{};
        int end{};
        int index{};

        auto operator<=>(const edge &) const = default;
    };
}

int main() {
    int house_count;
    int trail_count;
    std::cin >> house_count >> trail_count;

    std::vector<edge> trails(trail_count);
    for (int i = 0; i < trail_count; ++i) {
        std::cin >> trails[i].start;
        std::cin >> trails[i].end;
        std::cin >> trails[i].distance;
        trails[i].index = i + 1;
    }

    std::ranges::sort(trails);

    std::vector<int> result;
    result.reserve(house_count - 1);

    disjoint_set house_groups(house_count);
    for (int i = 0; i < trail_count; ++i) {
        const int start = trails[i].start - 1;
        const int end = trails[i].end - 1;

        if (house_groups.find(start) != house_groups.find(end)) {
            house_groups.unite(start, end);
            result.push_back(trails[i].index);

            if (house_groups.count() == 1) break;
        }
    }

    std::cout << result.size() << '\n';
    for (const int trail_index: result)
        std::cout << trail_index << '\n';

    return 0;
}
