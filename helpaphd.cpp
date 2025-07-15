#include <bits/stdc++.h>

int main() {
    int caseCount;
    std::cin >> caseCount;
    std::cin.ignore();
    while (caseCount--) {
        std::string line;
        std::getline(std::cin, line);
        if (line == "P=NP") {
            std::cout << "skipped" << "\n";
        } else {
            int pos = line.find('+');
            int a = std::stoi(line.substr(0, pos));
            int b = std::stoi(line.substr(pos + 1));
            std::cout << a + b << "\n";
        }
    }
    return 0;
}
