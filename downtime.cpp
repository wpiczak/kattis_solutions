#include <iostream>
#include <vector>

class fenwick_tree {
public:
    explicit fenwick_tree(const std::size_t size) : tree_(size + 1) {}

    void increment_range(const std::size_t start, const std::size_t end) {
        update(start, 1);
        update(end, -1);
    }

    int query(std::size_t i) const {
        i = i + 1;
        int result = 0;
        while (i > 0) {
            result += tree_[i];
            i -= i & -i;
        }
        return result;
    }

private:
    std::vector<int> tree_;

    void update(std::size_t i, const int value) {
        i = i + 1;
        while (i < tree_.size()) {
            tree_[i] += value;
            i += i & -i;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int number_of_requests;
    int server_capacity;
    std::cin >> number_of_requests >> server_capacity;

    auto concurrent_request_count = fenwick_tree{100'001};
    for (int i = 0; i < number_of_requests; ++i) {
        int time;
        std::cin >> time;

        concurrent_request_count.increment_range(time, time + 1'000);
    }

    int max_concurrent_request_count = 0;
    for (int i = 0; i < 100'001; ++i) {
        const int n = concurrent_request_count.query(i);
        if (n > max_concurrent_request_count) max_concurrent_request_count = n;
    }

    int required_server_count = max_concurrent_request_count / server_capacity;
    if (required_server_count * server_capacity < max_concurrent_request_count)
        ++required_server_count;
    std::cout << required_server_count;

    return 0;
}
