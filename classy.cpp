#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <vector>

std::array<int, 10> parse_class_descriptor(const std::string& class_descriptor) {
    std::stringstream stream(class_descriptor);
    std::array<int, 10> result{};
    std::string value;

    int i = 0;
    while (std::getline(stream, value, '-')) {
        if (value == "upper") result[i++] = 1;
        else if (value == "lower") result[i++] = -1;
        else ++i;
    }

    std::rotate(result.begin(), result.begin() + i, result.end());

    return result;
}

int main() {
    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int people_count;
        std::cin >> people_count;

        std::vector<std::pair<std::string, std::array<int, 10>>> people;
        for (int j = 0; j < people_count; ++j) {
            std::string person;
            std::cin >> person;
            person.pop_back();

            std::string class_descriptor;
            std::cin >> class_descriptor;

            people.emplace_back(person, parse_class_descriptor(class_descriptor));

            std::string dummy;
            std::cin >> dummy;
        }

        std::sort(
            people.begin(), people.end(), [](const auto& x, const auto& y) {
                for (int k = 9; k >= 0; --k) {
                    if (x.second[k] > y.second[k]) return true;
                    if (x.second[k] < y.second[k]) return false;
                }

                return x.first < y.first;
            }
        );

        for (const auto& [person, _] : people)
            std::cout << person << '\n';

        std::cout << "==============================\n";
    }

    return 0;
}
