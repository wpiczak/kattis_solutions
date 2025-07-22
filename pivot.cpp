#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;

    std::vector<int> array(size);
    for (int i = 0; i < size; ++i)
        std::cin >> array[i];

    std::vector<bool> is_pivot(size, true);

    int max = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < max) is_pivot[i] = false;
        else max = array[i];
    }

    int min = array[size - 1];
    for (int i = size - 2; i >= 0; --i) {
        if (array[i] >= min) is_pivot[i] = false;
        else min = array[i];
    }

    std::cout << std::count(is_pivot.begin(), is_pivot.end(), true);

    return 0;
}
