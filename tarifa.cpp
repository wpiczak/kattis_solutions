#include <bits/stdc++.h>

int main() {
    int x, inputCount, used = 0;
    scanf("%d", &x);
    scanf("%d", &inputCount);
    for (int i = 0; i < inputCount; i++) {
        int current = 0;
        scanf("%d", &current);
        used += current;
    }
    printf("%d", (inputCount + 1) * x - used);
}
