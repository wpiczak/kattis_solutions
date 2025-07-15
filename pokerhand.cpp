#include <bits/stdc++.h>

int main() {
  int occurrenceCount[13];
  std::fill(occurrenceCount, occurrenceCount + 13, 0);
  for (int i = 0; i < 5; i++) {
    std::string card;
    std::cin >> card;
    if (card[0] == 'A') occurrenceCount[0]++;
    else if (card[0] == 'T') occurrenceCount[9]++;
    else if (card[0] == 'J') occurrenceCount[10]++;
    else if (card[0] == 'Q') occurrenceCount[11]++;
    else if (card[0] == 'K') occurrenceCount[12]++;
    else occurrenceCount[card[0] - '1']++;
  }
  
  int strength = 0;
  for (int i = 0; i < 13; i++)
    if (occurrenceCount[i] > strength) strength = occurrenceCount[i];
  std::cout << strength;
}
