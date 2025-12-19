#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<int> process(const std::string& line) {
    std::vector<int> result;
    std::istringstream stream{line};

    int token;
    stream >> token;
    while (stream) {
        result.push_back(token);
        stream >> token;
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    while (std::getline(std::cin, line)) {
        const auto input = process(line);
        const int rank = std::ranges::max(input);

        std::vector<int> measure_possibilities(rank);
        for (int i = 0; i < input.size(); ++i) {
            for (int j = i + 1; j < input.size(); ++j) {
                const int distance = std::abs(input[i] - input[j]);
                ++measure_possibilities[distance - 1];
            }
        }

        std::vector<int> missing_distances;
        bool is_ruler = true;
        bool is_perfect = true;
        for (int i = 0; i < rank; ++i) {
            if (measure_possibilities[i] == 0) {
                is_perfect = false;
                missing_distances.push_back(i + 1);
            } else if (measure_possibilities[i] > 1) {
                is_ruler = false;
                break;
            }
        }

        if (!is_ruler) std::cout << "not a ruler\n";
        else if (is_perfect) std::cout << "perfect\n";
        else {
            std::cout << "missing ";
            for (const int distance : missing_distances)
                std::cout << distance << ' ';
            std::cout << '\n';
        }
    }

    return 0;
}
