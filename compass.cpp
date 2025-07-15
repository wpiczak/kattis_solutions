#include <iostream>

int main() {
    int n1, n2;
    std::cin >> n1 >> n2;

    if (n1 > n2) {
        if (std::abs(n2 - n1) < std::abs(360 + n2 - n1))
            std::cout << n2 - n1;
        else std::cout << 360 + n2 - n1;
    } else {
        if (std::abs(n2 - n1 - 360) < std::abs(n2 - n1))
            std::cout << n2 - n1 - 360;
        else std::cout << n2 - n1;
    }

    return 0;
}
