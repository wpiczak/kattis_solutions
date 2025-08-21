#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int trip_count;
    std::cin >> trip_count;

    std::unordered_map<std::string, std::vector<int>> trips;
    for (int i = 0; i < trip_count; ++i) {
        std::string destination;
        int year;
        std::cin >> destination >> year;

        const auto it = trips.insert({destination, std::vector<int>{}}).first;
        it->second.push_back(year);
    }

    for (auto& [_, years] : trips)
        std::sort(years.begin(), years.end());

    int query_count;
    std::cin >> query_count;

    for (int i = 0; i < query_count; ++i) {
        std::string destination;
        int number;
        std::cin >> destination >> number;
        std::cout << trips[destination][number - 1] << '\n';
    }


    return 0;
}
