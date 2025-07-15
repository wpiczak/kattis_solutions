#include <iostream>
#include <limits>
#include <vector>

std::string stretch(const std::string& input, int scaling_factor) {
    std::string result{};
    for (const char& chr : input)
        result.append(scaling_factor, chr);
    return result;
}

int main() {
    std::size_t row_count;
    std::size_t column_count;
    int row_scaling_factor;
    int column_scaling_factor;

    std::cin >> row_count >> column_count;
    std::cin >> row_scaling_factor >> column_scaling_factor;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::string> input_lines{row_count, ""};
    for (int i = 0; i < row_count; ++i)
        std::getline(std::cin, input_lines[i]);

    for (int i = 0; i < row_count; ++i)
        for (int j = 0; j < row_scaling_factor; ++j)
            std::cout << stretch(input_lines[i], column_scaling_factor) << '\n';

    return 0;
}
