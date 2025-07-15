#include <array>
#include <iostream>

static const std::array<std::array<std::string, 7>, 11> symbols = {
    {
        {
            "xxxxx",
            "x...x",
            "x...x",
            "x...x",
            "x...x",
            "x...x",
            "xxxxx"
        },
        {
            "....x",
            "....x",
            "....x",
            "....x",
            "....x",
            "....x",
            "....x",
        },
        {
            "xxxxx",
            "....x",
            "....x",
            "xxxxx",
            "x....",
            "x....",
            "xxxxx",
        },
        {
            "xxxxx",
            "....x",
            "....x",
            "xxxxx",
            "....x",
            "....x",
            "xxxxx",
        },
        {
            "x...x",
            "x...x",
            "x...x",
            "xxxxx",
            "....x",
            "....x",
            "....x",
        },
        {
            "xxxxx",
            "x....",
            "x....",
            "xxxxx",
            "....x",
            "....x",
            "xxxxx",
        },
        {
            "xxxxx",
            "x....",
            "x....",
            "xxxxx",
            "x...x",
            "x...x",
            "xxxxx",
        },
        {
            "xxxxx",
            "....x",
            "....x",
            "....x",
            "....x",
            "....x",
            "....x",
        },
        {
            "xxxxx",
            "x...x",
            "x...x",
            "xxxxx",
            "x...x",
            "x...x",
            "xxxxx",
        },
        {
            "xxxxx",
            "x...x",
            "x...x",
            "xxxxx",
            "....x",
            "....x",
            "xxxxx",
        },
        {
            ".....",
            "..x..",
            "..x..",
            "xxxxx",
            "..x..",
            "..x..",
            ".....",
        }
    }
};

int decode_symbol(const std::array<std::string, 7>& lines, const int start) {
    for (int i = 0; i < 11; ++i) {
        bool are_equal = true;
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (symbols[i][j][k] != lines[j][start + k]) {
                    are_equal = false;
                    break;
                }
            }
            if (!are_equal) break;
        }
        if (are_equal) return i;
    }

    return -1;
}

int decode_sum(const std::array<std::string, 7>& lines) {
    int a = 0;
    int b = 0;
    int* r = &a;

    const int symbol_count = (static_cast<int>(lines[0].length()) + 1) / 6;

    for (int i = 0; i < symbol_count; ++i) {
        if (const int symbol_id = decode_symbol(lines, 6 * i); symbol_id == 10) r = &b;
        else *r = *r * 10 + symbol_id;
    }

    return a + b;
}

void print(const std::string& number) {
    for (int i = 0; i < 7; ++i) {
        bool is_first = true;
        for (const char& digit : number) {
            if (is_first) is_first = false;
            else std::cout << '.';
            std::cout << symbols[digit - '0'][i];
        }

        std::cout << '\n';
    }
}

int main() {
    std::array<std::string, 7> lines;
    for (int i = 0; i < 7; ++i)
        std::getline(std::cin, lines[i]);

    print(std::to_string(decode_sum(lines)));

    return 0;
}
