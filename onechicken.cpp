#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m > n) {
        if (m - n > 1) printf("Dr. Chaz will have %d pieces of chicken left over!", m - n);
        else printf("Dr. Chaz will have 1 piece of chicken left over!");
    } else {
        if (n - m > 1) printf("Dr. Chaz needs %d more pieces of chicken!", n - m);
        else printf("Dr. Chaz needs 1 more piece of chicken!");
    }
    return 0;
}
