#include <bits/stdc++.h>

int main() {
  int result[100];
  int peopleCount;
  scanf("%d", &peopleCount);
  
  for (int i = 2; i <= peopleCount; i++) {
    int distance;
    scanf("%d", &distance);
    result[distance + 1] = i;
  }
  
  printf("1 ");
  for (int i = 1; i < peopleCount; i++)
    printf("%d ", result[i]);
  
  return 0;
}
