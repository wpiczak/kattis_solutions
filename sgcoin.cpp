#include <iostream>

long long hash(const long long previous_hash, const std::string& transaction, const long long token) {
    long long result = previous_hash;
    for (int i = 0; i < transaction.length(); i++)
        result = (result * 31 + transaction[i]) % 1'000'000'007;
    return (result * 7 + token) % 1'000'000'007;
}

long long partial_hash(const long long previous_hash, const std::string& transaction) {
    long long result = previous_hash;
    for (int i = 0; i < transaction.length(); i++)
        result = (result * 31 + transaction[i]) % 1'000'000'007;
    return (result * 7) % 1'000'000'007;
}

long long token(const long long previous_hash, const std::string& transaction) {
    const long long value = partial_hash(previous_hash, transaction);
    const long long n = value / 10'000'000;
    const long long token = 10'000'000 * (n + 1) - value;

    if (value + token == 1'000'000'007)
        return token + 10'000'000;
    return token;
}

int main() {
    long long previous_hash;
    std::cin >> previous_hash;

    const std::string first_transaction = "my-little-pony";
    const long long first_token = token(previous_hash, first_transaction);

    previous_hash = hash(previous_hash, first_transaction, first_token);

    const std::string second_transaction = "friendship-is-magic";
    const long long second_token = token(previous_hash, second_transaction);

    std::cout << first_transaction << ' ' << first_token << '\n';
    std::cout << second_transaction << ' ' << second_token;

    return 0;
}
