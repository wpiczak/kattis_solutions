#include <iostream>

bool test(const std::string& number) {
    int sum = 0;

    for (int i = 0; i < number.length(); ++i) {
        if ((number.length() - i) % 2 == 0) {
            if (const int temp = 2 * (number[i] - '0'); temp > 9)
                sum += temp % 10 + temp / 10;
            else sum += temp;
        } else sum += number[i] - '0';
    }

    return sum % 10 == 0;
}

int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        std::string number;
        std::cin >> number;
        std::cout << (test(number) ? "PASS" : "FAIL") << '\n';
    }

    return 0;
}
