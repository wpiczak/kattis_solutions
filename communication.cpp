#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input_size;
    std::cin >> input_size;

    while (input_size--) {
        int encoded_byte;
        std::cin >> encoded_byte;

        for (int byte = 0; byte < 256; ++byte) {
            if ((byte ^ (255 & (byte << 1))) == encoded_byte) {
                std::cout << byte << ' ';
                break;
            }
        }
    }

    return 0;
}
