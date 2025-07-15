#include <bits/stdc++.h>

struct PairHash {
  template<typename T1, typename T2>
  std::size_t operator()(const std::pair<T1, T2> &target) const {
    auto firstHash = std::hash<T1>{}(target.first);
    auto secondHash = std::hash<T2>{}(target.second);
    return firstHash ^ secondHash;
  }
};

int main() {
  std::unordered_map<std::pair<int, int>, char, PairHash> board;
  std::string whiteLine, blackLine;
  
  std::getline(std::cin, whiteLine);
  std::getline(std::cin, blackLine);
  
  std::stringstream whiteStream(whiteLine.substr(7));
  std::stringstream blackStream(blackLine.substr(7));
  
  std::string whitePiece;
  while (std::getline(whiteStream, whitePiece, ',')) {
    int row = whitePiece[whitePiece.size() - 1] - '1';
    int column = whitePiece[whitePiece.size() - 2] - 'a';
    board[{row, column}] = (whitePiece.size() == 2) ? 'P' : whitePiece[0];
  }
  
  std::string blackPiece;
  while (std::getline(blackStream, blackPiece, ',')) {
    int row = blackPiece[blackPiece.size() - 1] - '1';
    int column = blackPiece[blackPiece.size() - 2] - 'a';
    board[{row, column}] = (blackPiece.size() == 2) ? 'p' : std::tolower(blackPiece[0]);
  }
  
  for (int row = 7; row >= 0; row--) {
    std::cout << "+---+---+---+---+---+---+---+---+\n";
    for (int column = 0; column <= 7; column++) {
      std::string background = ((row + column) % 2 == 0) ? ":" : ".";
      std::cout << "|" << background;
      if (board.count({row, column}) == 0) std::cout << background;
      else std::cout << board[{row, column}];
      std::cout << background;
      if (column == 7) std::cout << "|\n";
    }
    if (row == 0) std::cout << "+---+---+---+---+---+---+---+---+";
  }
  
  return 0;
}
