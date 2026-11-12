#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    while (n != 0) {
        std::vector<int> sizes(n);
        for (int i = 0; i < n; ++i)
            std::cin >> sizes[i];

        std::ranges::sort(sizes);

        int k = 1;
        int repetition_count = 1;
        for (int i = 1; i < n; ++i) {
            if (sizes[i - 1] == sizes[i]) {
                ++repetition_count;
                k = std::max(repetition_count, k);
            } else repetition_count = 1;
        }

        std::cout << k << '\n';
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < n; j += k)
                std::cout << sizes[j] << ' ';
            std::cout << '\n';
        }
        std::cout << '\n';

        std::cin >> n;
    }

    return 0;
}
