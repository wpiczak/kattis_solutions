#include <iostream>
#include <vector>

class union_find {
public:
    explicit union_find(std::size_t initial_size);

    void unite_sets(std::size_t x, std::size_t y);
    std::size_t find_set(std::size_t x);

    [[nodiscard]] std::size_t size_of_set(std::size_t x) const;
    [[nodiscard]] std::size_t set_count() const;

private:
    std::vector<std::size_t> parent_;
    std::vector<std::size_t> size_;
    std::size_t set_count_;
};

union_find::union_find(const std::size_t initial_size) : set_count_{initial_size} {
    parent_.reserve(initial_size);
    for (std::size_t i = 0; i < initial_size; ++i)
        parent_.push_back(i);

    size_.resize(initial_size, 1);
}

void union_find::unite_sets(std::size_t x, std::size_t y) {
    auto root_of_x = find_set(x);
    auto root_of_y = find_set(y);

    if (root_of_x == root_of_y) return;

    if (size_[x] > size_[y]) {
        std::swap(x, y);
        std::swap(root_of_x, root_of_y);
    }

    parent_[root_of_x] = root_of_y;
    size_[root_of_y] += size_[root_of_x];
    size_[root_of_x] = 0;
    --set_count_;
}

std::size_t union_find::find_set(const std::size_t x) {
    auto root = parent_[x];
    while (parent_[root] != root)
        root = parent_[root];

    auto a = x;
    auto b = parent_[x];
    while (b != root) {
        parent_[a] = root;

        a = b;
        b = parent_[b];
    }

    return root;
}

std::size_t union_find::size_of_set(const std::size_t x) const {
    auto root = parent_[x];
    while (parent_[root] != root)
        root = parent_[root];

    return size_[root];
}

std::size_t union_find::set_count() const { return set_count_; }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;

    union_find sets{size};

    int query_count;
    std::cin >> query_count;

    while (query_count--) {
        char type;
        std::cin >> type;

        int a, b;
        std::cin >> a >> b;

        if (type == '?') {
            if (sets.find_set(a) == sets.find_set(b)) std::cout << "yes\n";
            else std::cout << "no\n";
        } else sets.unite_sets(a, b);
    }

    return 0;
}
