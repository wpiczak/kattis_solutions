#include <bits/stdc++.h>

int main() {
  int handCount;
  char suitB;
  scanf("%d %c%*c", &handCount, &suitB);
  
  int total = 0;
  for (int i = 0; i < handCount * 4; i++) {
    char type, suit;
    scanf("%c%c%*c", &type, &suit);
    
    if (type == 'A') total += 11;
    else if (type == 'K') total += 4;
    else if (type == 'Q') total += 3;
    else if (type == 'J') {
      if (suit == suitB) total += 20;
      else total += 2;
    } else if (type == 'T') total += 10;
    else if (type == '9' && suit == suitB) total += 14;
  }
  
  printf("%d", total);

  return 0;
}
