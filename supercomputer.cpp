#include <iostream>
#include <vector>

template<typename T>
class fenwick_tree {
public:
    explicit fenwick_tree(std::size_t size);

    [[nodiscard]] std::size_t size() const;

    [[nodiscard]] T query_point(std::size_t i) const;
    [[nodiscard]] T query_prefix(std::size_t i) const;
    [[nodiscard]] T query_range(std::size_t i, std::size_t j) const;

    void update_point(std::size_t i, const T& delta);

private:
    std::vector<T> data_;

    static std::size_t start(const std::size_t n) { return n & (n + 1); }
    static std::size_t next(const std::size_t n) { return n | (n + 1); }
};

template<typename T>
fenwick_tree<T>::fenwick_tree(const std::size_t size) : data_(size) {}

template<typename T>
std::size_t fenwick_tree<T>::size() const { return data_.size(); }

template<typename T>
T fenwick_tree<T>::query_point(const std::size_t i) const {
    if (i >= data_.size()) throw std::range_error("index out of bounds");
    return query_range(i, i);
}

template<typename T>
T fenwick_tree<T>::query_prefix(std::size_t i) const {
    if (i >= data_.size()) throw std::range_error("index out of bounds");

    T result = data_[i];
    while (start(i) > 0) {
        i = start(i) - 1;
        result += data_[i];
    }
    return result;
}

template<typename T>
T fenwick_tree<T>::query_range(const std::size_t i, const std::size_t j) const {
    if (j >= data_.size()) throw std::range_error("index out of bounds");
    if (i > j) return T{};
    if (i == 0) return query_prefix(j);
    return query_prefix(j) - query_prefix(i - 1);
}

template<typename T>
void fenwick_tree<T>::update_point(std::size_t i, const T& delta) {
    if (i >= data_.size()) throw std::range_error("index out of bounds");
    while (i < data_.size()) {
        data_[i] += delta;
        i = next(i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t bit_count;
    std::size_t query_count;
    std::cin >> bit_count >> query_count;

    fenwick_tree<int> tree{bit_count};

    while (query_count--) {
        char type;
        std::cin >> type;

        if (type == 'F') {
            int index;
            std::cin >> index;
            --index;

            tree.update_point(index, tree.query_point(index) ? -1 : 1);
        } else if (type == 'C') {
            int left;
            int right;
            std::cin >> left >> right;
            --left;
            --right;

            std::cout << tree.query_range(left, right) << '\n';
        }
    }

    return 0;
}
