#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_index{0};
    int input_size;

    std::cin >> input_size;
    while (std::cin) {
        std::cout << "Case " << (++case_index) << ":\n";

        std::vector<int> input(input_size);
        for (int i = 0; i < input_size; ++i)
            std::cin >> input[i];

        int query_count;
        std::cin >> query_count;
        while (query_count--) {
            int target;
            std::cin >> target;

            int closest_sum = input[0] + input[1];
            for (int i = 0; i < input_size; ++i) {
                for (int j = i + 1; j < input_size; ++j) {
                    const int sum = input[i] + input[j];
                    if (std::abs(sum - target) >= std::abs(closest_sum - target))
                        continue;
                    closest_sum = sum;
                }
            }

            std::cout << "Closest sum to " << target << " is " << closest_sum << ".\n";
        }

        std::cin >> input_size;
    }

    return 0;
}
