#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::multiset<int> lower;
    std::multiset<int> upper;

    std::string input;
    while (std::cin >> input) {
        if (input != "#") {
            int value = std::stoi(input);

            if (lower.empty()) {
                lower.insert(value);
                continue;
            }

            if (value > *(--lower.end())) upper.insert(value);
            else lower.insert(value);

            if (lower.size() > upper.size() + 1) {
                auto last = *(--lower.end());
                lower.erase(--lower.end());
                upper.insert(last);
            } else if (lower.size() < upper.size()) {
                auto first = *upper.begin();
                upper.erase(upper.begin());
                lower.insert(first);
            }
        } else {
            if (lower.size() == upper.size()) {
                std::cout << *upper.begin() << '\n';
                upper.erase(upper.begin());
            } else {
                std::cout << *(--lower.end()) << '\n';
                lower.erase(--lower.end());
            }
        }
    }

    return 0;
}
