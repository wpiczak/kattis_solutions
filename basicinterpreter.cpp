#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

std::array<int, 26> variables{};

std::vector<std::pair<int, std::string>> load() {
    std::vector<std::pair<int, std::string>> lines;

    int label;
    while (std::cin >> label) {
        std::cin.get();
        std::string line;
        std::getline(std::cin, line);

        lines.emplace_back(label, line);
    }

    std::sort(lines.begin(), lines.end());

    return lines;
}

std::vector<std::string> tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::istringstream stream{expression};

    std::string token;
    while (stream >> token) tokens.push_back(token);

    return tokens;
}

int evaluate(const std::string& literal) {
    if (literal.length() == 1 && literal[0] >= 'A' && literal[1] <= 'Z')
        return variables[literal[0] - 'A'];
    return std::stoi(literal);
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const auto lines = load();

    std::unordered_map<int, std::size_t> label_to_index;
    std::unordered_map<std::size_t, int> index_to_label;

    for (int i = 0; i < lines.size(); ++i) {
        label_to_index[lines[i].first] = i;
        index_to_label[i] = lines[i].first;
    }

    std::size_t current_index = 0;
    while (current_index < lines.size()) {
        const std::string statement = lines[current_index].second;

        std::istringstream stream{statement};
        std::string keyword;
        stream >> keyword;

        if (keyword == "LET") {
            char name;
            stream >> name;

            stream.ignore(3);

            std::string expression;
            std::getline(stream, expression);
            std::vector<std::string> tokens = tokenize(expression);

            if (tokens.size() == 1) variables[name - 'A'] = evaluate(tokens[0]);
            else if (tokens.size() == 3) {
                if (tokens[1] == "+")
                    variables[name - 'A'] = evaluate(tokens[0]) + evaluate(tokens[2]);
                else if (tokens[1] == "-")
                    variables[name - 'A'] = evaluate(tokens[0]) - evaluate(tokens[2]);
                else if (tokens[1] == "*")
                    variables[name - 'A'] = evaluate(tokens[0]) * evaluate(tokens[2]);
                else if (tokens[1] == "/")
                    variables[name - 'A'] = evaluate(tokens[0]) / evaluate(tokens[2]);
            }
        } else if (keyword == "IF") {
            stream.ignore(1);

            std::string expression;
            std::getline(stream, expression);
            std::vector<std::string> tokens = tokenize(expression);

            bool result = false;

            if (tokens[1] == "=")
                result = evaluate(tokens[0]) == evaluate(tokens[2]);
            else if (tokens[1] == ">")
                result = evaluate(tokens[0]) > evaluate(tokens[2]);
            else if (tokens[1] == "<")
                result = evaluate(tokens[0]) < evaluate(tokens[2]);
            else if (tokens[1] == "<>")
                result = evaluate(tokens[0]) != evaluate(tokens[2]);
            else if (tokens[1] == ">=")
                result = evaluate(tokens[0]) >= evaluate(tokens[2]);
            else if (tokens[1] == "<=")
                result = evaluate(tokens[0]) <= evaluate(tokens[2]);

            if (result) {
                int next_label = std::stoi(tokens[5]);
                current_index = label_to_index[next_label] - 1;
            }
        } else if (keyword == "PRINT" || keyword == "PRINTLN") {
            stream.ignore(1);

            std::string print_statement;
            std::getline(stream, print_statement);

            if (print_statement.length() == 1)
                std::cout << variables[print_statement[0] - 'A'];
            else std::cout << print_statement.substr(1, print_statement.size() - 2);

            if (keyword == "PRINTLN") std::cout << '\n';
        }

        ++current_index;
    }

    return 0;
}
