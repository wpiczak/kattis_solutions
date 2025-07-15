#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cout << i << " Abracadabra\n";

    return 0;
}
