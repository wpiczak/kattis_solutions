#include <iomanip>
#include <iostream>

int main() {
    int distance_x;
    int distance_y;
    std::cin >> distance_x >> distance_y;

    int shield_count;
    std::cin >> shield_count;

    double range = 0;
    int total_shield_height = 0;
    for (int i = 0; i < shield_count; ++i) {
        int lower_boundary;
        int upper_boundary;
        double speed_factor;
        std::cin >> lower_boundary >> upper_boundary >> speed_factor;

        total_shield_height += upper_boundary - lower_boundary;
        range += (upper_boundary - lower_boundary) * speed_factor;
    }

    range += distance_y - total_shield_height;

    std::cout << std::setprecision(16) << distance_x / range;

    return 0;
}
