#include <array>
#include <iostream>
#include <stack>
#include <vector>

char and_operator(const char a, const char b) {
    if (a == 'T' && b == 'T') return 'T';
    return 'F';
}

char or_operator(const char a, const char b) {
    if (a == 'F' && b == 'F') return 'F';
    return 'T';
}

char not_operator(const char c) {
    if (c == 'T') return 'F';
    return 'T';
}

int main() {
    int n;
    std::cin >> n;

    std::array<char, 26> inputs{};
    for (int i = 0; i < n; ++i)
        std::cin >> inputs[i];

    std::vector<char> tokens;
    char chr;
    std::cin >> chr;
    while (std::cin) {
        if (std::isalpha(chr) != 0)
            tokens.push_back(inputs[chr - 'A']);
        else tokens.push_back(chr);

        std::cin >> chr;
    }

    std::stack<char> values;
    for (const char token : tokens) {
        if (token == 'T' || token == 'F') {
            values.push(token);
            continue;
        }

        if (token == '*') {
            const char a = values.top();
            values.pop();
            const char b = values.top();
            values.pop();

            values.push(and_operator(a, b));
        } else if (token == '+') {
            const char a = values.top();
            values.pop();
            const char b = values.top();
            values.pop();

            values.push(or_operator(a, b));
        } else if (token == '-') {
            const char c = values.top();
            values.pop();

            values.push(not_operator(c));
        }
    }

    std::cout << values.top();

    return 0;
}
