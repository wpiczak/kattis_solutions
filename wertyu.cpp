#include <iostream>
#include <sstream>
#include <unordered_map>

int main() {
    std::unordered_map<char, char> table = {
        {'1', '`'},
        {'2', '1'},
        {'3', '2'},
        {'4', '3'},
        {'5', '4'},
        {'6', '5'},
        {'7', '6'},
        {'8', '7'},
        {'9', '8'},
        {'0', '9'},
        {'-', '0'},
        {'=', '-'},
        {'Q', '='},
        {'W', 'Q'},
        {'E', 'W'},
        {'R', 'E'},
        {'T', 'R'},
        {'Y', 'T'},
        {'U', 'Y'},
        {'I', 'U'},
        {'O', 'I'},
        {'P', 'O'},
        {'[', 'P'},
        {']', '['},
        {'\\', ']'},
        {'A', '\\'},
        {'S', 'A'},
        {'D', 'S'},
        {'F', 'D'},
        {'G', 'F'},
        {'H', 'G'},
        {'J', 'H'},
        {'K', 'J'},
        {'L', 'K'},
        {';', 'L'},
        {'\'', ';'},
        {'Z', '\''},
        {'X', 'Z'},
        {'C', 'X'},
        {'V', 'C'},
        {'B', 'V'},
        {'N', 'B'},
        {'M', 'N'},
        {',', 'M'},
        {'.', ','},
        {'/', '.'}
    };

    std::string line;
    while (std::cin) {
        std::getline(std::cin, line);
        std::ostringstream stream;
        for (const char& key: line) {
            if (key == ' ') stream << ' ';
            else stream << table[key];
        }
        std::cout << stream.str() << '\n';
    }

    return 0;
}
