#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int city_count;
        std::cin >> city_count;

        int pilot_count;
        std::cin >> pilot_count;

        for (int i = 0; i < pilot_count; ++i) {
            int a, b;
            std::cin >> a >> b;
        }

        std::cout << city_count - 1 << '\n';
    }

    return 0;
}
