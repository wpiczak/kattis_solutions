#include <algorithm>
#include <iostream>
#include <vector>

class union_find {
public:
    explicit union_find(const std::size_t size) : parent_(size), rank_(size) {
        for (std::size_t i = 0; i < size; ++i) parent_[i] = i;
        std::ranges::fill(rank_, 1);
    }

    void join(std::size_t first, std::size_t second) {
        first = find(first);
        second = find(second);

        if (first == second) return;

        if (rank_[first] > rank_[second]) {
            join(second, first);
            return;
        }

        parent_[first] = second;
        rank_[second] += rank_[first];
        rank_[first] = 0;
    }

    std::size_t find(const std::size_t key) {
        std::size_t result = key;
        while (parent_[result] != result)
            result = parent_[result];

        std::size_t current = key;
        while (current != result) {
            const std::size_t next = parent_[current];
            parent_[current] = result;
            current = next;
        }

        return result;
    }

    std::size_t size(const std::size_t key) {
        return rank_[find(key)];
    }

private:
    std::vector<std::size_t> parent_;
    std::vector<std::size_t> rank_;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int guest_count, query_count;
    std::cin >> guest_count >> query_count;

    union_find guest_tracker(guest_count + 1);
    while (query_count--) {
        char code;
        std::cin >> code;

        if (code == 't') {
            int a, b;
            std::cin >> a >> b;

            guest_tracker.join(a, b);
        } else if (code == 's') {
            int i;
            std::cin >> i;

            std::cout << guest_tracker.size(i) << '\n';
        }
    }

    return 0;
}
