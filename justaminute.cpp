#include <iomanip>
#include <iostream>

int main() {
    int observation_count;
    std::cin >> observation_count;

    int total_minutes = 0;
    int total_delay = 0;
    for (int i = 0; i < observation_count; ++i) {
        int minutes;
        int seconds;

        std::cin >> minutes >> seconds;
        total_minutes += minutes;
        total_delay += seconds - 60 * minutes;
    }

    const double average_minute_length = 1 + total_delay / (total_minutes * 60.0);
    if (total_delay <= 0) std::cout << "measurement error";
    else std::cout << std::setprecision(10) << average_minute_length;

    return 0;
}
