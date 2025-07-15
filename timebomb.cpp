#include <array>
#include <iostream>

int decode_digit(const std::array<std::string, 5>& lines, const int start) {
    static const std::array<std::string, 5> digit_representations = {
        "***   * *** *** * * *** *** *** *** ***",
        "* *   *   *   * * * *   *     * * * * *",
        "* *   * *** *** *** *** ***   * *** ***",
        "* *   * *     *   *   * * *   * * *   *",
        "***   * *** ***   * *** ***   * *** ***"
    };

    for (int i = 0; i < 10; ++i) {
        bool are_equal = true;
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (digit_representations[j][4 * i + k] != lines[j][start + k]) {
                    are_equal = false;
                    break;
                }
            }
            if (!are_equal) break;
        }
        if (are_equal) return i;
    }

    return -1;
}

int decode_digits(const std::array<std::string, 5>& lines) {
    const int digit_count = (static_cast<int>(lines[0].length()) + 1) / 4;
    int result = 0;
    for (int i = 0; i < digit_count; ++i) {
        int digit = decode_digit(lines, 4 * i);
        if (digit == -1) return -1;
        result = result * 10 + digit;
    }

    return result;
}

int main() {
    std::array<std::string, 5> lines;
    for (int i = 0; i < 5; ++i)
        std::getline(std::cin, lines[i]);

    auto decoded_digits = decode_digits(lines);
    if (decoded_digits == -1 || decoded_digits % 6 != 0)
        std::cout << "BOOM!!";
    else std::cout << "BEER!!";

    return 0;
}
