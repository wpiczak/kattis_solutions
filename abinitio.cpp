#include <iostream>
#include <memory>

template<std::size_t S>
class graph {
public:
    explicit graph(std::size_t initial_size);

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] bool inspect_edge(std::size_t x, std::size_t y) const;

    void toggle_edge(std::size_t x, std::size_t y);
    void add_vertex();
    void disconnect_vertex(std::size_t x);
    void transpose();
    void complement();
    void print_vertex_encoding(std::size_t x) const;

private:
    std::unique_ptr<bool[]> data_ = std::make_unique<bool[]>(S * S);
    std::size_t size_;
    bool is_transpose_{false};
    bool is_complement_{false};
};

template<std::size_t S>
graph<S>::graph(const std::size_t initial_size) : size_{initial_size} {}

template<std::size_t S>
std::size_t graph<S>::size() const { return size_; }

template<std::size_t S>
bool graph<S>::inspect_edge(std::size_t x, std::size_t y) const {
    if (x == y) return false;
    if (is_transpose_) std::swap(x, y);
    if (is_complement_) return !data_[x * S + y];
    return data_[x * S + y];
}

template<std::size_t S>
void graph<S>::toggle_edge(std::size_t x, std::size_t y) {
    if (is_transpose_) std::swap(x, y);
    data_[x * S + y] = !data_[x * S + y];
}

template<std::size_t S>
void graph<S>::add_vertex() {
    ++size_;

    if (is_complement_) {
        for (int i = 0; i < size_ - 1; ++i) {
            toggle_edge(i, size_ - 1);
            toggle_edge(size_ - 1, i);
        }
    }
}

template<std::size_t S>
void graph<S>::disconnect_vertex(const std::size_t x) {
    for (int y = 0; y < size_; ++y) {
        if (inspect_edge(x, y)) toggle_edge(x, y);
        if (inspect_edge(y, x)) toggle_edge(y, x);
    }
}

template<std::size_t S>
void graph<S>::transpose() { is_transpose_ = !is_transpose_; }

template<std::size_t S>
void graph<S>::complement() { is_complement_ = !is_complement_; }

template<std::size_t S>
void graph<S>::print_vertex_encoding(const std::size_t x) const {
    std::size_t out_degree{0};
    std::size_t hash{0};
    std::size_t scalar{1};

    for (int i = 0; i < size_; ++i) {
        if (inspect_edge(x, i)) {
            ++out_degree;

            hash += scalar * i;
            scalar *= 7;

            hash %= 1'000'000'007;
            scalar %= 1'000'000'007;
        }
    }

    std::cout << out_degree << ' ' << hash << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::size_t vertex_count;
    std::size_t edge_count;
    std::size_t query_count;
    std::cin >> vertex_count >> edge_count >> query_count;

    graph<4'000> target{vertex_count};

    while (edge_count--) {
        std::size_t x;
        std::size_t y;
        std::cin >> x >> y;
        target.toggle_edge(x, y);
    }

    while (query_count--) {
        int type;
        std::cin >> type;

        if (type == 1) target.add_vertex();
        else if (type == 2 || type == 4) {
            std::size_t x;
            std::size_t y;
            std::cin >> x >> y;
            target.toggle_edge(x, y);
        } else if (type == 3) {
            std::size_t x;
            std::cin >> x;
            target.disconnect_vertex(x);
        } else if (type == 5) target.transpose();
        else if (type == 6) target.complement();
    }

    std::cout << target.size() << '\n';
    for (int i = 0; i < target.size(); ++i)
        target.print_vertex_encoding(i);

    return 0;
}
