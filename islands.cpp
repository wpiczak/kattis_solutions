#include <algorithm>
#include <array>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input_size;
    std::cin >> input_size;

    while (input_size--) {
        int index;
        std::cin >> index;

        std::array<int, 12> data{};
        for (int i = 0; i < 12; ++i)
            std::cin >> data[i];

        int result = 0;
        for (int i = 1; i < 12; ++i)
            for (int j = i + 1; j < 12; ++j)
                if (*std::min_element(data.begin() + i, data.begin() + j) > std::max(data[i - 1], data[j]))
                    ++result;

        std::cout << index << ' ' << result << '\n';
    }

    return 0;
}
