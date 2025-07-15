#include <bits/stdc++.h>

int main() {
  int playerCount;
  int state = -1;
  std::cin >> playerCount;
  
  std::string previous;
  std::cin >> previous;
  for (int i = 1; i < playerCount; i++) {
    std::string current;
    std::cin >> current;
    if ((state == -1 || state == 1) && (previous < current)) state = 1;
    else if ((state == -1 || state == 2) && (previous > current)) state = 2;
    else {
      state = 0;
      break;
    }
    previous = current;
  }
  
  if (state == 0) printf("NEITHER");
  else if (state == 1) printf("INCREASING");
  else if (state == 2) printf("DECREASING");
  
  return 0;
}
