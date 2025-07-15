#include <bits/stdc++.h>

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  
  if (a > b) std::swap(a, b);
  if (b > c) std::swap(b, c);
  if (a > b) std::swap(a, b);
  
  if (c - b == b - a) printf("%d", c + c - b);
  else if (c - b > b - a) printf("%d", b + b - a);
  else printf("%d", a + c - b);
  
  return 0;
}
