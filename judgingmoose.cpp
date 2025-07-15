#include <bits/stdc++.h>

int main() {
    int left, right;
    scanf("%d %d", &left, &right);
    if (left + right == 0)
        printf("Not a moose");
    else if (left == right)
        printf("Even %d", left + right);
    else if (left > right)
        printf("Odd %d", left * 2);
    else if (left < right)
        printf("Odd %d", right * 2);
    return 0;
}
