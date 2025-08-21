#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_set>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::unordered_set<std::string> proven_statements;
    bool correct = true;
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);

        std::istringstream stream(line);
        std::string token;

        bool is_assumption = true;
        while (stream >> token) {
            if (token == "->") {
                is_assumption = false;
                continue;
            }

            if (is_assumption && proven_statements.count(token) == 0) {
                std::cout << i + 1 << '\n';
                correct = false;
                goto loop_end;
            }

            if (!is_assumption) proven_statements.insert(token);
        }
    }

loop_end:
    if (correct) std::cout << "correct";

    return 0;
}
