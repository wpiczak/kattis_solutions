#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int professor_count;
    std::cin >> professor_count;

    std::vector<int> numbers(professor_count);
    std::vector<int> professors(professor_count);
    for (int i = 0; i < professor_count; ++i) {
        professors[i] = i;
        std::cin >> numbers[i];
    }

    int index = 0;
    while (professors.size() > 1) {
        index = (index + numbers[professors[index]] - 1) % professors.size();
        professors.erase(professors.begin() + index);
        if (index == professors.size()) index = 0;
    }

    std::cout << professors[0] + 1;

    return 0;
}
