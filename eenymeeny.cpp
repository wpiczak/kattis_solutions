#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string rhyme;
    std::getline(std::cin, rhyme);

    const int length = std::ranges::count(rhyme, ' ');

    int children_count;
    std::cin >> children_count;

    std::vector<std::string> children(children_count);
    for (int i = 0; i < children_count; ++i)
        std::cin >> children[i];

    std::vector<std::string> first;
    std::vector<std::string> second;

    int index = 0;
    for (int i = 0; i < children_count; ++i) {
        index = (index + length) % children.size();

        if ((i & 1) == 0) first.push_back(children[index]);
        else second.push_back(children[index]);

        children.erase(children.begin() + index);
    }

    std::cout << first.size() << '\n';
    for (const auto& child : first)
        std::cout << child << '\n';

    std::cout << second.size() << '\n';
    for (const auto& child : second)
        std::cout << child << '\n';

    return 0;
}
