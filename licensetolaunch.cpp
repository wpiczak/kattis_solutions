#include <bits/stdc++.h>

int main() {
    int n, lowestJunkCount = 1'000'000'000, lowestJunkDay = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int currentJunkCount;
        scanf("%d", &currentJunkCount);
        if (currentJunkCount < lowestJunkCount) {
            lowestJunkCount = currentJunkCount;
            lowestJunkDay = i;
        }
    }
    printf("%d", lowestJunkDay);
    return 0;
}
