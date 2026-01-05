#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

int encode_routine(const std::string& routine) {
    int result = 0;
    for (const char dancer : routine)
        result |= (1 << (dancer - 'A'));
    return result;
}

int calculate_recital_cost(const std::vector<int>& routines) {
    int result = 0;
    for (int i = 1; i < routines.size(); ++i)
        result += std::bitset<32>(routines[i - 1] & routines[i]).count();
    return result;
}

int main() {
    int routine_count;
    std::cin >> routine_count;

    std::vector<int> routines;
    for (int i = 0; i < routine_count; ++i) {
        std::string input; std::cin >> input;
        routines.push_back(encode_routine(input));
    }

    std::ranges::sort(routines);

    int least_cost = calculate_recital_cost(routines);
    while (std::ranges::next_permutation(routines).found)
        least_cost = std::min(calculate_recital_cost(routines), least_cost);

    std::cout << least_cost << '\n';

    return 0;
}
