#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t, m;
    std::cin >> n >> t >> m;
    std::cout << n * t * m;

    return 0;
}
