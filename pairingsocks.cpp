#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::stack<int> main;
    std::stack<int> auxiliary;

    for (int i = 0; i < 2 * n; ++i) {
        int sock;
        std::cin >> sock;
        main.push(sock);
    }

    int move_count = 0;
    while (!main.empty()) {
        if (!auxiliary.empty() && main.top() == auxiliary.top()) {
            main.pop();
            auxiliary.pop();
        } else {
            auxiliary.push(main.top());
            main.pop();
        }

        ++move_count;
    }

    if (auxiliary.empty()) std::cout << move_count;
    else std::cout << "impossible";

    return 0;
}
