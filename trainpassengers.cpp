#include <iostream>

bool is_possible() {
    long long capacity;
    long long station_count;
    std::cin >> capacity >> station_count;

    long long passenger_count = 0;
    for (int i = 0; i < station_count; ++i) {
        long long exit_count;
        long long entry_count;
        long long stay_count;
        std::cin >> exit_count >> entry_count >> stay_count;

        passenger_count = passenger_count - exit_count + entry_count;
        if (i != station_count - 1) {
            if (passenger_count < 0 || passenger_count > capacity) return false;
            if (passenger_count != capacity && stay_count > 0) return false;
        } else if (passenger_count != 0 || entry_count != 0 || stay_count != 0) return false;
    }

    return true;
}

int main() {
    std::cout << (is_possible() ? "possible" : "impossible");

    return 0;
}
