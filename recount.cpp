#include <algorithm>
#include <iostream>
#include <unordered_map>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, int> votes;
    std::string candidate;
    while (std::getline(std::cin, candidate)) {
        if (candidate == "***") break;
        const auto it = votes.insert({candidate, 0});
        ++it.first->second;
    }

    auto winner = votes.begin();
    bool has_majority = true;
    for (auto it = ++votes.begin(); it != votes.end(); ++it) {
        if (it->second > winner->second) {
            winner = it;
            has_majority = true;
        } else if (it->second == winner->second) has_majority = false;
    }

    if (has_majority) std::cout << winner->first;
    else std::cout << "Runoff!";

    return 0;
}
