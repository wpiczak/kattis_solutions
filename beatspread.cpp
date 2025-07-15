#include <iostream>


int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int sum;
        int difference;
        std::cin >> sum >> difference;

        if ((sum + difference) % 2 || sum - (sum + difference) / 2 < 0)
            std::cout << "impossible\n";
        else std::cout << (sum + difference) / 2 << ' ' << sum - (sum + difference) / 2 << '\n';
    }

    return 0;
}
