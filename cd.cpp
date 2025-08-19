#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int m;

    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        std::vector<int> jack(n);
        std::vector<int> jill(m);
        std::vector<int> common;
        common.reserve(std::min(n, m));

        for (int i = 0; i < n; ++i)
            std::cin >> jack[i];

        for (int i = 0; i < m; ++i)
            std::cin >> jill[i];

        std::set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), std::back_inserter(common));

        std::cout << common.size() << '\n';
    }


    return 0;
}
