#include <algorithm>
#include <iostream>
#include <vector>

bool contains(const std::vector<long long>& array, const long long value) {
    long long start = 0;
    long long end = static_cast<long long>(array.size()) - 1;
    while (start <= end) {
        const long long center = (start + end) / 2;
        if (array[center] == value) return true;
        if (array[center] < value) start = center + 1;
        if (array[center] > value) end = center - 1;
    }
    return false;
}

int main() {
    long long n;
    long long m;
    long long a;
    long long c;
    long long x_0;

    std::cin >> n >> m >> a >> c >> x_0;

    std::vector sequence{x_0};
    for (long long i = 0; i < n; ++i)
        sequence.push_back((a * sequence.back() + c) % m);
    sequence.erase(sequence.begin());

    long long result = 0;
    for (long long i = 0; i < n; ++i)
        if (contains(sequence, sequence[i]))
            ++result;

    std::cout << result << '\n';

    return 0;
}
