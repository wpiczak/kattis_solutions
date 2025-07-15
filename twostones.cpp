#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    if (n % 2 == 0)
        std::cout << "Bob";
    else std::cout << "Alice";
    
    return 0;
}