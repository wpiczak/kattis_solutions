#include <bits/stdc++.h>

int main() {
  std::vector<std::string> lines;
  std::string line;
  while (!std::cin.eof()) {
    std::getline(std::cin, line);
    if (line.size() != 0) lines.push_back(line);
    else {
      std::unordered_map<char, std::pair<int, int>> positions;
      char dots[62] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
        'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z'
      };
      
      for (char &dot: dots) {
        for (int lineIndex = 0; lineIndex < lines.size(); lineIndex++) {
          auto position = lines[lineIndex].find(dot);
          if (position == std::string::npos) continue;
          positions[dot] = {lineIndex, position};
          break;
        }
      }
      
      for (int index = 0; index < 62; index++) {
        if (positions.count(dots[index + 1]) == 0) break;
        char current = dots[index], next = dots[index + 1];
        auto currentPosition = positions[current];
        auto nextPosition = positions[next];
        if (currentPosition.first == nextPosition.first) {
          int lineStart = std::min(currentPosition.second, nextPosition.second);
          int lineEnd = std::max(currentPosition.second, nextPosition.second);
          for (int i = lineStart + 1; i < lineEnd; i++) {
            if (lines[currentPosition.first][i] == '|') lines[currentPosition.first][i] = '+';
            else if (lines[currentPosition.first][i] == '.') lines[currentPosition.first][i] = '-';
          }
        } else if (currentPosition.second == nextPosition.second) {
          int lineStart = std::min(currentPosition.first, nextPosition.first);
          int lineEnd = std::max(currentPosition.first, nextPosition.first);
          for (int i = lineStart + 1; i < lineEnd; i++) {
            if (lines[i][currentPosition.second] == '-') lines[i][currentPosition.second] = '+';
            else if (lines[i][currentPosition.second] == '.') lines[i][currentPosition.second] = '|';
          }
        }
      }
     
      for (auto &line: lines)
        std::cout << line << "\n";
      std::cout << "\n";
      
      lines.clear();
    }
  }
  
  return 0;
}
