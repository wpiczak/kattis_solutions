#include <bits/stdc++.h>

int requiredStars(int rank) {
  if (rank >= 21) return 2;
  else if (rank >= 16) return 3;
  else if (rank >= 11) return 4;
  else if (rank >= 1) return 5;
  return -1;
}

int main() {
  int rank = 25;
  int starCount = 0;
  bool isLegend = false;
  
  char result;
  int consecutiveWinCount = 0;
  while (scanf("%c", &result) && result != '\n') {
    if (result == 'W') {
      consecutiveWinCount++;
      starCount++;
      if (consecutiveWinCount >= 3 && rank >= 6)
        starCount++;
      if (starCount > requiredStars(rank)) {
        starCount = starCount - requiredStars(rank);
        rank--;
        if (rank == 0) isLegend = true;
      }
    } else if (result == 'L') {
      consecutiveWinCount = 0;
      if (rank == 20 && starCount > 0) starCount--;
      if (rank < 20) {
        if (starCount == 0) {
          starCount = requiredStars(rank + 1) - 1;
          rank++;
        } else starCount--;
      }
    }
  }
  
  if (isLegend) std::cout << "Legend";
  else std::cout << rank;
  
  return 0;
}
