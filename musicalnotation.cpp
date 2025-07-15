#include <array>
#include <iostream>

int note_to_index(const char note) {
    if ('A' <= note && note <= 'G')
        return 6 - (note - 'A');
    return 13 - (note - 'a');
}

void append(std::array<std::string, 14>& lines, const int note_index) {
    static const std::array grid = {
        ' ',
        '-',
        ' ',
        '-',
        ' ',
        '-',
        ' ',
        '-',
        ' ',
        '-',
        ' ',
        ' ',
        ' ',
        '-'
    };

    for (int i = 0; i < 14; ++i) {
        if (i == note_index) lines[i] += '*';
        else lines[i] += grid[i];
    }
}

int main() {
    int note_count;
    std::cin >> note_count;

    std::array<std::string, 14> lines = {
        "G: ",
        "F: ",
        "E: ",
        "D: ",
        "C: ",
        "B: ",
        "A: ",
        "g: ",
        "f: ",
        "e: ",
        "d: ",
        "c: ",
        "b: ",
        "a: "
    };

    for (int i = 0; i < note_count; ++i) {
        std::string note;
        std::cin >> note;

        if (note.length() == 1)
            append(lines, note_to_index(note[0]));
        else
            for (int j = 0; j < std::stoi(note.substr(1)); ++j)
                append(lines, note_to_index(note[0]));
        if (i != note_count - 1) append(lines, -1);
    }

    for (const auto& line : lines)
        std::cout << line << '\n';

    return 0;
}
