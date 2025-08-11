#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::stack<int> cards;
    for (int i = 0; i < n; ++i) {
        int card;
        std::cin >> card;

        if (!cards.empty() && (cards.top() + card) % 2 == 0) cards.pop();
        else cards.push(card);
    }

    std::cout << cards.size();

    return 0;
}
