#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;
    if (a < b)
        std::cout << a << " " << b;
    else std::cout << b << " " << a;

    return 0;
}
