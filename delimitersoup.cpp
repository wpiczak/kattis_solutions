#include <iostream>
#include <limits>
#include <stack>

bool match(const char a, const char b) {
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
}

int main() {
    int length;
    std::cin >> length;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string program;
    std::getline(std::cin, program);

    const std::string opening_brackets = "([{";
    const std::string closing_brackets = ")]}";

    bool error_occurred = false;
    std::stack<char> brackets;
    for (int i = 0; i < length; ++i) {
        if (opening_brackets.contains(program[i]))
            brackets.push(program[i]);
        if (closing_brackets.contains(program[i])) {
            if (brackets.empty() || !match(brackets.top(), program[i])) {
                std::cout << program[i] << ' ' << i;
                error_occurred = true;
                break;
            }

            brackets.pop();
        }
    }

    if (!error_occurred) std::cout << "ok so far";

    return 0;
}
