#include <bits/stdc++.h>

int main() {
  int size, action;
  std::cin >> size >> action;
  
  unsigned int array[size];
  for (int i = 0; i < size; i++)
    std::cin >> array[i];
  
  if (action == 1) std::cout << "7";
  else if (action == 2) {
    if (array[0] > array[1]) std::cout << "Bigger";
    else if (array[0] == array[1]) std::cout << "Equal";
    else std::cout << "Smaller";
  } else if (action == 3) {
    int a = array[0], b = array[1], c = array[2];
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
    std::cout << b;
  } else if (action == 4) {
    unsigned long long result = 0;
    for (int i = 0; i < size; i++)
      result += array[i];
    std::cout << result;
  } else if (action == 5) {
    unsigned long long result = 0;
    for (int i = 0; i < size; i++)
      if (array[i] % 2 == 0) result += array[i];
    std::cout << result;
  } else if (action == 6) {
    std::string result;
    for (int i = 0; i < size; i++)
      result += 'a' + (array[i] % 26);
    std::cout << result;
  } else if (action == 7) {
    bool visited[size];
    std::fill(visited, visited + size, false);
    int i = 0;
    while (true) {
      i = array[i];
      if (i >= size) {
        std::cout << "Out";
        break;
      } else if (i == size - 1) {
        std::cout << "Done";
        break;
      } else if (visited[i]) {
        std::cout << "Cyclic";
        break;
      }
      visited[i] = true;
    }
  }
  return 0;
}
