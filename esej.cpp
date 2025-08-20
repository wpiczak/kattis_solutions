#include <iostream>

void print_word(int index) {
    std::cout << 'p';
    while (index > 0) {
        std::cout << static_cast<char>('a' + index % 26);
        index /= 26;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a;
    int b;
    std::cin >> a >> b;

    bool is_first = true;
    for (int i = 0; i < b; ++i) {
        if (is_first) is_first = false;
        else std::cout << ' ';
        print_word(i);
    }

    return 0;
}
