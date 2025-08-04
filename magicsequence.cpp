#include <iostream>
#include <sstream>
#include <vector>

void counting_sort(std::vector<long long>& vector, const int& n) {
    std::vector<int> count(32768);
    for (const auto& item : vector) ++count[(item >> (15 * n) & 0x7FFF)];
    for (int i = 1; i < count.size(); ++i) count[i] += count[i - 1];

    std::vector<long long> result(vector.size());
    for (int i = static_cast<int>(vector.size()) - 1; i >= 0; --i)
        result[--count[(vector[i] >> (15 * n) & 0x7FFF)]] = vector[i];

    std::swap(result, vector);
}

void radix_sort(std::vector<long long>& numbers) {
    for (int n = 0; n < 2; ++n) counting_sort(numbers, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        long long n, a, b, c, x, y;
        std::cin >> n >> a >> b >> c >> x >> y;

        std::vector<long long> sequence(n, 0);
        sequence[0] = a;
        for (int i = 1; i < n; ++i)
            sequence[i] = (sequence[i - 1] * b + a) % c;

        radix_sort(sequence);

        long long hash = 0;
        for (int i = 0; i < n; ++i)
            hash = (hash * x + sequence[i]) % y;

        std::cout << hash << '\n';
    }

    return 0;
}
