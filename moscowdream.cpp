#include <bits/stdc++.h>

int main() {
    int a, b, c, n;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    bool isPossible = ((n >= 3) && (a > 0) && (b > 0) && (c > 0) && (a + b + c >= n));
    printf((isPossible) ? "YES" : "NO");
}
