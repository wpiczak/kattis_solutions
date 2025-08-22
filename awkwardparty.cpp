#include <iostream>
#include <unordered_map>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<int, int> last_position;

    int n;
    std::cin >> n;

    int awkwardness = n;
    for (int i = 0; i < n; ++i) {
        int language;
        std::cin >> language;

        auto it = last_position.find(language);
        if (it != last_position.end())
            awkwardness = std::min(i - it->second, awkwardness);

        last_position[language] = i;
    }

    std::cout << awkwardness;

    return 0;
}
