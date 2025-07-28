#include <algorithm>
#include <iostream>
#include <vector>

std::string to_lower_case(std::string data) {
    std::transform(
        data.begin(), data.end(), data.begin(),
        [](const char& c) { return std::tolower(c); }
    );
    return data;
}

int main() {
    int r;
    int c;
    std::cin >> r >> c;

    bool is_first_case = true;
    while (r != 0 && c != 0) {
        if (is_first_case) is_first_case = false;
        else std::cout << '\n';

        std::vector<std::string> lines(c, std::string(r, ' '));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                std::cin >> lines[j][i];

        std::sort(
            lines.begin(), lines.end(), [](const auto& x, const auto& y) {
                return to_lower_case(x) < to_lower_case(y);
            }
        );

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j)
                std::cout << lines[j][i];
            std::cout << '\n';
        }

        std::cin >> r >> c;
    }

    return 0;
}
