#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        std::multiset<int> lower;
        std::multiset<int> upper;

        int size;
        std::cin >> size;

        long long result = 0;

        int value;
        std::cin >> value;
        upper.insert(value);
        result += value;

        for (int j = 1; j < size; ++j) {
            std::cin >> value;

            if (value < *upper.begin()) lower.insert(value);
            else upper.insert(value);

            if (lower.size() > upper.size()) {
                auto last = *(--lower.end());
                lower.erase(--lower.end());
                upper.insert(last);
            } else if (lower.size() + 1 < upper.size()) {
                auto first = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(first);
            }

            if (lower.size() == upper.size()) {
                const int a = *(--lower.end());
                const int b = *upper.begin();
                result += (a + b) / 2;
            } else result += *upper.begin();
        }

        std::cout << result << '\n';
    }

    return 0;
}
