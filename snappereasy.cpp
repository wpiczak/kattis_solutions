#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int n, k;
        std::cin >> n >> k;

        std::cout << "Case #" << (i + 1) << ": ";

        const bool light_is_on = ((1 << n) - 1 & k) == (1 << n) - 1;
        if (light_is_on) std::cout << "ON\n";
        else std::cout << "OFF\n";
    }

    return 0;
}
