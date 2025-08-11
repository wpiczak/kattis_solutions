#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    bool is_first = true;
    while (n != 0) {
        if (is_first) is_first = false;
        else std::cout << '\n';

        int first_stack_size = 0;
        int second_stack_size = 0;

        for (int i = 0; i < n; ++i) {
            std::string command;
            std::cin >> command;

            int count;
            std::cin >> count;

            if (command == "DROP") {
                std::cout << "DROP 2 " << count << '\n';
                second_stack_size += count;
            } else {
                if (first_stack_size > 0) {
                    const int k = std::min(first_stack_size, count);
                    std::cout << "TAKE 1 " << k << '\n';
                    first_stack_size -= k;
                    count -= k;
                }

                if (count > 0) {
                    std::cout << "MOVE 2->1 " << second_stack_size << '\n';
                    std::cout << "TAKE 1 " << count << '\n';
                    first_stack_size = second_stack_size;
                    first_stack_size -= count;
                    second_stack_size = 0;
                }
            }
        }

        std::cin >> n;
    }

    return 0;
}
