#include <bits/stdc++.h>

int main() {
  int safetyLimit;
  int eventCount;
  std::cin >> safetyLimit >> eventCount;
  
  std::string action;
  int groupSize;
  int rejectedCount = 0;
  int currentCount = 0;
  for (int i = 0; i < eventCount; i++) {
    std::cin >> action >> groupSize;
    if (action == "enter") {
      if (currentCount + groupSize > safetyLimit) rejectedCount++;
      else currentCount += groupSize;
    } else if (action == "leave") currentCount -= groupSize;
  }
  std::cout << rejectedCount;
  
  return 0;
}
