#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int queue_length;
    int time_remaining;
    std::cin >> queue_length >> time_remaining;

    std::vector<std::pair<int, int>> clients(queue_length);
    for (int i = 0; i < queue_length; ++i)
        std::cin >> clients[i].first >> clients[i].second;

    std::ranges::sort(clients, std::greater());

    int total = 0;
    std::vector<bool> busy(time_remaining);
    for (int i = 0; i < queue_length; ++i) {
        for (int j = clients[i].second; j >= 0; --j) {
            if (!busy[j]) {
                busy[j] = true;
                total += clients[i].first;
                break;
            }
        }
    }

    std::cout << total;

    return 0;
}
