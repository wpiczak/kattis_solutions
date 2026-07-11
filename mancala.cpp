#include <iostream>
#include <vector>

std::vector<int> next_board(const std::vector<int>& board) {
    int index = 0;
    while (index < board.size() && board[index] != 0) ++index;

    std::vector<int> result = board;
    if (index == board.size()) result.push_back(index + 1);
    else result[index] = index + 1;
    for (int i = 0; i < index; ++i) --result[i];

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input_count;
    std::cin >> input_count;

    std::vector<std::vector<int>> cache;
    cache.push_back({});

    while (input_count--) {
        int query_index;
        int count;
        std::cin >> query_index >> count;

        while (cache.size() <= count)
            cache.push_back(next_board(cache.back()));

        std::cout << query_index << ' ' << cache[count].size() << '\n';
        for (int i = 0; i < cache[count].size(); ++i) {
            std::cout << cache[count][i];
            std::cout << ((i % 10 == 9 && i + 1 < cache[count].size()) ? '\n' : ' ');
        }
        std::cout << std::endl;
    }
}
