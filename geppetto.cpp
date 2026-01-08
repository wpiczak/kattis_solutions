#include <iostream>
#include <vector>

int main() {
    int ingredient_count;
    int restriction_count;
    std::cin >> ingredient_count >> restriction_count;

    std::vector<int> prohibited_pairs(restriction_count);
    for (int i = 0; i < restriction_count; ++i) {
        int first;
        int second;
        std::cin >> first >> second;

        --first;
        --second;

        prohibited_pairs[i] = (1 << first) | (1 << second);
    }

    int recipe_count = 0;
    for (int recipe = 0; recipe < (1 << ingredient_count); ++recipe) {
        bool prohibited = false;
        for (int i = 0; i < restriction_count; ++i) {
            if ((recipe & prohibited_pairs[i]) == prohibited_pairs[i]) {
                prohibited = true;
                break;
            }
        }

        if (!prohibited) ++recipe_count;
    }

    std::cout << recipe_count << '\n';

    return 0;
}
