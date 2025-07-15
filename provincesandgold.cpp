#include <bits/stdc++.h>

int main() {
    int g, s, c;
    scanf("%d %d %d", &g, &s, &c);
    int buyingPower = 3 * g + 2 * s + c;
    if (buyingPower >= 8)
        printf("Province or ");
    else if (buyingPower >= 5)
        printf("Duchy or ");
    else if (buyingPower >= 2)
        printf("Estate or ");
    if (buyingPower >= 6)
        printf("Gold");
    else if (buyingPower >= 3)
        printf("Silver");
    else if (buyingPower >= 0)
        printf("Copper");
    return 0;
}
