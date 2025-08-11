#include <iostream>
#include <stack>

int throw_egg(const int current_position, const int n, const int p) {
    return (n + (current_position + p) % n) % n;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int k;
    std::cin >> n >> k;

    std::stack<int> moves;
    int current_position = 0;
    for (int i = 0; i < k; ++i) {
        std::string command;
        std::cin >> command;

        if (command == "undo") {
            int m;
            std::cin >> m;

            for (int j = 0; j < m; ++j) {
                current_position = throw_egg(current_position, n, -moves.top());
                moves.pop();
            }
        } else {
            const int p = std::stoi(command);
            current_position = throw_egg(current_position, n, p);
            moves.push(p);
        }
    }

    std::cout << current_position;

    return 0;
}
