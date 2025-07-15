#include <bits/stdc++.h>

int reverseInteger(int n) {
  int result = 0;
  while (n > 0) {
    result = result * 10 + (n % 10);
    n = (n - n % 10) / 10;
  }
  return result;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int reverseA = reverseInteger(a);
  int reverseB = reverseInteger(b);
  if (reverseA > reverseB) printf("%d", reverseA);
  else printf("%d", reverseB);
}
