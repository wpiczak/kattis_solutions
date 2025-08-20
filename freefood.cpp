#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::array<bool, 366> free_food{};
    for (int i = 0; i < n; ++i) {
        int start;
        int end;
        std::cin >> start >> end;

        for (int j = start; j <= end; ++j) free_food[j] = true;
    }

    std::cout << std::count(free_food.begin(), free_food.end(), true);

    return 0;
}
