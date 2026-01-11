#include <iostream>
#include <set>
#include <stack>
#include <vector>

constexpr unsigned int lsb(const unsigned int n) { return n & -n; }

int main() {
    std::string expression;
    std::cin >> expression;

    std::vector<int> left_parentheses;
    std::vector<int> right_parentheses;

    std::stack<int> indices;
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '(') indices.push(i);
        if (expression[i] == ')') {
            left_parentheses.push_back(indices.top());
            right_parentheses.push_back(i);
            indices.pop();
        }
    }

    std::set<std::string> subexpressions;
    for (unsigned i = 1; i < (1 << left_parentheses.size()); ++i) {
        std::string subexpression = expression;

        unsigned j = i;
        while (j > 0) {
            subexpression[left_parentheses[std::countr_zero(j)]] = ' ';
            subexpression[right_parentheses[std::countr_zero(j)]] = ' ';
            j -= lsb(j);
        }

        std::erase(subexpression, ' ');
        subexpressions.insert(subexpression);
    }

    for (const std::string& subexpression : subexpressions)
        std::cout << subexpression << '\n';

    return 0;
}
