#include <iostream>

int main() {
    std::string positions;
    std::cin >> positions;

    int first_count = 0;
    int second_count = 0;
    int third_count = 0;

    for (int i = 1; i < positions.length(); ++i) {
        if (i == 1) {
            if (positions[0] != positions[1]) {
                ++first_count;
                ++second_count;
                ++third_count;
            }

            if (positions[1] == 'D') ++first_count;
            if (positions[1] == 'U') ++second_count;
        } else {
            if (positions[i - 1] != positions[i]) ++third_count;

            if (positions[i] == 'D') first_count += 2;
            if (positions[i] == 'U') second_count += 2;
        }
    }

    std::cout << first_count << '\n' << second_count << '\n' << third_count;

    return 0;
}
