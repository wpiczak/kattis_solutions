#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::getline(std::cin, input);
    std::string vowels = "aeiouAEIOU";
    int vowelCount = 0;
    for (int i = 0; i < input.length(); i++)
        if (vowels.find(input[i]) != std::string::npos) vowelCount++;
    std::cout << vowelCount;

    return 0;
}
