#include <bits/stdc++.h>

int main() {
    int caseId = 1;
    while (true) {
        int n;
        if (scanf("%d", &n) != 1) break;
        int minimum = 1'000'000, maximum = -1'000'000;
        while (n--) {
            int current;
            scanf("%d", &current);
            if (current < minimum) minimum = current;
            if (current > maximum) maximum = current;
        }
        printf("Case %d: %d %d %d\n", caseId++, minimum, maximum, maximum - minimum);
    }
    return 0;
}
