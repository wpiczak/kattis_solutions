#include <bits/stdc++.h>

int main() {
  int cardCount, turnCount;
  std::cin >> cardCount >> turnCount;
  
  std::vector<std::string> cardPictures(cardCount, "?");
  std::string first, second;
  int firstPosition, secondPosition;
  for (int currentTurn = 0; currentTurn < turnCount; currentTurn++) {
    std::cin >> firstPosition >> secondPosition;
    std::cin >> first >> second;
    if (first == second) {
      cardPictures[firstPosition - 1] = "-";
      cardPictures[secondPosition - 1] = "-";
      continue;
    }
    cardPictures[firstPosition - 1] = first;
    cardPictures[secondPosition - 1] = second;
  }
  
  std::unordered_set<std::string> visited;
  int hiddenCardCount = 0;
  int pairCount = 0;
  int foundCardCount = 0;
  for (int i = 0; i < cardCount; i++) {
    if (cardPictures[i] == "-") continue;
    if (cardPictures[i] == "?") {
      hiddenCardCount++;
      continue;
    }
    
    if (visited.count(cardPictures[i])) pairCount++;
    else visited.insert(cardPictures[i]);
    foundCardCount++;
  }
  
  int score = pairCount;
  if (hiddenCardCount == foundCardCount - 2 * pairCount) score += hiddenCardCount;
  else if (foundCardCount == 2 * pairCount && hiddenCardCount == 2) score++;
  std::cout << score;
  
  return 0;
}
