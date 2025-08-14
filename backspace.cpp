#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::getline(std::cin, input);

    std::vector<char> output;
    for (const char chr : input) {
        if (chr == '<' && !output.empty()) output.pop_back();
        else output.push_back(chr);
    }

    for (const char chr : output)
        std::cout << chr;

    return 0;
}
