#include <iostream>
#include <unordered_set>
#include <vector>

class union_find {
public:
    explicit union_find(int initial_size);

    void unite_sets(int x, int y);
    int find_set(int x);

    [[nodiscard]] int size_of_set(int x) const;
    [[nodiscard]] int set_count() const;

private:
    std::vector<int> parent_;
    std::vector<int> size_;
    int set_count_;
};

union_find::union_find(const int initial_size) : set_count_{initial_size} {
    parent_.reserve(initial_size);
    for (int i = 0; i < initial_size; ++i)
        parent_.push_back(i);

    size_.resize(initial_size, 1);
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
    --set_count_;
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
    auto root = parent_[x];
    while (parent_[root] != root)
        root = parent_[root];

    return size_[root];
}

int union_find::set_count() const { return set_count_; }

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    union_find cauldrons{500'001};

    int query_count;
    std::cin >> query_count;

    int potion_count{0};
    while (query_count--) {
        std::unordered_set<int> used_cauldrons;

        int current_ingredient_count{0};
        int target_ingredient_count;
        std::cin >> target_ingredient_count;

        for (int i = 0; i < target_ingredient_count; ++i) {
            int ingredient;
            std::cin >> ingredient;


            int current = cauldrons.find_set(ingredient);
            if (auto [_, inserted] = used_cauldrons.insert(current); inserted)
                current_ingredient_count += cauldrons.size_of_set(current);
        }

        if (current_ingredient_count == target_ingredient_count) {
            const int new_cauldron = *used_cauldrons.begin();
            for (const int cauldron : used_cauldrons)
                cauldrons.unite_sets(cauldron, new_cauldron);
            ++potion_count;
        }
    }

    std::cout << potion_count;

    return 0;
}
