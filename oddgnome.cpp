#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int gnomeCount;
        scanf("%d", &gnomeCount);
        int currentGnome = -1, previousGnome = -1;
        bool found = false;
        for (int i = 1; i <= gnomeCount; i++) {
            scanf("%d", &currentGnome);
            if (!found && previousGnome != -1 && currentGnome - previousGnome != 1) {
                printf("%d\n", i);
                found = true;
            }
            previousGnome = currentGnome;
        }
    }
    return 0;
}
