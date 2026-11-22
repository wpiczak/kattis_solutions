#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    while (case_count--) {
        int length;
        int ant_count;
        std::cin >> length >> ant_count;

        int earliest_time = 0;
        int latest_time = 0;
        for (int i = 0; i < ant_count; ++i) {
            int position;
            std::cin >> position;

            earliest_time = std::max(
                std::min(position, length - position),
                earliest_time
            );

            latest_time = std::max(
                std::max(position, length - position),
                latest_time
            );
        }

        std::cout << earliest_time << ' ' << latest_time << '\n';
    }

    return 0;
}
