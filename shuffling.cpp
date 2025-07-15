#include <bits/stdc++.h>

void shuffle(int cards[], int cardCount, bool outShuffle) {
  int cardsCopy[cardCount];
  std::copy(cards, cards + cardCount, cardsCopy);

  if (outShuffle) {
    cards[0] = cardsCopy[0];
    for (int i = 0; i < cardCount / 2; i++) {
      cards[2 * i + 2 * (cardCount % 2)] = cardsCopy[i + (cardCount % 2)];
      cards[2 * i + 1] = cardsCopy[cardCount / 2 + i + (cardCount % 2)];
    }
  } else {
    cards[0] = cardsCopy[cardCount / 2];
    for (int i = 0; i < cardCount / 2; i++) {
      cards[2 * i + 1] = cardsCopy[i];
      cards[2 * i + 2 * ((cardCount % 2))] = cardsCopy[cardCount / 2 + i + (cardCount % 2)];
    }
  }
}

int main() {
  int cardCount;
  std::string shuffleType;
  std::cin >> cardCount >> shuffleType;
  
  int cards[cardCount];
  int initialCards[cardCount];
  for (int i = 0; i < cardCount; i++) {
    cards[i] = i;
    initialCards[i] = i;
  }

  int shuffleCount = 0;
  while (true) {
    shuffleCount++;
    shuffle(cards, cardCount, (shuffleType == "out"));
    bool solved = true;
    for (int i = 0; i < cardCount; i++)
      if (cards[i] != initialCards[i]) solved = false;
    if (solved) break;
  }
  
  printf("%d", shuffleCount);
  
  return 0;
}
