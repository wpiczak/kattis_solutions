#include <iostream>
#include <limits>
#include <map>
#include <vector>

class segment_tree {
    struct interval {
        std::size_t a;
        std::size_t b;

        explicit interval(const std::size_t a, const std::size_t b) : a{a}, b{b} {
            if (a >= b) throw std::logic_error("invalid interval");
        }

        [[nodiscard]] bool contains(const interval& other) const { return other.a >= a && other.b <= b; }

        [[nodiscard]] bool intersects(const interval& other) const { return other.a < b && other.b > a; }

        [[nodiscard]] std::size_t padded_length() const { return 1 << std::bit_width(b - a - 1); }

        [[nodiscard]] std::pair<interval, interval> split() const {
            const std::size_t c = a + (padded_length() >> 1);
            return {interval{a, c}, interval{c, b}};
        }
    };

public:
    explicit segment_tree(const std::vector<int>& input) {
        if (input.empty()) throw std::logic_error("the input vector is empty");

        data_.resize(2 * input.size() - 1);
        size_ = input.size();

        build(0, interval{0, size_}, input);
    }

    int query(const std::size_t start, const std::size_t end) {
        if (end > size_) throw std::logic_error("invalid interval");
        return query(0, interval{0, size_}, interval{start, end});
    }

private:
    std::vector<int> data_{};
    std::size_t size_{0};

    void build(const std::size_t index, const interval& range, const std::vector<int>& input) {
        if (range.b == range.a + 1) {
            data_[index] = input[range.a];
            return;
        }

        const auto [left, right] = range.split();
        const std::size_t left_index = index + 1;
        const std::size_t right_index = index + 2 * left.padded_length();

        build(left_index, left, input);
        build(right_index, right, input);

        data_[index] = std::max(data_[left_index], data_[right_index]);
    }

    int query(const std::size_t index, const interval& current, const interval& target) {
        if (!target.intersects(current)) return std::numeric_limits<int>::min();
        if (target.contains(current)) return data_[index];

        const auto [left, right] = current.split();
        const std::size_t left_index = index + 1;
        const std::size_t right_index = index + 2 * left.padded_length();

        return std::max(query(left_index, left, target), query(right_index, right, target));
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int pair_count;
    std::cin >> pair_count;

    std::map<int, std::size_t> first_position;
    std::map<int, std::size_t> second_position;

    std::vector<int> configuration(2 * pair_count + 1);
    configuration[pair_count] = std::numeric_limits<int>::max();

    for (int i = 0; i < 2 * pair_count + 1; ++i) {
        if (i == pair_count) continue;
        std::cin >> configuration[i];

        if (!first_position.contains(configuration[i]))
            first_position[configuration[i]] = i;
        else second_position[configuration[i]] = i;
    }

    segment_tree tree{configuration};

    int result = 0;
    for (const auto& [weight, start] : first_position) {
        const std::size_t end = second_position[weight];
        if (end == start + 1) continue;
        result = std::max(std::min(tree.query(start + 1, end), weight), result);
    }

    std::cout << result << '\n';

    return 0;
}
