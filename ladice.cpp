#include <iostream>
#include <vector>

class union_find {
public:
    explicit union_find(int initial_size);

    void reduce_virtual_size(int x);
    void unite_sets(int x, int y);
    int find_set(int x);

    [[nodiscard]] int size_of_set(int x) const;
    [[nodiscard]] int virtual_size_of_set(int x) const;

private:
    std::vector<int> parent_;
    std::vector<int> size_;
    std::vector<int> virtual_size_;

    [[nodiscard]] int get_root(int x) const;
};

union_find::union_find(const int initial_size) {
    parent_.reserve(initial_size);
    for (int i = 0; i < initial_size; ++i)
        parent_.push_back(i);

    size_.resize(initial_size, 1);
    virtual_size_.resize(initial_size, 1);
}

void union_find::reduce_virtual_size(const int x) {
    --virtual_size_[get_root(x)];
}

void union_find::unite_sets(int x, int y) {
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
    virtual_size_[root_of_y] += virtual_size_[root_of_x];
    virtual_size_[root_of_x] = 0;
}

int union_find::find_set(const int x) {
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

int union_find::size_of_set(const int x) const {
    return size_[get_root(x)];
}

int union_find::virtual_size_of_set(const int x) const {
    return virtual_size_[get_root(x)];
}

int union_find::get_root(const int x) const {
    auto root = parent_[x];
    while (parent_[root] != root)
        root = parent_[root];

    return root;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int item_count;
    int drawer_count;
    std::cin >> item_count >> drawer_count;

    union_find drawers{drawer_count};
    while (item_count--) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;

        drawers.unite_sets(a, b);
        if (drawers.virtual_size_of_set(a) > 0) {
            drawers.reduce_virtual_size(a);
            std::cout << "LADICA\n";
        } else std::cout << "SMECE\n";
    }

    return 0;
}
