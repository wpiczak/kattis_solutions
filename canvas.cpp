#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int canvas_count;
        std::cin >> canvas_count;

        std::priority_queue<long long, std::vector<long long>, std::greater<>> queue;
        for (int i = 0; i < canvas_count; ++i) {
            int size;
            std::cin >> size;
            queue.push(size);
        }

        long long result = 0;
        while (queue.size() >= 2) {
            const auto first = queue.top();
            queue.pop();

            const auto second = queue.top();
            queue.pop();

            result += first + second;
            queue.push(first + second);
        }

        std::cout << result << '\n';
    }

    return 0;
}
