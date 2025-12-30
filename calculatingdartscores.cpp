#include <iostream>

void print_throw(const int i, const int a) {
    if (i == 1) std::cout << "single";
    else if (i == 2) std::cout << "double";
    else if (i == 3) std::cout << "triple";
    else return;

    std::cout << ' ' << a << '\n';
}

bool print_solution(const int n) {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            for (int k = 0; k <= 3; ++k) {
                for (int a = 1; a <= 20; ++a) {
                    for (int b = 1; b <= 20; ++b) {
                        for (int c = 1; c <= 20; ++c) {
                            if (i * a + j * b + k * c == n) {
                                print_throw(i, a);
                                print_throw(j, b);
                                print_throw(k, c);
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;

    if (!print_solution(n))
        std::cout << "impossible\n";

    return 0;
}
