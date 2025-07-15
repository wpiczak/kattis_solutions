#include <cmath>
#include <iostream>
#include <limits>

int main() {
    int case_count;
    std::cin >> case_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < case_count; ++i) {
        std::string message;
        std::getline(std::cin, message);

        const auto n = static_cast<int>(std::ceil(std::sqrt(message.length())));
        message.append(n * n - message.length(), '*');

        for (int j = 0; j < n; ++j)
            for (int k = n - 1; k >= 0; --k)
                if (message[k * n + j] != '*')
                    std::cout << message[k * n + j];

        std::cout << '\n';
    }

    return 0;
}
