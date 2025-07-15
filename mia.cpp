#include <bits/stdc++.h>

int main() {
    while (true) {
        int a1, a2, b1, b2;
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        int score1 = 0, score2 = 0;
        if (a1 == 0 && a2 == 0 && b1 == 0 && b2 == 0)
            break;

        // Player 1
        if ((a1 == 2 && a2 == 1) || (a1 == 1 && a2 == 2))
            score1 = 1000;
        else if (a1 == a2)
            score1 = a1 * 100;
        else {
            if (a1 > a2) score1 = a1 * 10 + a2;
            else score1 = a2 * 10 + a1;
        }

        // Player 2
        if ((b1 == 2 && b2 == 1) || (b1 == 1 && b2 == 2))
            score2 = 1000;
        else if (b1 == b2)
            score2 = b1 * 100;
        else {
            if (b1 > b2) score2 = b1 * 10 + b2;
            else score2 = b2 * 10 + b1;
        }

        if (score1 > score2) printf("Player 1 wins.\n");
        else if (score2 > score1) printf("Player 2 wins.\n");
        else printf("Tie.\n");
    }
  
    return 0;
}
