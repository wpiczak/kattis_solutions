#include <bits/stdc++.h>

int main() {
  int caseCount;
  std::cin >> caseCount;

  for (int caseIndex = 1; caseIndex <= caseCount; caseIndex++) {
    std::string first, second;
    std::cin >> first >> second;
    
    if (first.size() != second.size()) {
      std::cout << "Case " << caseIndex << ": -1\n";
      continue;
    }
    
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    for (int j = 0; j < first.size(); j++) {
      if (first[j] == '0' && second[j] == '0') a++;
      if (first[j] == '0' && second[j] == '1') b++;
      if (first[j] == '1' && second[j] == '0') c++;
      if (first[j] == '1' && second[j] == '1') d++;
      if (first[j] == '?' && second[j] == '0') e++;
      if (first[j] == '?' && second[j] == '1') f++;
    }
    
    int result = (b < c) ? b : c;
    b -= result;
    c -= result;
    
    if (b > 0) result += b + e + f;
    else {
      if (f < c) result = -1;
      else result += c + e + f;
    }
    
    std::cout << "Case " << caseIndex << ": " << result << "\n";
  }
  
  return 0;
}
