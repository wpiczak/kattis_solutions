#include <array>
#include <iostream>

int main() {
    std::array<std::string, 26> translation_table = {
        "@",
        "8",
        "(",
        "|)",
        "3",
        "#",
        "6",
        "[-]",
        "|",
        "_|",
        "|<",
        "1",
        "[]\\/[]",
        "[]\\[]",
        "0",
        "|D",
        "(,)",
        "|Z",
        "$",
        "']['",
        "|_|",
        "\\/",
        "\\/\\/",
        "}{",
        "`/",
        "2"
    };

    std::string message;
    std::getline(std::cin, message);

    for (const auto& chr : message) {
        if (std::tolower(chr) >= 'a' && std::tolower(chr) <= 'z')
            std::cout << translation_table[std::tolower(chr) - 'a'];
        else std::cout << chr;
    }

    return 0;
}
