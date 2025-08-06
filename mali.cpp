#include <iostream>
#include <vector>

int next_nonzero(const std::vector<int>& vector, const int& index) {
    for (int i = index; i < vector.size(); ++i)
        if (vector[i] != 0) return i;
    return -1;
}

int previous_nonzero(const std::vector<int>& vector, const int& index) {
    for (int i = index; i >= 0; --i)
        if (vector[i] != 0) return i;
    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> total_count_a(100);
    std::vector<int> total_count_b(100);

    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        ++total_count_a[a - 1];
        ++total_count_b[b - 1];

        auto count_a = total_count_a;
        auto count_b = total_count_b;

        int maximum = 0;
        int j = next_nonzero(count_a, 0);
        int k = previous_nonzero(count_b, 99);
        while (j != -1 && k != -1) {
            if (j + k > maximum)
                maximum = j + k;

            const int delta = std::min(count_a[j], count_b[k]);
            count_a[j] -= delta;
            count_b[k] -= delta;

            j = next_nonzero(count_a, j);
            k = previous_nonzero(count_b, k);
        }

        std::cout << (maximum + 2) << '\n';
    }

    return 0;
}
