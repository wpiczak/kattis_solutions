#include <bits/stdc++.h>

int main() {
  int caseCount;
  scanf("%d", &caseCount);
  
  for (int i = 0; i < caseCount; i++) {
    int prizeTypeCount, stickerTypeCount;
    scanf("%d %d", &prizeTypeCount, &stickerTypeCount);
    int prizeValue[prizeTypeCount], stickerCount[stickerTypeCount];
    bool isRequiredForPrize[prizeTypeCount][stickerTypeCount];
    
    for (auto &x: isRequiredForPrize) for (auto &y: x) y = false;
    std::fill(prizeValue, prizeValue + prizeTypeCount, 0);
    std::fill(stickerCount, stickerCount + stickerTypeCount, 0);
    
    for (int j = 0; j < prizeTypeCount; j++) {
      int requiredStickerCount;
      scanf("%d", &requiredStickerCount);
      
      for (int k = 0; k < requiredStickerCount; k++) {
        int sticker;
        scanf("%d", &sticker);
        isRequiredForPrize[j][sticker - 1] = true;
      }
      
      int prize;
      scanf("%d", &prize);
      prizeValue[j] = prize;
    }
    
    for (int j = 0; j < stickerTypeCount; j++)
      scanf("%d", &stickerCount[j]);
    
    int total = 0;
    for (int j = 0; j < prizeTypeCount; j++) {
      int highestPurchaseQuantity = 2'147'483'647;
      for (int k = 0; k < stickerTypeCount; k++)
        if (isRequiredForPrize[j][k])
          highestPurchaseQuantity = (stickerCount[k] < highestPurchaseQuantity) ? stickerCount[k] : highestPurchaseQuantity;
      total += prizeValue[j] * highestPurchaseQuantity;
    }
    
    printf("%d\n", total);
  }
  
  return 0;
}
