#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> cards(12);
    for (int i = 0; i < 12; ++i)
        std::cin >> cards[i];

    int answer_count = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = i + 1; j < 12; ++j) {
            for (int k = j + 1; k < 12; ++k) {
                bool is_set = true;
                for (int l = 0; l < 4; ++l) {
                    is_set = (
                        (cards[i][l] == cards[j][l] && cards[j][l] == cards[k][l]) ||
                        (cards[i][l] != cards[j][l] && cards[j][l] != cards[k][l] && cards[k][l] != cards[i][l])
                    );
                    if (!is_set) break;
                }

                if (is_set) {
                    std::cout << (i + 1) << ' ' << (j + 1) << ' ' << (k + 1) << '\n';
                    ++answer_count;
                }
            }
        }
    }

    if (answer_count == 0)
        std::cout << "no sets\n";

    return 0;
}
