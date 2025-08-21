#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int participant_count;
    int point_requirement;
    int line_count;
    std::cin >> participant_count >> point_requirement >> line_count;

    std::unordered_map<std::string, int> points;
    for (int i = 0; i < participant_count; ++i) {
        std::string name;
        std::cin >> name;
        points.insert({name, 0});
    }

    std::vector<std::string> winners;
    for (int i = 0; i < line_count; ++i) {
        std::string name;
        int score;
        std::cin >> name >> score;

        if (points[name] >= point_requirement) continue;
        points[name] += score;

        if (points[name] >= point_requirement) {
            winners.push_back(name);
        }
    }

    if (winners.empty()) std::cout << "No winner!";
    else for (const auto& winner : winners)
        std::cout << winner << " wins!\n";

    return 0;
}
