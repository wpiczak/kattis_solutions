#include <algorithm>
#include <array>
#include <iostream>

std::pair<int, int> operator+(const std::pair<int, int>& x, const std::pair<int, int>& y) {
    return {x.first + y.first, x.second + y.second};
}

int main() {
    std::array<std::pair<int, int>, 9> position;
    int knight_count = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char tile;
            std::cin >> tile;
            if (tile == 'k') {
                if (knight_count < 9) position[knight_count] = {i, j};
                ++knight_count;
            }
        }
    }

    if (knight_count != 9) std::cout << "invalid";
    else {
        const std::array<std::pair<int, int>, 8> offsets = {
            {
                {1, 2},
                {2, 1},
                {-1, 2},
                {-2, 1},
                {-1, -2},
                {-2, -1},
                {1, -2},
                {2, -1},
            }
        };

        bool is_valid = true;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 8; ++j) {
                const auto it = std::find(position.begin(), position.end(), position[i] + offsets[j]);
                if (it != position.end()) is_valid = false;
            }
        }

        std::cout << (is_valid ? "valid" : "invalid");
    }

    return 0;
}
