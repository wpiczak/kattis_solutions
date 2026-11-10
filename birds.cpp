#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int wire_length;
    int gap_size;
    int initial_count;
    std::cin >> wire_length >> gap_size >> initial_count;

    int result = 0;

    if (initial_count == 0) {
        if (wire_length > 12) result += (wire_length - 12) / gap_size + 1;
    } else {
        std::vector<int> positions(initial_count);
        for (int i = 0; i < initial_count; ++i)
            std::cin >> positions[i];

        std::ranges::sort(positions);

        result += (positions.front() - 6) / gap_size;
        result += (wire_length - positions.back() - 6) / gap_size;

        for (int i = 1; i < initial_count; ++i)
            result += (positions[i] - positions[i - 1] - gap_size) / gap_size;
    }

    std::cout << result;

    return 0;
}
