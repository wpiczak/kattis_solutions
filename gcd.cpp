#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    while (a > 0) {
        if (a < b) std::swap(a, b);
        a = a % b;
    }

    std::cout << b << std::endl;

    return 0;
}
