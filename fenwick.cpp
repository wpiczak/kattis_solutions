#include <iostream>
#include <vector>

constexpr std::size_t lsb(const std::size_t n) { return n & (-n); }

class fenwick_tree {
public:
    explicit fenwick_tree(const std::size_t length) : data_(length + 1) {}

    [[nodiscard]] long long query(std::size_t n) const {
        long long result = 0;

        while (n > 0) {
            result += data_[n];
            n -= lsb(n);
        }

        return result;
    }

    void update(std::size_t i, const int delta) {
        i += 1;
        while (i < data_.size()) {
            data_[i] += delta;
            i += lsb(i);
        }
    }

private:
    std::vector<long long> data_;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t length;
    std::size_t operation_count;
    std::cin >> length >> operation_count;

    fenwick_tree tree{length};

    while (operation_count--) {
        char operation;
        std::cin >> operation;

        if (operation == '+') {
            std::size_t i;
            int delta;
            std::cin >> i >> delta;

            tree.update(i, delta);
        } else if (operation == '?') {
            std::size_t i;
            std::cin >> i;

            std::cout << tree.query(i) << '\n';
        }
    }

    return 0;
}
