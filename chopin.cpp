#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> notes = {
        {"A#", "Bb"}, {"Bb", "A#"},
        {"C#", "Db"}, {"Db", "C#"},
        {"D#", "Eb"}, {"Eb", "D#"},
        {"F#", "Gb"}, {"Gb", "F#"},
        {"G#", "Ab"}, {"Ab", "G#"},
    };

    std::string note;
    std::string tonality;
    std::cin >> note >> tonality;

    int case_index = 0;
    while (std::cin) {
        if (auto it = notes.find(note); it != notes.end())
            std::cout << "Case " << ++case_index << ": " << it->second << " " << tonality << '\n';
        else std::cout << "Case " << ++case_index << ": UNIQUE\n";

        std::cin >> note >> tonality;
    }

    return 0;
}
