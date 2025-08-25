#include <iostream>
#include <memory>
#include <set>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::set<int> tree;
    std::vector<int> depth(n + 1);
    long long counter = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;

        auto current = tree.insert(value).first;
        int current_depth = 0;

        if (current != tree.begin())
            current_depth = std::max(depth.at(*std::prev(current)) + 1, current_depth);
        if (std::next(current) != tree.end())
            current_depth = std::max(depth.at(*std::next(current)) + 1, current_depth);

        depth[*current] = current_depth;
        counter += current_depth;

        std::cout << counter << '\n';
    }

    return 0;
}
