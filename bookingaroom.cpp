#include <array>
#include <iomanip>
#include <iostream>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int room_count;
    int booked_room_count;
    std::cin >> room_count >> booked_room_count;

    std::array<bool, 100> booked{};
    for (int i = 0; i < booked_room_count; ++i) {
        int room;
        std::cin >> room;
        booked[room] = true;
    }

    if (booked_room_count < room_count) {
        for (int i = 1; i <= room_count; ++i) {
            if (!booked[i]) {
                std::cout << i;
                break;
            }
        }
    } else std::cout << "too late";

    return 0;
}
