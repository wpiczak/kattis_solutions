#include <algorithm>
#include <iostream>

int main() {
    std::string input;
    std::cin >> input;

    const std::string sorted_input = input;
    std::ranges::sort(input);

    int k;
    std::cin >> k;

    bool result = true;
    for (int i = input.size() - k; i < k; ++i) {
        if (input[i] != sorted_input[i]) {
            result = false;
            break;
        }
    }

    if (result) std::cout << "Yes";
    else std::cout << "No";

    return 0;
}
