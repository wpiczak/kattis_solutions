#include <iostream>

int main() {
    std::string line;
    std::getline(std::cin, line);
    while (!line.empty() && std::cin) {
        const std::size_t end = line.rfind(' ') + 1;
        const std::size_t start = line.rfind(' ', end - 2) + 1;
        std::string end_time = line.substr(end);
        std::string start_time = line.substr(start, end - start - 1);

        const std::size_t end_time_divisor = end_time.find(':');
        const std::size_t start_time_divisor = start_time.find(':');
        const int end_hour = std::stoi(end_time.substr(0, end_time_divisor));
        const int end_minute = std::stoi(end_time.substr(end_time_divisor + 1));
        const int start_hour = std::stoi(start_time.substr(0, start_time_divisor));
        const int start_minute = std::stoi(start_time.substr(start_time_divisor + 1));

        const int duration = (end_hour * 60 + end_minute) - (start_hour * 60 + start_minute);
        const int duration_minutes = duration % 60;
        const int duration_hours = duration / 60;

        std::cout << line.substr(0, start) << duration_hours << " hours " << duration_minutes << " minutes\n";

        std::getline(std::cin, line);
    }

    return 0;
}
