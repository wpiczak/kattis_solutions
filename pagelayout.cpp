#include <iostream>
#include <vector>

struct story {
    int width{0};
    int height{0};
    int x{0};
    int y{0};

    [[nodiscard]] int area() const { return width * height; }
};

bool intersect(const story& first, const story& second) {
    const int overlap_start_x = std::max(first.x, second.x);
    const int overlap_start_y = std::max(first.y, second.y);
    const int overlap_end_x = std::min(first.x + first.width, second.x + second.width);
    const int overlap_end_y = std::min(first.y + first.height, second.y + second.height);
    const int overlap_width = std::max(overlap_end_x - overlap_start_x, 0);
    const int overlap_height = std::max(overlap_end_y - overlap_start_y, 0);
    return overlap_width * overlap_height > 0;
}

int get_maximum_area(
    std::vector<bool>& selected,
    const std::vector<story>& stories,
    const int area = 0,
    const int index = 0
) {
    int result = area;

    for (int i = index; i < stories.size(); ++i) {
        bool can_be_added = true;
        for (int j = 0; j < index; ++j) {
            if (selected[j] && intersect(stories[i], stories[j])) {
                can_be_added = false;
                break;
            }
        }

        if (can_be_added) {
            selected[i] = true;
            result = std::max(get_maximum_area(selected, stories, area + stories[i].area(), i + 1), result);
            selected[i] = false;
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int story_count;
    std::cin >> story_count;

    while (story_count != 0) {
        std::vector<story> stories(story_count);
        for (int i = 0; i < story_count; ++i) {
            std::cin >> stories[i].width;
            std::cin >> stories[i].height;
            std::cin >> stories[i].x;
            std::cin >> stories[i].y;
        }

        std::vector<bool> selected(story_count);
        std::cout << get_maximum_area(selected, stories) << '\n';

        std::cin >> story_count;
    }

    return 0;
}
