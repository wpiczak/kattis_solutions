#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];

    std::vector<int> result(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i] |= matrix[i][j];

    bool is_first = true;
    for (const int& value : result) {
        if (is_first) is_first = false;
        else std::cout << ' ';
        std::cout << value;
    }

    return 0;
}
