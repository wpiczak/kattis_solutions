#include <bits/stdc++.h>

int main() {
  int caseCount;
  scanf("%d\n", &caseCount);
  
  for (int caseIndex = 0; caseIndex < caseCount; caseIndex++) {
    char a, b, c, d;
    scanf("%c %c %c %c\n", &a, &b, &c, &d);
    
    int startX, startY, endX, endY;
    startX = a - 'A';
    startY = b - '1';
    endX = c - 'A';
    endY = d - '1';
    
    if (((startX + startY) & 1) != ((endX + endY) & 1)) {
      printf("Impossible\n");
      continue;
    } else if (startX == endX && startY == endY) {
      printf("0 %c %c\n", a, b);
      continue;
    }

    std::pair<char, int> path[4];
    path[0] = {'A' + startX, 1 + startY};
    int pathLength = 1;
    bool finished = false;
    if ((startX + startY) & 1) {
      if (startX + startY != 7) {
        int distance = ((startX + startY) - 7) / 2;
        startX -= distance;
        startY -= distance;
        path[pathLength] = {'A' + startX, 1 + startY};
        pathLength++;
        if (startX == endX && startY == endY) finished = true;
      }

      int successorX = (7 + endX - endY) / 2;
      int successorY = (7 - endX + endY) / 2;
      if (!finished && startX != successorX && startY != successorY) {
        startX = successorX;
        startY = successorY;
        path[pathLength] = {'A' + startX, 1 + startY};
        pathLength++;
        if (startX == endX && startY == endY) finished = true;
      }
      
      if (!finished) {
        path[pathLength] = {'A' + endX, 1 + endY};
        pathLength++;
      }
    } else {
      if (startX - startY != 0) {
        int distance = ((startX - startY)) / 2;
        startX -= distance;
        startY += distance;
        path[pathLength] = {'A' + startX, 1 + startY};
        pathLength++;
        if (startX == endX && startY == endY) finished = true;
      }

      int successorX = (endX + endY) / 2;
      int successorY = (endX + endY) / 2;
      if (!finished && startX != successorX && startY != successorY) {
        startX = successorX;
        startY = successorY;
        path[pathLength] = {'A' + startX, 1 + startY};
        pathLength++;
        if (startX == endX && startY == endY) finished = true;
      }

      if (!finished) {
        path[pathLength] = {'A' + endX, 1 + endY};
        pathLength++;
      }
    }
    
    printf("%d ", pathLength - 1);
    for (int i = 0; i < pathLength; i++) {
      auto [x, y] = path[i];
      printf("%c %d", x, y);
      if (i != pathLength - 1) printf(" ");
      else printf("\n");
    }
  }
  
  return 0;
}
