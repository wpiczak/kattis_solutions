#include <iostream>
#include <memory>
#include <vector>

class prototype {
    struct ceiling {
        int value;
        std::unique_ptr<ceiling> left{nullptr};
        std::unique_ptr<ceiling> right{nullptr};
    };

public:
    void insert(const int value) {
        if (root_ == nullptr) root_ = std::make_unique<ceiling>(value);
        else insert(root_, value);
    }

    bool operator==(const prototype& other) const { return equal(root_, other.root_); }

private:
    std::unique_ptr<ceiling> root_{nullptr};

    static void insert(const std::unique_ptr<ceiling>& current, const int value) {
        if (value < current->value) {
            if (current->left == nullptr)
                current->left = std::make_unique<ceiling>(value);
            else insert(current->left, value);
        } else {
            if (current->right == nullptr)
                current->right = std::make_unique<ceiling>(value);
            else insert(current->right, value);
        }
    }

    static bool equal(const std::unique_ptr<ceiling>& x, const std::unique_ptr<ceiling>& y) {
        if (x == nullptr && y == nullptr)
            return true;
        if (x != nullptr && y != nullptr)
            return equal(x->left, y->left) && equal(x->right, y->right);
        return false;
    }
};

int main() {
    int n;
    int k;
    std::cin >> n >> k;

    std::vector<prototype> prototypes;
    for (int i = 0; i < n; ++i) {
        prototype current;
        for (int j = 0; j < k; ++j) {
            int resistance;
            std::cin >> resistance;
            current.insert(resistance);
        }

        bool is_distinct = true;
        for (auto& previous : prototypes) {
            if (current == previous) {
                is_distinct = false;
                break;
            }
        }

        if (is_distinct) prototypes.push_back(std::move(current));
    }

    std::cout << prototypes.size();
}
