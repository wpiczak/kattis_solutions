#include <bits/stdc++.h>

int main() {
  std::string attacks, result;
  std::cin >> attacks;
  
  for (int i = 0; i < attacks.size(); i++) {
      int attackSequence = 0;
      if (attacks[i] == 'R' || attacks[i + 1] == 'R' || attacks[i + 2] == 'R')
        attackSequence = attackSequence | 1;
      if (attacks[i] == 'L' || attacks[i + 1] == 'L' || attacks[i + 2] == 'L')
        attackSequence = attackSequence | 2;
      if (attacks[i] == 'B' || attacks[i + 1] == 'B' || attacks[i + 2] == 'B')
        attackSequence = attackSequence | 4;
      
      if (attackSequence == 7) {
        result += 'C';
        i += 2;
        continue;
      }
      
      if (attacks[i] == 'R') result += 'S';
      else if (attacks[i] == 'B') result += 'K';
      else if (attacks[i] == 'L') result += 'H';
  }
  
  std::cout << result;
  
  return 0;
}
