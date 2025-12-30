#include <array>
#include <iostream>

std::pair<bool, int> parse(const int start, const std::string& formula, const std::array<bool, 5>& parameters) {
    if (const int index = formula[start] - 'p'; index >= 0 && index < 5)
        return {parameters[index], start + 1};

    if (formula[start] == 'N') {
        auto [result, end] = parse(start + 1, formula, parameters);
        return {!result, end};
    }

    auto [first_result, first_end] = parse(start + 1, formula, parameters);
    auto [second_result, second_end] = parse(first_end, formula, parameters);

    bool result;
    if (formula[start] == 'K') result = first_result && second_result;
    else if (formula[start] == 'A') result = first_result || second_result;
    else if (formula[start] == 'C') result = !first_result || second_result;
    else if (formula[start] == 'E') result = first_result == second_result;

    return {result, second_end};
}

bool parse(const std::string& formula, const bool p, const bool q, const bool r, const bool s, const bool t) {
    return parse(0, formula, {p, q, r, s, t}).first;
}

int main() {
    std::string formula;
    std::cin >> formula;

    while (std::cin) {
        if (formula == "0") break;

        bool is_tautology = true;
        for (int i = 0; i < 32; ++i) {
            is_tautology = parse(formula, i & 1, i & 2, i & 4, i & 8, i & 16);
            if (!is_tautology) break;
        }

        if (is_tautology) std::cout << "tautology\n";
        else std::cout << "not\n";

        std::cin >> formula;
    }

    return 0;
}
