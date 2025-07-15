#include <bits/stdc++.h>

int main() {
  int restaurantCount;
  std::string line;
  std::getline(std::cin, line);
  restaurantCount = std::stoi(line);

  bool foundValidRestaurant = false;
  for (int i = 0; i < restaurantCount; i++) {
    bool hasPeaSoup = false;
    bool hasPancakes = false;
    int dishCount;
    std::getline(std::cin, line);
    dishCount = std::stoi(line);
    std::string restaurant;
    std::getline(std::cin, restaurant);
    for (int j = 0; j < dishCount; j++) {
      std::string dish;
      std::getline(std::cin, dish);
      if (dish == "pea soup") hasPeaSoup = true;
      if (dish == "pancakes") hasPancakes = true;
    }
    if (hasPeaSoup && hasPancakes) {
      std::cout << restaurant;
      foundValidRestaurant = true;
      break;
    }
  }
  if (!foundValidRestaurant)
    std::cout << "Anywhere is fine I guess";
  
  return 0;
}
