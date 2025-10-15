#include <iostream>
#include <queue>
#include <vector>

int main() {
    int size;
    std::cin >> size;

    std::vector child_count(size, 0);
    std::vector input(size, 0);

    for (int i = 0; i < size; ++i) {
        int parent;
        std::cin >> parent;
        --parent;

        ++child_count[parent];
        input[i] = parent;
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> queue;
    for (int i = 0; i < size; ++i)
        queue.emplace(child_count[i], i);

    std::vector output(size, 0);
    bool error = false;
    for (int i = 0; i < size; ++i) {
        auto [remaining_child_count, parent] = queue.top();
        queue.pop();

        if (remaining_child_count != 0) {
            error = true;
            break;
        }

        output[i] = parent;

        --child_count[input[i]];
        queue.emplace(child_count[input[i]], input[i]);
    }

    if (!error) for (int i = 0; i < size; ++i) std::cout << output[i] + 1 << '\n';
    else std::cout << "Error\n";

    return 0;
}
