#include <iostream>
#include <vector>

int main() {
    int height, width;
    int kernel_height, kernel_width;
    std::cin >> height >> width;
    std::cin >> kernel_height >> kernel_width;

    std::vector<std::vector<int>> image(height, std::vector<int>(width));
    std::vector<std::vector<int>> kernel(kernel_height, std::vector<int>(kernel_width));

    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            std::cin >> image[i][j];

    for (int i = 0; i < kernel_height; ++i)
        for (int j = 0; j < kernel_width; ++j)
            std::cin >> kernel[i][j];

    bool is_first_row = true;
    for (int i = 0; i < height - kernel_height + 1; ++i) {
        if (is_first_row) is_first_row = false;
        else std::cout << '\n';

        bool is_first_column = true;
        for (int j = 0; j < width - kernel_width + 1; ++j) {
            if (is_first_column) is_first_column = false;
            else std::cout << ' ';

            int result = 0;
            for (int k = 0; k < kernel_height; ++k)
                for (int l = 0; l < kernel_width; ++l)
                    result += image[i + k][j + l] * kernel[kernel_height - k - 1][kernel_width - l - 1];
            std::cout << result;
        }
    }

    return 0;
}
