#include <iostream>
#include <limits>

int maximum_torque(const int a, const int b, const int c) {
    return (4 * a * c + b * b) / (4 * a);
}

int main() {
    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int gear_count;
        std::cin >> gear_count;

        int best_gear = 0;
        int highest_torque = std::numeric_limits<int>::min();
        for (int i = 1; i <= gear_count; ++i) {
            int a, b, c;
            std::cin >> a >> b >> c;

            if (maximum_torque(a, b, c) > highest_torque) {
                highest_torque = maximum_torque(a, b, c);
                best_gear = i;
            }
        }

        std::cout << best_gear << '\n';
    }

    return 0;
}
