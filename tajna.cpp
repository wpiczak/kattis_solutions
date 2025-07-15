#include <iostream>

unsigned int sqrt(const unsigned int n) {
    unsigned short shift = 2;
    while (n >> shift) shift += 2;

    unsigned int result = 0;
    while (shift > 0) {
        shift -= 2;
        result = result << 1;
        result = result ^ 1;
        if (result * result > n >> shift)
            result = result ^ 1;
    }

    return result;
}

int get_row_count(const int n) {
    for (int i = static_cast<int>(sqrt(n)); i > 1; --i)
        if (n % i == 0) return i;
    return 1;
}

int main() {
    std::string message;
    std::getline(std::cin, message);

    const int length = static_cast<int>(message.length());
    const int row_count = get_row_count(length);
    const int column_count = length / row_count;

    for (int i = 0; i < row_count; ++i)
        for (int j = 0; j < column_count; ++j)
            std::cout << message[j * row_count + i];

    return 0;
}
