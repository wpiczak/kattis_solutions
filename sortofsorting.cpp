#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<std::string>> inputs;
    while (true) {
        int input_size;
        std::cin >> input_size;
        if (input_size == 0) break;

        std::vector<std::string> names;
        names.reserve(input_size);

        while (input_size--) {
            std::string name;
            std::cin >> name;
            names.push_back(name);
        }

        inputs.push_back(names);
    }

    for (int i = 0; i < inputs.size(); i++) {
        std::stable_sort(inputs[i].begin(), inputs[i].end(), [](const auto& x, const auto& y) {
            return x.substr(0, 2) < y.substr(0, 2);
        });

        if (i) std::cout << '\n';
        for (const auto& name : inputs[i])
            std::cout << name << '\n';
    }

    return 0;
}