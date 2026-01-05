#include <algorithm>
#include <array>
#include <iostream>

bool is_leap_year(const int year) {
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    if (year % 400 == 0) return true;
    return false;
}

bool is_valid_date(const int day, const int month, const int year) {
    if (day == 0 || month == 0 || month > 12 || year < 2000) return false;

    std::array days_in_month = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (is_leap_year(year)) days_in_month[1] = 29;

    return day <= days_in_month[month - 1];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        std::string date;

        std::array<int, 8> digits{};

        for (int i = 0; i < 8; ++i) {
            char input;
            std::cin >> input;
            digits[i] = input - '0';
        }

        std::ranges::sort(digits);

        std::string earliest_date;
        int result = 0;
        do {
            const int year = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
            const int month = digits[4] * 10 + digits[5];
            const int day = digits[6] * 10 + digits[7];

            if (!is_valid_date(day, month, year)) continue;

            if (earliest_date.empty()) {
                earliest_date.resize(10, ' ');
                earliest_date[0] = '0' + digits[6];
                earliest_date[1] = '0' + digits[7];
                earliest_date[3] = '0' + digits[4];
                earliest_date[4] = '0' + digits[5];
                earliest_date[6] = '0' + digits[0];
                earliest_date[7] = '0' + digits[1];
                earliest_date[8] = '0' + digits[2];
                earliest_date[9] = '0' + digits[3];
            }

            ++result;
        } while (std::ranges::next_permutation(digits).found);

        std::cout << result << ' ' << earliest_date << '\n';
    }

    return 0;
}
