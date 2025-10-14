#include <iostream>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using entry = std::tuple<int, int, int>;
using scoreboard = tree<entry, null_type, std::less<entry>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int team_count;
    int event_count;
    std::cin >> team_count >> event_count;

    scoreboard entries;
    std::vector<scoreboard::const_iterator> team_to_entry{};

    for (int i = 0; i < team_count; ++i) {
        auto [it, _] = entries.insert({0, 0, i});
        team_to_entry.push_back(it);
    }

    for (int i = 0; i < event_count; ++i) {
        int current_team;
        int current_penalty;
        std::cin >> current_team >> current_penalty;
        current_team -= 1;

        auto [score, penalty, _] = *team_to_entry[current_team];
        score += 1;
        penalty -= current_penalty;

        entries.erase(team_to_entry[current_team]);
        auto [it, __] = entries.insert({score, penalty, current_team});
        team_to_entry[current_team] = it;

        auto [favorite_score, favorite_penalty, ___] = *team_to_entry[0];
        std::cout << team_count + 1 - entries.order_of_key({favorite_score, favorite_penalty, team_count}) << '\n';
    }

    return 0;
}
