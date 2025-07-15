#include <iomanip>
#include <iostream>
#include <sstream>

std::pair<std::string, std::string> parse_input(const std::string& line) {
    if (std::isalpha(line[0])) {
        auto i = line.find(' ');
        while (i != std::string::npos) {
            if (std::isdigit(line[i + 1]))
                return {line.substr(0, i), line.substr(i + 1)};
            i = line.find(' ', i + 1);
        }
        return {line, std::string{}};
    }

    auto i = line.find(' ');
    while (i != std::string::npos) {
        if (std::isalpha(line[i + 1]))
            return {line.substr(i + 1), line.substr(0, i)};
        i = line.find(' ', i + 1);
    }
    return {std::string{}, line};
}

double calculate_average(const std::string& measurements) {
    std::istringstream stream{measurements};

    int count = 0;
    double total = 0;
    while (!stream.eof()) {
        double measurement;
        stream >> measurement;

        total += measurement;
        ++count;
    }

    return total / count;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::cout << std::setprecision(8);
    while (!line.empty() && std::cin) {
        auto [name, measurements] = parse_input(line);
        std::cout << calculate_average(measurements) << ' ' << name << '\n';

        std::getline(std::cin, line);
    }

    return 0;
}
