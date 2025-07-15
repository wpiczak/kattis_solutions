#include <iostream>
#include <sstream>
#include <cmath>

int main() {
    double nutrientCalories[] = {9, 4, 4, 4, 7};

    double totalCalories = 0;
    double totalFatCalories = 0;

    std::string line;
    getline(std::cin, line);
    bool isLastLine = true;
    while (std::cin) {
        if (line == "-") {
            if (isLastLine) break;
            std::cout << std::round(totalFatCalories / totalCalories * 100) << "%\n";
            totalCalories = 0;
            totalFatCalories = 0;
            isLastLine = true;
        } else {
            isLastLine = false;
            std::stringstream stream(line);

            double calories = 0;
            double percents = 0;
            double fatPercent = 0;
            double fatCalories = 0;
            for (int i = 0; i < 5; i++) {
                std::string nutrient;
                stream >> nutrient;

                double inputValue = std::stod(nutrient.substr(0, nutrient.length() - 1));
                char inputType = nutrient[nutrient.length() - 1];
                
                if (inputType == 'g') {
                    double currentCalories = nutrientCalories[i] * inputValue;
                    calories += currentCalories;
                    if (i == 0) fatCalories = currentCalories;
                } else if (nutrient[nutrient.length() - 1] == 'C') {
                    double currentCalories = inputValue;
                    calories += currentCalories;
                    if (i == 0) fatCalories = currentCalories;
                } else {
                    double currentPercent = inputValue;
                    percents += currentPercent;
                    if (i == 0) fatPercent = currentPercent;
                }
            }

            calories = calories / (1 - percents / 100);
            if (fatCalories == 0) fatCalories = fatPercent * calories / 100;

            totalCalories += calories;
            totalFatCalories += fatCalories;
        }
        getline(std::cin, line);
    }

    return 0;
}
