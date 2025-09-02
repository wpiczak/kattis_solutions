#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>

struct car_data {
    int catalog_price;
    int pickup_fee;
    int rental_rate;
};

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    for (int i = 0; i < case_count; ++i) {
        int car_count;
        int event_count;
        std::cin >> car_count >> event_count;

        std::unordered_map<std::string, car_data> data;
        for (int j = 0; j < car_count; ++j) {
            std::string name;
            int catalog_price;
            int pickup_fee;
            int rental_rate;
            std::cin >> name >> catalog_price >> pickup_fee >> rental_rate;
            data[name] = {catalog_price, pickup_fee, rental_rate};
        }

        std::unordered_map<std::string, std::string> car;
        std::map<std::string, int> bill;

        for (int j = 0; j < event_count; ++j) {
            int time;
            std::string spy_name;
            char event_type;
            std::cin >> time >> spy_name >> event_type;

            const auto bill_it = bill.insert({spy_name, 0}).first;

            if (event_type == 'p') {
                std::string car_type;
                std::cin >> car_type;

                if (bill_it->second == -1) continue;

                if (!car.insert({spy_name, car_type}).second) bill_it->second = -1;
                else bill_it->second += data[car_type].pickup_fee;
            } else if (event_type == 'r') {
                int distance;
                std::cin >> distance;

                if (bill_it->second == -1) continue;

                const auto car_it = car.find(spy_name);
                if (car_it == car.end()) bill_it->second = -1;
                else {
                    bill_it->second += data[car_it->second].rental_rate * distance;
                    car.erase(car_it);
                }
            } else if (event_type == 'a') {
                int severity;
                std::cin >> severity;

                if (bill_it->second == -1) continue;

                const auto car_it = car.find(spy_name);
                if (car_it == car.end()) bill_it->second = -1;
                else {
                    double damage = severity * data[car_it->second].catalog_price;
                    damage /= 100;
                    bill_it->second += ceil(damage);
                }
            }
        }

        for (const auto& [spy_name, _] : car)
            bill[spy_name] = -1;

        for (const auto& [spy_name, total] : bill) {
            std::cout << spy_name << ' ';
            if (total == -1) std::cout << "INCONSISTENT\n";
            else std::cout << total << '\n';
        }
    }

    return 0;
}
