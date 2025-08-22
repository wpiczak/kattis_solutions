#include <iostream>
#include <unordered_map>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_map<std::string, int> name_to_value;
    std::unordered_map<int, std::string> value_to_name;

    std::string command;
    while (std::cin >> command) {
        if (command == "def") {
            std::string name;
            int value;
            std::cin >> name >> value;

            auto it = name_to_value.find(name);
            if (it != name_to_value.end())
                value_to_name.erase(it->second);

            name_to_value[name] = value;
            value_to_name[value] = name;
        } else if (command == "calc") {
            bool is_unknown = false;
            std::string calculation;

            int result = 0;
            char operation = '+';
            while (operation != '=') {
                std::string name;
                std::cin >> name;

                auto it = name_to_value.find(name);
                if (it == name_to_value.end()) is_unknown = true;
                else {
                    if (operation == '+') result += it->second;
                    if (operation == '-') result -= it->second;
                }

                std::cin >> operation;
                calculation += name + ' ' + operation + ' ';
            }

            std::cout << calculation;
            if (is_unknown) std::cout << "unknown\n";
            else {
                auto it = value_to_name.find(result);
                if (it == value_to_name.end()) std::cout << "unknown\n";
                else std::cout << it->second << '\n';
            }
        } else if (command == "clear") {
            name_to_value.clear();
            value_to_name.clear();
        }
    }

    return 0;
}
