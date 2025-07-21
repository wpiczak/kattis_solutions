#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> sequence;
    int previous = 0;
    for (int i = 0; i < n; ++i) {
        int current;
        std::cin >> current;

        if (current > previous) {
            sequence.push_back(current);
            previous = current;
        }
    }

    std::cout << sequence.size() << '\n';
    bool is_first = true;
    for (const auto& x : sequence) {
        if (!is_first) std::cout << ' ';
        else is_first = false;
        std::cout << x;
    }

    return 0;
}
