#include <iostream>
#include <set>
#include <tuple>

struct quest {
    int energy;
    int reward;

    bool operator<(const quest& other) const {
        return std::tie(energy, reward) < std::tie(other.energy, other.reward);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int command_count;
    std::cin >> command_count;

    std::multiset<quest> queue;
    for (int i = 0; i < command_count; ++i) {
        std::string command_type;
        std::cin >> command_type;

        if (command_type == "add") {
            quest new_quest{0, 0};
            std::cin >> new_quest.energy >> new_quest.reward;

            queue.insert(new_quest);
        } else if (command_type == "query") {
            int available_energy;
            std::cin >> available_energy;

            long long total_reward = 0;
            auto it = queue.lower_bound({available_energy + 1, 0});
            while (it != queue.begin()) {
                it = std::prev(it);

                total_reward += it->reward;
                available_energy -= it->energy;
                queue.erase(it);

                it = queue.lower_bound({available_energy + 1, 0});
            }

            std::cout << total_reward << '\n';
        }
    }

    return 0;
}