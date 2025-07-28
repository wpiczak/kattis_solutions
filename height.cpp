#include <array>
#include <iostream>

int count_backward_steps(std::array<int, 20>& heights) {
    int result = 0;
    for (int i = 1; i < 20; ++i) {
        int j = i;
        while (j > 0 && heights[j - 1] > heights[j]) {
            std::swap(heights[j - 1], heights[j]);
            ++result;
            --j;
        }
    }
    return result;
}

int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int index;
        std::cin >> index;

        std::array<int, 20> heights{};
        for (int j = 0; j < 20; ++j)
            std::cin >> heights[j];

        std::cout << index << ' ' << count_backward_steps(heights) << '\n';
    }

    return 0;
}
