#include <iostream>
#include <list>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int arm_count;
    int action_count;
    std::cin >> arm_count >> action_count;

    std::list<std::string> artwork;
    std::vector<std::list<std::string>::iterator> arm_pointers;

    for (int i = 0; i < arm_count; ++i) {
        std::string color;
        std::cin >> color;

        artwork.push_back(color);
        arm_pointers.push_back(--artwork.end());
    }

    for (int i = 0; i < action_count; ++i) {
        int arm_index;
        std::string code;
        std::cin >> arm_index >> code;

        if (code == "L") --arm_pointers[arm_index];
        else if (code == "R") ++arm_pointers[arm_index];
        else {
            artwork.insert(arm_pointers[arm_index], code);
            --arm_pointers[arm_index];
        }
    }

    bool is_first = true;
    for (const auto& color : artwork) {
        if (is_first) is_first = false;
        else std::cout << ' ';
        std::cout << color;
    }

    return 0;
}
