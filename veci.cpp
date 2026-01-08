#include <algorithm>
#include <iostream>
#include <vector>

int digits_to_number(const std::vector<int>& digits) {
    int result = 0;
    for (const int digit : digits)
        result = result * 10 + digit;
    return result;
}

std::vector<int> number_to_digits(int number) {
    std::vector<int> result;
    while (number > 0) {
        result.push_back(number % 10);
        number /= 10;
    }
    std::ranges::reverse(result);
    return result;
}

int main() {
    int input;
    std::cin >> input;

    auto digits = number_to_digits(input);

    int result = 0;
    while (std::ranges::next_permutation(digits).found) {
        result = digits_to_number(digits);
        if (result > input) break;
        result = 0;
    }

    std::cout << result << '\n';

    return 0;
}
