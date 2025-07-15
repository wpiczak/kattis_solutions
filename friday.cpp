#include <iostream>

int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int day_count;
        int month_count;
        std::cin >> day_count >> month_count;

        int friday_count = 0;
        int month_start = 0;
        for (int j = 0; j < month_count; ++j) {
            int month_length;
            std::cin >> month_length;

            if (month_length >= 13 && (month_start + 12) % 7 == 5) ++friday_count;

            month_start += month_length;
        }
        std::cout << friday_count << '\n';
    }

    return 0;
}
