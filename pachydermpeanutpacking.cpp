#include <iostream>
#include <vector>

std::string get_peanut_status(
    const double x, const double y,
    const std::vector<std::pair<double, double>>& start_position,
    const std::vector<std::pair<double, double>>& end_position,
    const std::vector<std::string>& type
) {
    for (int i = 0; i < type.size(); ++i) {
        if (start_position[i].first > x || start_position[i].second > y) continue;
        if (end_position[i].first < x || end_position[i].second < y) continue;

        return type[i];
    }

    return "floor";
}

int main() {
    std::size_t box_count;
    std::size_t peanut_count;
    std::cin >> box_count;

    bool is_first = true;
    while (box_count != 0) {
        if (is_first) is_first = false;
        else std::cout << '\n';

        std::vector<std::pair<double, double>> start_position{box_count};
        std::vector<std::pair<double, double>> end_position{box_count};
        std::vector<std::string> type{box_count};

        for (int i = 0; i < box_count; ++i) {
            double x_start;
            double y_start;
            std::cin >> x_start >> y_start;
            start_position[i] = {x_start, y_start};

            double x_end;
            double y_end;
            std::cin >> x_end >> y_end;
            end_position[i] = {x_end, y_end};

            std::cin >> type[i];
        }

        std::cin >> peanut_count;
        for (int i = 0; i < peanut_count; ++i) {
            double x;
            double y;
            std::cin >> x >> y;

            std::string size;
            std::cin >> size;

            std::string status = get_peanut_status(x, y, start_position, end_position, type);
            if (status == size) std::cout << size << " correct\n";
            else std::cout << size << ' ' << status << '\n';
        }

        std::cin >> box_count;
    }

    return 0;
}
