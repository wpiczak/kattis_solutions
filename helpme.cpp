#include <bits/stdc++.h>

int main() {
  std::vector<std::string> blackPieces;
  std::vector<std::string> whitePieces;
  std::string current;
  for (int row = 7; row >= 0; row--) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, current);
    for (int column = 0; column <= 7; column++) {
      int index = 2 + column * 4;
      std::stringstream whiteStream;
      std::stringstream blackStream;
      if (current[index] == 'K') whiteStream << 'K' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'k') blackStream << 'K' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'Q') whiteStream << 'Q' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'q') blackStream << 'Q' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'R') whiteStream << 'R' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'r') blackStream << 'R' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'B') whiteStream << 'B' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'b') blackStream << 'B' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'N') whiteStream << 'N' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'n') blackStream << 'N' << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'P') whiteStream << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      if (current[index] == 'p') blackStream << static_cast<char>('a' + column) << static_cast<char>('1' + row);
      std::string whitePiece, blackPiece;
      whiteStream >> whitePiece;
      blackStream >> blackPiece;
      if (whitePiece.size() > 0) whitePieces.push_back(whitePiece);
      if (blackPiece.size() > 0) blackPieces.push_back(blackPiece);
    }
  }
  
  auto whiteComparator = [](const std::string &a, const std::string &b) {
    int aScore = 0, bScore = 0;
    if (a[0] == 'K') aScore += 1000;
    if (a[0] == 'Q') aScore += 500;
    if (a[0] == 'R') aScore += 250;
    if (a[0] == 'B') aScore += 100;
    if (a[0] == 'N') aScore += 50;
    
    if (b[0] == 'K') bScore += 1000;
    if (b[0] == 'Q') bScore += 500;
    if (b[0] == 'R') bScore += 250;
    if (b[0] == 'B') bScore += 100;
    if (b[0] == 'N') bScore += 50;

    if (aScore == bScore) {
      aScore -= (a[a.size() - 1] - '1');
      bScore -= (b[b.size() - 1] - '1');
    }

    if (aScore == bScore) {
      aScore -= (a[a.size() - 2] - 'a');
      bScore -= (b[b.size() - 2] - 'a');
    }
    
    return aScore > bScore;
  };
  
  auto blackComparator = [](const std::string &a, const std::string &b) {
    int aScore = 0, bScore = 0;
    if (a[0] == 'K') aScore += 1000;
    if (a[0] == 'Q') aScore += 500;
    if (a[0] == 'R') aScore += 250;
    if (a[0] == 'B') aScore += 100;
    if (a[0] == 'N') aScore += 50;

    if (b[0] == 'K') bScore += 1000;
    if (b[0] == 'Q') bScore += 500;
    if (b[0] == 'R') bScore += 250;
    if (b[0] == 'B') bScore += 100;
    if (b[0] == 'N') bScore += 50;

    if (aScore == bScore) {
      aScore += (a[a.size() - 1] - '1');
      bScore += (b[b.size() - 1] - '1');
    }

    if (aScore == bScore) {
      aScore -= (a[a.size() - 2] - 'a');
      bScore -= (b[b.size() - 2] - 'a');
    }

    return aScore > bScore;
  };
  
  std::sort(whitePieces.begin(), whitePieces.end(), whiteComparator);
  std::sort(blackPieces.begin(), blackPieces.end(), blackComparator);
  
  std::cout << "White: ";
  auto it = whitePieces.begin();
  for (int i = 0; i < whitePieces.size(); i++) {
    if (i != 0) std::cout << ",";
    std::cout << *it;
    it = std::next(it, 1);
  }
  
  std::cout << "\nBlack: ";
  it = blackPieces.begin();
  for (int i = 0; i < blackPieces.size(); i++) {
    if (i != 0) std::cout << ",";
    std::cout << *it;
    it = std::next(it, 1);
  }
  
  return 0;
}