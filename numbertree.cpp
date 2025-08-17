#include <iostream>

int main() {
    int height;
    std::cin >> height;

    const std::size_t node_count = (2 << height) - 1;

    std::string path;
    std::cin >> path;

    std::size_t i = 0;
    for (const char direction : path) {
        i *= 2;
        if (direction == 'L') i += 1;
        if (direction == 'R') i += 2;
    }

    std::cout << node_count - i;

    return 0;
}
