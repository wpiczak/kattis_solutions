#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int team_count;
        std::cin >> team_count;

        std::vector<int> scores(3 * team_count);
        for (int i = 0; i < 3 * team_count; ++i)
            std::cin >> scores[i];

        std::ranges::sort(scores, std::greater());

        int result = 0;
        for (int i = 0; i < team_count; ++i)
            result += scores[2 * i + 1];

        std::cout << result << '\n';
    }

    return 0;
}
