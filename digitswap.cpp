#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char a, b;
    std::cin >> a >> b;
    std::cout << b << a;

    return 0;
}
