#include <iostream>
#include <vector>

int main() {
    int length;
    int width;
    std::cin >> length >> width;

    int count;
    int range;
    std::cin >> count >> range;

    std::vector<int> walls_reached(count);
    for (int i = 0; i < count; ++i) {
        int x;
        int y;
        std::cin >> x >> y;

        if ((2 * x + length) * (2 * x + length) + 4 * y * y <= 4 * range * range)
            walls_reached[i] |= 1;
        if ((2 * x - length) * (2 * x - length) + 4 * y * y <= 4 * range * range)
            walls_reached[i] |= 2;
        if (4 * x * x + (2 * y + width) * (2 * y + width) <= 4 * range * range)
            walls_reached[i] |= 4;
        if (4 * x * x + (2 * y - width) * (2 * y - width) <= 4 * range * range)
            walls_reached[i] |= 8;
    }

    for (int i = 0; i < count; ++i) {
        if (walls_reached[i] == 15) {
            std::cout << '1';
            return 0;
        }
    }

    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if ((walls_reached[i] | walls_reached[j]) == 15) {
                std::cout << '2';
                return 0;
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            for (int k = j + 1; k < count; ++k) {
                if ((walls_reached[i] | walls_reached[j] | walls_reached[k]) == 15) {
                    std::cout << '3';
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            for (int k = j + 1; k < count; ++k) {
                for (int l = k + 1; l < count; ++l) {
                    if ((walls_reached[i] | walls_reached[j] | walls_reached[k] | walls_reached[l]) == 15) {
                        std::cout << '4';
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "Impossible";

    return 0;
}
