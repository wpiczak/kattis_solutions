#include <array>
#include <iostream>

const std::array<std::string, 7>& convert(const char symbol) {
    static std::array<std::array<std::string, 7>, 10> digits = {
        {
            {
                "+---+",
                "|   |",
                "|   |",
                "+   +",
                "|   |",
                "|   |",
                "+---+"
            },
            {
                "    +",
                "    |",
                "    |",
                "    +",
                "    |",
                "    |",
                "    +"
            },
            {
                "+---+",
                "    |",
                "    |",
                "+---+",
                "|    ",
                "|    ",
                "+---+"
            },
            {
                "+---+",
                "    |",
                "    |",
                "+---+",
                "    |",
                "    |",
                "+---+"
            },
            {
                "+   +",
                "|   |",
                "|   |",
                "+---+",
                "    |",
                "    |",
                "    +"
            },
            {
                "+---+",
                "|    ",
                "|    ",
                "+---+",
                "    |",
                "    |",
                "+---+"
            },
            {
                "+---+",
                "|    ",
                "|    ",
                "+---+",
                "|   |",
                "|   |",
                "+---+"
            },
            {
                "+---+",
                "    |",
                "    |",
                "    +",
                "    |",
                "    |",
                "    +"
            },
            {
                "+---+",
                "|   |",
                "|   |",
                "+---+",
                "|   |",
                "|   |",
                "+---+"
            },
            {
                "+---+",
                "|   |",
                "|   |",
                "+---+",
                "    |",
                "    |",
                "+---+"
            }
        }
    };

    static std::array<std::string, 7> colon = {
        " ",
        " ",
        "o",
        " ",
        "o",
        " ",
        " "
    };

    if (symbol >= '0' && symbol <= '9')
        return digits[symbol - '0'];
    return colon;
}

void append(std::array<std::string, 7>& lines, const std::array<std::string, 7>& symbol) {
    for (int i = 0; i < 7; ++i) {
        if (!lines[i].empty()) lines[i] += "  ";
        lines[i] += symbol[i];
    }
}

int main() {
    std::string input;
    std::cin >> input;

    while (input != "end") {
        std::array<std::string, 7> lines{};

        for (const char& symbol : input)
            append(lines, convert(symbol));

        for (int i = 0; i < 7; ++i)
            std::cout << lines[i] << '\n';
        std::cout << "\n\n";

        std::cin >> input;
    }

    std::cout << "end" << std::endl;

    return 0;
}
