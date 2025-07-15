#include <iostream>

int main() {
    std::string sequence;
    std::cin >> sequence;

    long long inversion_count = 0;
    long long total_one_count = 0;
    long long sequence_count = 1;
    for (const char& bit : sequence) {
        if (bit == '1')
            total_one_count = (total_one_count + sequence_count) % 1'000'000'007;
        else if (bit == '0')
            inversion_count = (inversion_count + total_one_count) % 1'000'000'007;
        else {
            inversion_count = (2 * inversion_count + total_one_count) % 1'000'000'007;
            total_one_count = (2 * total_one_count + sequence_count) % 1'000'000'007;
            sequence_count = 2 * sequence_count % 1'000'000'007;
        }
    }

    std::cout << inversion_count;

    return 0;
}
