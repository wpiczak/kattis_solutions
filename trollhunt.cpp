#include <iostream>

int main() {
    int bridge_count;
    int knight_count;
    int group_size;
    std::cin >> bridge_count >> knight_count >> group_size;

    --bridge_count;

    const int group_count = knight_count / group_size;
    const int search_duration = (bridge_count - 1) / group_count + 1;

    std::cout << search_duration << '\n';

    return 0;
}
