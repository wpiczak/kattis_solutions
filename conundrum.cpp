#include <iostream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    int result = 0;
    for (int i = 0; i < line.length(); ++i) {
        if (i % 3 == 0 && line[i] != 'P') ++result;
        if (i % 3 == 1 && line[i] != 'E') ++result;
        if (i % 3 == 2 && line[i] != 'R') ++result;
    }

    std::cout << result;

    return 0;
}
