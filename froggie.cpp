#include <iostream>
#include <vector>

class lane {
public:
    lane() = default;

    lane(const int first_car_position, const int car_interval_length, const int car_speed):
        first_car_position_(first_car_position),
        car_interval_length_(car_interval_length),
        car_speed_(car_speed) {}

    [[nodiscard]] bool is_safe_position(const int position) const {
        const int distance_from_upcoming_car = (position - first_car_position_ + car_interval_length_) %
            car_interval_length_;
        if (distance_from_upcoming_car > car_speed_) return true;
        if (distance_from_upcoming_car == 0 && 0 < car_speed_ && car_speed_ < car_interval_length_) return true;
        return false;
    }

    void advance() {
        first_car_position_ += car_speed_;
        first_car_position_ %= car_interval_length_;
    }

private:
    int first_car_position_ = 0;
    int car_interval_length_ = 0;
    int car_speed_ = 0;
};

int to_lane_position(const int position, const int lane_index, const int lane_count, const int lane_width) {
    if (lane_count - lane_index & 1) return position;
    return lane_width - position - 1;
}

int main() {
    int lane_count;
    int lane_width;
    std::cin >> lane_count >> lane_width;

    std::vector<lane> lanes{static_cast<std::size_t>(lane_count)};
    for (int i = lane_count - 1; i >= 0; --i) {
        int first_car_position;
        int car_interval_length;
        int car_speed;
        std::cin >> first_car_position >> car_interval_length >> car_speed;

        lanes[i] = lane{first_car_position, car_interval_length, car_speed};
    }

    int froggie_x;
    int froggie_y = -1;
    std::cin >> froggie_x;

    std::string moves;
    std::cin >> moves;

    bool is_squished = false;
    for (const char& move : moves) {
        if (is_squished) break;

        if (move == 'U') ++froggie_y;
        if (move == 'D') --froggie_y;
        if (move == 'R') ++froggie_x;
        if (move == 'L') --froggie_x;

        if (0 <= froggie_y && froggie_y < lane_count)
            if (!lanes[froggie_y].is_safe_position(to_lane_position(froggie_x, froggie_y, lane_count, lane_width)))
                is_squished = true;

        for (int i = 0; i < lane_count; ++i) lanes[i].advance();
    }

    if (!is_squished && froggie_y >= lane_count) std::cout << "safe";
    else std::cout << "squish";

    return 0;
}
