#include <iostream>

int main() {
    std::string name;
    std::getline(std::cin, name);

    std::cout << name[0];
    std::size_t it = name.find('-');
    while (it != std::string::npos) {
        std::cout << name[it + 1];
        it = name.find('-', it + 1);
    }

    return 0;
}
