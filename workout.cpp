#include <array>
#include <iostream>

int main() {
    std::array<int, 10> personal_usage_time{};
    std::array<int, 10> personal_recovery_time{};

    for (int i = 0; i < 10; ++i)
        std::cin >> personal_usage_time[i] >> personal_recovery_time[i];

    std::array<int, 10> usage_time{};
    std::array<int, 10> recovery_time{};
    std::array<int, 10> start_time{};
    std::array<int, 10> end_time{};

    for (int i = 0; i < 10; ++i) {
        std::cin >> usage_time[i] >> recovery_time[i] >> start_time[i];
        end_time[i] = 0;
    }

    int current_time = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 10; ++j) {
            while (current_time >= start_time[j]) {
                end_time[j] = start_time[j] + usage_time[j];
                start_time[j] = end_time[j] + recovery_time[j];
            }

            current_time = std::max(current_time, end_time[j]);
            start_time[j] = std::max(start_time[j], current_time + personal_usage_time[j]);
            current_time += personal_usage_time[j] + personal_recovery_time[j];
        }
    }

    std::cout << current_time - personal_recovery_time[9];

    return 0;
}
