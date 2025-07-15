#include <algorithm>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

struct window {
    int index;
    int start_x;
    int start_y;
    int end_x;
    int end_y;

    window(const int index, const int x, const int y, const int width, const int height) :
        index{index}, start_x{x}, start_y{y}, end_x{x + width - 1}, end_y{y + height - 1} {
        if (start_x > end_x || start_y > end_y) throw std::logic_error("invalid window");
    }

    int width() const { return end_x - start_x + 1; }

    int height() const { return end_y - start_y + 1; }

    bool contains(const int x, const int y) const { return start_x <= x && x <= end_x && start_y <= y && y <= end_y; }

    bool overlaps(const window& other) const {
        const int overlap_start_x = std::max(start_x, other.start_x);
        const int overlap_start_y = std::max(start_y, other.start_y);
        const int overlap_end_x = std::min(end_x, other.end_x);
        const int overlap_end_y = std::min(end_y, other.end_y);
        return overlap_end_x >= overlap_start_x && overlap_end_y >= overlap_start_y;
    }

    void resize(const int width, const int height) {
        end_x = start_x + width - 1;
        end_y = start_y + height - 1;
    }

    bool operator==(const window& other) const {
        return index == other.index
            && start_x == other.start_x && start_y == other.start_y
            && end_x == other.end_x && end_y == other.end_y;
    }
};

int horizontal_distance(const window& first, const window& second) {
    if (first == second) return 0;
    return std::max(
        second.start_x - first.end_x - 1,
        first.start_x - second.end_x - 1
    );
}

int vertical_distance(const window& first, const window& second) {
    if (first == second) return 0;
    return std::max(
        second.start_y - first.end_y - 1,
        first.start_y - second.end_y - 1
    );
}

struct window_manager {
    int screen_width;
    int screen_height;
    std::vector<window> windows;

    window_manager(const int screen_width, const int screen_height) :
        screen_width{screen_width}, screen_height{screen_height} {}

    std::string open(const window& new_window) {
        if (!fits(new_window)) return "window does not fit";

        windows.push_back(new_window);

        return "success";
    }

    std::string resize(const int x, const int y, const int width, const int height) {
        const int i = find(x, y);
        if (i == windows.size()) return "no window at given position";

        const auto original_window = windows[i];
        windows.erase(windows.begin() + i);

        auto new_window = original_window;
        new_window.resize(width, height);

        if (!fits(new_window)) {
            windows.push_back(original_window);
            return "window does not fit";
        }

        windows.push_back(new_window);
        return "success";
    }

    std::string close(const int x, const int y) {
        const int i = find(x, y);
        if (i == windows.size()) return "no window at given position";

        windows.erase(windows.begin() + i);
        return "success";
    }

    std::string move(const int x, const int y, const int delta_x, const int delta_y) {
        const int i = find(x, y);
        if (i == windows.size()) return "no window at given position";

        int distance = 0;
        if (std::abs(delta_x) != 0)
            distance = std::abs(move_horizontally(i, delta_x));
        if (std::abs(delta_y) != 0)
            distance = std::abs(move_vertically(i, delta_y));

        if (distance == std::abs(delta_x + delta_y))
            return "success";

        return "moved " + std::to_string(distance) + " instead of " + std::to_string(std::abs(delta_x + delta_y));
    }

private:
    bool fits(const window& new_window) const {
        if (new_window.start_x < 0 || new_window.end_x >= screen_width) return false;
        if (new_window.start_y < 0 || new_window.end_y >= screen_height) return false;

        return std::all_of(windows.cbegin(), windows.cend(), [&](const window& window) {
            return !new_window.overlaps(window);
        });
    }

    int find(const int x, const int y) const {
        for (int i = 0; i < windows.size(); ++i)
            if (windows[i].contains(x, y)) return i;
        return static_cast<int>(windows.size());
    }

    int move_horizontally(const int i, const int delta) {
        const auto selected = windows[i];
        if (delta > 0) return move_rightward(selected, delta);
        if (delta < 0) return move_leftward(selected, -delta);
        return 0;
    }

    int move_vertically(const int i, const int delta) {
        const auto selected = windows[i];
        if (delta > 0) return move_downward(selected, delta);
        if (delta < 0) return move_upward(selected, -delta);
        return 0;
    }

    int move_forward(
        const window& selected, const int target_distance, const int axis_length,
        const std::function<int(const window&, const window&)>& axis_distance,
        const std::function<int&(window&)>& start_coordinate,
        const std::function<int&(window&)>& end_coordinate
    ) {
        std::sort(windows.begin(), windows.end(), [&](window& first, window& second) {
            return start_coordinate(first) < start_coordinate(second);
        });

        int selected_index = 0;
        std::vector<int> distance_from_boundary(windows.size());
        for (int i = static_cast<int>(windows.size()) - 1; i >= 0; --i) {
            auto affected_region = windows[i];
            end_coordinate(affected_region) = axis_length;

            distance_from_boundary[i] = axis_length - end_coordinate(windows[i]) - 1;
            for (int j = static_cast<int>(windows.size()) - 1; j > i; --j) {
                if (!windows[j].overlaps(affected_region)) continue;
                distance_from_boundary[i] = std::min(
                    distance_from_boundary[i],
                    distance_from_boundary[j] + axis_distance(windows[i], windows[j])
                );
            }

            if (windows[i] == selected) {
                selected_index = i;
                break;
            }
        }

        const int real_distance = std::min(target_distance, distance_from_boundary[selected_index]);

        std::vector<int> delta(windows.size());
        delta[selected_index] = real_distance;

        for (int i = selected_index; i < static_cast<int>(windows.size()); ++i) {
            if (delta[i] == 0) continue;
            auto affected_region = windows[i];
            end_coordinate(affected_region) += delta[i];

            for (int j = i + 1; j < static_cast<int>(windows.size()); ++j) {
                if (!windows[j].overlaps(affected_region)) continue;
                delta[j] = std::max(
                    delta[j],
                    delta[i] - axis_distance(windows[i], windows[j])
                );
            }
        }

        for (int i = selected_index; i < static_cast<int>(windows.size()); ++i) {
            start_coordinate(windows[i]) += delta[i];
            end_coordinate(windows[i]) += delta[i];
        }

        return real_distance;
    }

    int move_backward(
        const window& selected, const int target_distance,
        const std::function<int(const window&, const window&)>& axis_distance,
        const std::function<int&(window&)>& start_coordinate,
        const std::function<int&(window&)>& end_coordinate
    ) {
        std::sort(windows.begin(), windows.end(), [&](window& first, window& second) {
            return end_coordinate(first) > end_coordinate(second);
        });

        int selected_index = 0;
        std::vector<int> distance_from_boundary(windows.size());
        for (int i = static_cast<int>(windows.size()) - 1; i >= 0; --i) {
            auto affected_region = windows[i];
            start_coordinate(affected_region) = 0;

            distance_from_boundary[i] = start_coordinate(windows[i]);
            for (int j = static_cast<int>(windows.size()) - 1; j > i; --j) {
                if (!windows[j].overlaps(affected_region)) continue;
                distance_from_boundary[i] = std::min(
                    distance_from_boundary[i],
                    distance_from_boundary[j] + axis_distance(windows[i], windows[j])
                );
            }

            if (windows[i] == selected) {
                selected_index = i;
                break;
            }
        }

        const int real_distance = std::min(target_distance, distance_from_boundary[selected_index]);

        std::vector<int> delta(windows.size());
        delta[selected_index] = real_distance;

        for (int i = selected_index; i < static_cast<int>(windows.size()); ++i) {
            if (delta[i] == 0) continue;
            auto affected_region = windows[i];
            start_coordinate(affected_region) -= delta[i];

            for (int j = i + 1; j < static_cast<int>(windows.size()); ++j) {
                if (!windows[j].overlaps(affected_region)) continue;
                delta[j] = std::max(
                    delta[j],
                    delta[i] - axis_distance(windows[i], windows[j])
                );
            }
        }

        for (int i = selected_index; i < static_cast<int>(windows.size()); ++i) {
            start_coordinate(windows[i]) -= delta[i];
            end_coordinate(windows[i]) -= delta[i];
        }

        return real_distance;
    }

    int move_rightward(const window& selected, const int target_distance) {
        return move_forward(
            selected, target_distance, screen_width,
            horizontal_distance,
            [](window& window) -> int& { return window.start_x; },
            [](window& window) -> int& { return window.end_x; }
        );
    }

    int move_leftward(const window& selected, const int target_distance) {
        return move_backward(
            selected, target_distance,
            horizontal_distance,
            [](window& window) -> int& { return window.start_x; },
            [](window& window) -> int& { return window.end_x; }
        );
    }

    int move_downward(const window& selected, const int target_distance) {
        return move_forward(
            selected, target_distance, screen_height,
            vertical_distance,
            [](window& window) -> int& { return window.start_y; },
            [](window& window) -> int& { return window.end_y; }
        );
    }

    int move_upward(const window& selected, const int target_distance) {
        return move_backward(
            selected, target_distance,
            vertical_distance,
            [](window& window) -> int& { return window.start_y; },
            [](window& window) -> int& { return window.end_y; }
        );
    }
};

int main() {
    int screen_width;
    int screen_height;
    std::cin >> screen_width >> screen_height;

    auto manager = window_manager{screen_width, screen_height};

    std::string command;
    std::cin >> command;
    int i = 1;
    while (std::cin && !command.empty()) {
        if (command == "OPEN") {
            int x, y, w, h;
            std::cin >> x >> y >> w >> h;
            const std::string response = manager.open(window{i, x, y, w, h});
            if (response != "success") std::cout << "Command " << i << ": OPEN - " << response << '\n';
        } else if (command == "CLOSE") {
            int x, y;
            std::cin >> x >> y;
            const std::string response = manager.close(x, y);
            if (response != "success") std::cout << "Command " << i << ": CLOSE - " << response << '\n';
        } else if (command == "RESIZE") {
            int x, y, w, h;
            std::cin >> x >> y >> w >> h;
            const std::string response = manager.resize(x, y, w, h);
            if (response != "success") std::cout << "Command " << i << ": RESIZE - " << response << '\n';
        } else if (command == "MOVE") {
            int x, y, dx, dy;
            std::cin >> x >> y >> dx >> dy;
            const std::string response = manager.move(x, y, dx, dy);
            if (response != "success") std::cout << "Command " << i << ": MOVE - " << response << '\n';
        }

        std::cin >> command;
        ++i;
    }

    std::sort(manager.windows.begin(), manager.windows.end(), [](const window& first, const window& second) {
        return first.index < second.index;
    });

    std::cout << manager.windows.size() << " window(s):\n";
    for (const auto& window : manager.windows)
        std::cout << window.start_x << ' ' << window.start_y << ' ' << window.width() << ' ' << window.height() << '\n';

    return 0;
}
