#include <bits/stdc++.h>

int main() {
  int teaTypeCount;
  scanf("%d", &teaTypeCount);
  
  int teaPrices[teaTypeCount];
  for (int i = 0; i < teaTypeCount; i++)
    scanf("%d", &teaPrices[i]);
  
  int toppingTypeCount;
  scanf("%d", &toppingTypeCount);

  int toppingPrices[toppingTypeCount];
  for (int i = 0; i < toppingTypeCount; i++)
    scanf("%d", &toppingPrices[i]);
  
  int lowestPrice = 1'000'000;
  for (int i = 0; i < teaTypeCount; i++) {
    int validToppingCount;
    scanf("%d", &validToppingCount);
    for (int j = 0; j < validToppingCount; j++) {
      int validTopping;
      scanf("%d", &validTopping);
      if (lowestPrice > teaPrices[i] + toppingPrices[validTopping - 1])
        lowestPrice = teaPrices[i] + toppingPrices[validTopping - 1];
    }
  }
  
  int cash;
  scanf("%d", &cash);
  int bubbleTeaCount = cash / lowestPrice;
  printf("%d", (bubbleTeaCount > 0) ? bubbleTeaCount - 1 : 0);
  
  return 0;
}
