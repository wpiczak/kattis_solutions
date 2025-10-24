#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/ranges_algo.h>

class augmented_union_find {
public:
    explicit augmented_union_find(const int capacity)
        : proxy_(capacity), parent_(capacity), size_(capacity, 1), sum_(capacity) {
        std::ranges::iota(proxy_, 0);
        std::ranges::iota(parent_, 0);
        std::ranges::iota(sum_, 0);
    }

    void unite(int x, int y) {
        int root_of_x = find(x);
        int root_of_y = find(y);

        if (root_of_x == root_of_y) return;

        if (size_[x] > size_[y]) {
            std::swap(x, y);
            std::swap(root_of_x, root_of_y);
        }

        parent_[root_of_x] = root_of_y;
        size_[root_of_y] += size_[root_of_x];
        size_[root_of_x] = 0;
        sum_[root_of_y] += sum_[root_of_x];
        sum_[root_of_x] = 0;
    }

    void move(const int x, const int y) {
        const int root_of_x = find(x);
        const int root_of_y = find(y);

        --size_[root_of_x];
        ++size_[root_of_y];
        sum_[root_of_x] -= x;
        sum_[root_of_y] += x;
        proxy_[x] = root_of_y;
    }

    std::pair<int, long long> inspect(const int x) {
        const int root = find(x);
        return {size_[root], sum_[root]};
    }

private:
    std::vector<int> proxy_;
    std::vector<int> parent_;
    std::vector<int> size_;
    std::vector<long long> sum_;

    [[nodiscard]] int find(const int x) {
        int root = proxy_[x];
        while (parent_[root] != root)
            root = parent_[root];

        int a = proxy_[x];
        int b = parent_[a];
        while (b != root) {
            parent_[a] = root;

            a = b;
            b = parent_[b];
        }

        proxy_[x] = root;

        return root;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int integer_count;
    int command_count;
    std::cin >> integer_count >> command_count;

    while (std::cin) {
        augmented_union_find sets{integer_count};

        while (command_count--) {
            int command;
            std::cin >> command;

            if (command == 1) {
                int p;
                int q;
                std::cin >> p >> q;

                sets.unite(p - 1, q - 1);
            } else if (command == 2) {
                int p;
                int q;
                std::cin >> p >> q;

                sets.move(p - 1, q - 1);
            } else if (command == 3) {
                int p;
                std::cin >> p;

                auto [size, sum] = sets.inspect(p - 1);
                sum += size;
                std::cout << size << ' ' << sum << '\n';
            }
        }

        std::cin >> integer_count >> command_count;
    }

    return 0;
}
