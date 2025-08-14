#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

template<typename Iterator>
void print(const Iterator& start, const Iterator& end) {
    std::cout << '[';

    bool is_first = true;
    for (auto it = start; it != end; ++it) {
        if (!is_first) std::cout << ',';
        else is_first = false;
        std::cout << *it;
    }

    std::cout << ']' << '\n';
}

void print_list(const std::deque<int>& list, const bool reversed) {
    if (reversed) print(list.rbegin(), list.rend());
    else print(list.begin(), list.end());
}

std::deque<int> decode_list(const std::string& list) {
    std::deque<int> result;

    if (list.length() == 2)
        return result;

    std::istringstream stream(list.substr(1, list.length() - 2));
    char comma;
    int value;
    while (stream) {
        stream >> value;
        stream >> comma;
        result.push_back(value);
    }

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        std::string program;
        std::cin >> program;

        int n;
        std::cin >> n;

        std::string encoded_list;
        std::cin >> encoded_list;

        std::deque<int> list = decode_list(encoded_list);
        bool reversed = false;

        bool error_occurred = false;
        for (const char chr : program) {
            if (chr == 'R') reversed = not reversed;
            if (chr == 'D') {
                if (list.empty()) {
                    error_occurred = true;
                    break;
                }

                if (reversed) list.pop_back();
                else list.pop_front();
            }
        }

        if (error_occurred) std::cout << "error\n";
        else print_list(list, reversed);
    }

    return 0;
}
