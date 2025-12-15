#include <iostream>

int main() {
    int winner = 0;
    int highest_score = 0;
    for (int i = 0; i < 5; ++i) {
        int score = 0;
        for (int j = 0; j < 4; ++j) {
            int grade;
            std::cin >> grade;
            score += grade;
        }

        if (score > highest_score) {
            highest_score = score;
            winner = i + 1;
        }
    }

    std::cout << winner << ' ' << highest_score;

    return 0;
}
