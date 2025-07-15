#include <bits/stdc++.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 1) printf("ALL GOOD");
    else if (x != 0 && y == 1) printf("IMPOSSIBLE");
    else printf("%.8lf", static_cast<double>(x) / (1 - y));
    return 0;
}
