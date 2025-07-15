#include <bits/stdc++.h>

int main() {
    while (true) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        else if (a + b == 13) printf("Never speak again.\n");
        else if (a > b) printf("To the convention.\n");
        else if (a < b) printf("Left beehind.\n");
        else if (a == b) printf("Undecided.\n");
    }
    return 0;
}
