#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int airport_count, day_count, flight_count;
    std::cin >> airport_count >> day_count >> flight_count;

    std::vector schedule(day_count, std::vector(airport_count, std::vector<std::pair<int, int>>{}));
    for (int i = 0; i < flight_count; ++i) {
        int start, end, day, capacity;
        std::cin >> start >> end >> day >> capacity;
        --start;
        --end;
        --day;

        schedule[day][start].emplace_back(end, capacity);
    }

    std::vector customer_count(day_count, std::vector(airport_count, 0));
    for (int i = 0; i < airport_count * day_count; ++i) {
        int airport, day, arrival_count;
        std::cin >> airport >> day >> arrival_count;
        --airport;
        --day;

        customer_count[day][airport] += arrival_count;
    }

    bool optimal = true;
    for (int day = 0; day < day_count; ++day) {
        for (int airport = 0; airport < airport_count; ++airport) {
            for (auto& [destination, capacity] : schedule[day][airport]) {
                customer_count[day][airport] -= capacity;
                if (day + 1 < day_count) customer_count[day + 1][destination] += capacity;
            }

            if (customer_count[day][airport] < 0) {
                optimal = false;
                break;
            }

            if (day + 1 < day_count) customer_count[day + 1][airport] += customer_count[day][airport];
        }

        if (!optimal) break;
    }

    std::cout << (optimal ? "optimal" : "suboptimal") << '\n';

    return 0;
}
