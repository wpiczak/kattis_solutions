#include <iomanip>
#include <iostream>

int main() {
    int event_count;
    int speedup_rate;
    int duration;
    std::cin >> event_count >> speedup_rate >> duration;

    int start = 0;
    double result = 0;
    for (int i = 0; i < event_count; ++i) {
        int end;
        std::cin >> end;

        result += (end - start) * (1.0 + 0.01 * speedup_rate * i);
        start = end;
    }

    result += (duration - start) * (1.0 + 0.01 * speedup_rate * event_count);

    std::cout << std::setprecision(9) << result << '\n';

    return 0;
}
