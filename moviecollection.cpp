#include <iostream>
#include <vector>

template<typename T>
class fenwick_tree {
public:
    explicit fenwick_tree(std::size_t size);
    explicit fenwick_tree(const std::vector<T>& data);

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
fenwick_tree<T>::fenwick_tree(const std::vector<T>& data) : data_(data.size()) {
    for (std::size_t i = 0; i < data_.size(); ++i) {
        if (i < data.size()) data_[i] += data[i];
        if (next(i) < data_.size()) data_[next(i)] += data_[i];
    }
}

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

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int movie_count;
        int request_count;
        std::cin >> movie_count >> request_count;

        std::vector initializer(movie_count, -1);
        initializer.resize(movie_count + request_count, 0);

        fenwick_tree tree{initializer};

        std::vector position(movie_count, 0);
        for (int i = 0; i < movie_count; ++i)
            position[i] = movie_count - i - 1;

        int next_position = movie_count;
        for (int i = 0; i < request_count; ++i) {
            int label;
            std::cin >> label;
            --label;

            if (i > 0) std::cout << ' ';
            std::cout << movie_count + tree.query_prefix(position[label]);

            tree.update_point(position[label], 1);
            tree.update_point(next_position, -1);
            position[label] = next_position;
            ++next_position;
        }

        std::cout << '\n';
    }

    return 0;
}
