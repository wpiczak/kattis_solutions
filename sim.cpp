#include <iostream>
#include <limits>
#include <list>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < case_count; ++i) {
        std::string input;
        std::getline(std::cin, input);

        std::list<char> output;
        auto cursor = output.begin();
        for (const char chr : input) {
            if (chr == '<') {
                if (cursor == output.begin()) continue;
                cursor = output.erase(--cursor);
            } else if (chr == '[') {
                cursor = output.begin();
            } else if (chr == ']') {
                cursor = output.end();
            } else cursor = ++output.insert(cursor, chr);
        }

        for (const char chr : output)
            std::cout << chr;
        std::cout << '\n';
    }

    return 0;
}
