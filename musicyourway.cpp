#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& str) {
    std::stringstream stream{str};
    std::vector<std::string> result;

    while (stream) {
        std::string token;
        stream >> token;
        result.push_back(token);
    }

    return result;
}

std::string combine(const std::vector<std::string>& tokens) {
    std::stringstream stream;
    bool is_first = true;
    for (const auto& token : tokens) {
        if (is_first) is_first = false;
        else stream << ' ';
        stream << token;
    }
    return stream.str();
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> attributes = split(line);

    int song_count;
    std::cin >> song_count;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<std::vector<std::string>> songs;
    for (int i = 0; i < song_count; ++i) {
        std::getline(std::cin, line);
        songs.push_back(split(line));
    }

    int command_count;
    std::cin >> command_count;

    bool is_first = true;
    for (int i = 0; i < command_count; ++i) {
        std::string attribute;
        std::cin >> attribute;

        int attribute_index = -1;
        for (int j = 0; j < attributes.size(); ++j) {
            if (attributes[j] == attribute) {
                attribute_index = j;
                break;
            }
        }

        std::stable_sort(
            songs.begin(), songs.end(), [&](const auto& x, const auto& y) {
                return x[attribute_index] < y[attribute_index];
            }
        );

        if (is_first) is_first = false;
        else std::cout << '\n';

        std::cout << combine(attributes) << '\n';
        for (const auto& song : songs)
            std::cout << combine(song) << '\n';
    }

    return 0;
}
