#include <iostream>
#include <queue>

int main() {
    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int n;
        std::cin >> n;

        std::deque<int> deck;
        while (n > 0) {
            deck.push_front(n);
            for (int i = 0; i < n; ++i) {
                int card = deck.back();
                deck.pop_back();
                deck.push_front(card);
            }
            --n;
        }

        for (const int card : deck)
            std::cout << card << ' ';
        std::cout << '\n';
    }

    return 0;
}
