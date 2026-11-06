#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int case_count;
    std::cin >> case_count;

    int case_index = 1;
    while (case_count--) {
        int n;
        std::cin >> n;

        std::vector<long long> first(n);
        std::vector<long long> second(n);

        for (int i = 0; i < n; ++i) std::cin >> first[i];
        for (int i = 0; i < n; ++i) std::cin >> second[i];

        std::ranges::sort(first, std::less());
        std::ranges::sort(second, std::greater());

        long long result = 0;
        for (int i = 0; i < n; ++i)
            result += first[i] * second[i];

        std::cout << "Case #" << (case_index++) << ": " << result << '\n';
    }

    return 0;
}
