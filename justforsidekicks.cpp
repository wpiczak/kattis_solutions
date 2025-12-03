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

    std::size_t gem_count;
    std::size_t query_count;
    std::cin >> gem_count >> query_count;

    std::vector array(6, fenwick_tree<int>{gem_count});
    std::vector value(6, 0LL);

    for (int i = 0; i < 6; ++i) std::cin >> value[i];

    std::string types;
    std::cin >> types;
    for (int i = 0; i < gem_count; ++i)
        array[types[i] - '1'].update_point(i, 1);

    for (int i = 0; i < query_count; ++i) {
        int command;
        std::cin >> command;

        if (command == 1) {
            int index;
            int type;
            std::cin >> index >> type;
            --index;
            --type;
            array[types[index] - '1'].update_point(index, -1);
            array[type].update_point(index, 1);
            types[index] = static_cast<char>('1' + type);
        } else if (command == 2) {
            int type;
            std::cin >> type;
            std::cin >> value[type - 1];
        } else if (command == 3) {
            int left;
            int right;
            std::cin >> left >> right;
            --left;
            --right;
            long long result = 0;
            for (int j = 0; j < 6; ++j)
                result += value[j] * array[j].query_range(left, right);
            std::cout << result << '\n';
        }
    }

    return 0;
}
