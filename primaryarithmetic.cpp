#include <algorithm>
#include <iostream>

int main() {
    std::string x;
    std::string y;
    std::cin >> x >> y;

    while (x != "0" || y != "0") {
        if (x.length() < y.length()) std::swap(x, y);

        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());

        int carry = 0;
        int carry_count = 0;
        for (int i = 0; i < x.size(); ++i) {
            const int a = x[i] - '0';
            const int b = i < y.size() ? y[i] - '0' : 0;
            const int c = a + b + carry;
            if (c > 9) {
                carry = 1;
                ++carry_count;
            } else carry = 0;
        }

        if (carry_count == 0) std::cout << "No carry operation.\n";
        else if (carry_count == 1) std::cout << "1 carry operation.\n";
        else std::cout << carry_count << " carry operations.\n";

        std::cin >> x >> y;
    }

    return 0;
}
