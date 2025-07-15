#include <iostream>
#include <limits>

int main() {
    int guess;
    int upper_bound = 10;
    int lower_bound = 1;
    while (std::cin >> guess) {
        if (guess == 0) break;

        std::string response;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, response, '\n');

        if (response == "too high" && guess <= upper_bound)
            upper_bound = guess - 1;
        else if (response == "too low" && guess >= lower_bound)
            lower_bound = guess + 1;
        else if (response == "right on") {
            if (lower_bound <= guess && guess <= upper_bound)
                std::cout << "Stan may be honest\n";
            else std::cout << "Stan is dishonest\n";
            upper_bound = 10;
            lower_bound = 1;
        }
    }
}
