#include <iostream>
#include <limits>

unsigned int sqrt(const unsigned int n) {
    short shift = 2;
    while (n >> shift) shift += 2;

    unsigned int result = 0;
    while (shift >= 0) {
        result = result << 1;
        result = result ^ 1;
        if (result * result > n >> shift)
            result = result ^ 1;
        shift -= 2;
    }

    return result;
}

int main() {
    int case_count;
    std::cin >> case_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < case_count; ++i) {
        std::string message;
        std::getline(std::cin, message);

        const int n = static_cast<int>(sqrt(message.length()));
        for (int j = n - 1; j >= 0; --j)
            for (int k = 0; k < n; ++k)
                std::cout << message[n * k + j];
        std::cout << '\n';
    }

    return 0;
}
