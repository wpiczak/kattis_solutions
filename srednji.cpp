#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    int median;
    std::cin >> size >> median;

    int median_index = -1;
    std::vector<int> sequence(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> sequence[i];
        if (sequence[i] == median) median_index = i;
    }

    std::unordered_map<int, int> count;
    int right_balance = 0;
    for (int i = median_index; i < size; ++i) {
        if (sequence[i] < median) --right_balance;
        else if (sequence[i] > median) ++right_balance;

        const auto it = count.insert({right_balance, 0}).first;
        ++it->second;
    }

    long long result = 0;
    int left_balance = 0;
    for (int i = median_index; i >= 0; --i) {
        if (sequence[i] < median) ++left_balance;
        else if (sequence[i] > median) --left_balance;

        const auto it = count.find(left_balance);
        if (it != count.end()) result += it->second;
    }

    std::cout << result;

    return 0;
}
