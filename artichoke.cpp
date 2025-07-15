#include <bits/stdc++.h>

double price(int n, int p, int a, int b, int c, int d) {
    return p * (sin(a * n + b) + cos(c * n + d) + 2);
}

int main() {
    int p, a, b, c, d, n;
    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    double largestDecline = 0;
    double highestPrice = price(1, p, a, b, c, d);
    for (int i = 2; i <= n; i++) {
        double currentPrice = price(i, p, a, b, c, d);
        if (highestPrice - currentPrice > largestDecline)
            largestDecline = highestPrice - currentPrice;
        if (currentPrice > highestPrice) highestPrice = currentPrice;
    }
    if (largestDecline == 0)
        printf("0.00");
    else printf("%.8lf", largestDecline);
    return 0;
}
