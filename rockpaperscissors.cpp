#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::cout << std::fixed << std::setprecision(3);

    int n;
    int k;
    std::cin >> n;
    bool first = true;
    while (n != 0) {
        std::cin >> k;

        if (first) first = false;
        else std::cout << '\n';

        std::vector<int> wins, losses;
        wins.resize(n, 0);
        losses.resize(n, 0);

        for (int i = 0; i < k * n * (n - 1) / 2; ++i) {
            int p1, p2;
            std::string m1, m2;
            std::cin >> p1 >> m1 >> p2 >> m2;

            if (m1 == m2) continue;
            if ((m1 == "rock" && m2 == "paper") || (m1 == "paper" && m2 == "scissors") || (m1 == "scissors" && m2 == "rock")) {
                ++wins[p2 - 1];
                ++losses[p1 - 1];
            } else{
                ++wins[p1 - 1];
                ++losses[p2 - 1];
            }
        }

        for (int p = 0; p < n; ++p) {
            if (wins[p] + losses[p] == 0) std::cout << "-\n";
            else std::cout << static_cast<double>(wins[p]) / (wins[p] + losses[p]) << '\n';
        }

        std::cin >> n;
    }
}
