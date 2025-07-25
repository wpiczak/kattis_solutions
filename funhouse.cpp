#include <iostream>
#include <vector>

std::pair<int, int> find_entrance(const std::vector<std::string>& diagram) {
    const int width = static_cast<int>(diagram[0].length());
    const int length = static_cast<int>(diagram.size());

    for (int i = 0; i < width; ++i)
        if (diagram[0][i] == '*')
            return {0, i};

    for (int i = 1; i < length - 1; ++i) {
        if (diagram[i][0] == '*') return {i, 0};
        if (diagram[i][width - 1] == '*') return {i, width - 1};
    }

    for (int i = 0; i < width; ++i)
        if (diagram[length - 1][i] == '*')
            return {length - 1, i};

    return {-1, -1};
}

class diagram {
public:
    void construct(const int width, const int height) {
        width_ = width;
        height_ = height;

        diagram_.resize(height);
        for (int i = 0; i < height; ++i)
            std::cin >> diagram_[i];
    }

    void mark_exit() {
        locate_entrance();
        while (diagram_[y_][x_] != 'x') next();
        diagram_[y_][x_] = '&';
    }

    void display() const {
        for (const auto& line : diagram_)
            std::cout << line << '\n';
    }

private:
    std::vector<std::string> diagram_;
    int width_ = 0;
    int height_ = 0;

    int x_ = -1;
    int y_ = -1;
    int direction_x_ = 0;
    int direction_y_ = 0;

    void next() {
        if (direction_x_ == 1) {
            for (int i = x_ + 1; i < width_; ++i) {
                const char symbol = diagram_[y_][i];
                if (symbol == '/') direction_y_ = -1;
                else if (symbol == '\\') direction_y_ = 1;
                else if (symbol != 'x') continue;

                x_ = i;
                direction_x_ = 0;
                return;
            }
        } else if (direction_x_ == -1) {
            for (int i = x_ - 1; i >= 0; --i) {
                const char symbol = diagram_[y_][i];
                if (symbol == '/') direction_y_ = 1;
                else if (symbol == '\\') direction_y_ = -1;
                else if (symbol != 'x') continue;

                x_ = i;
                direction_x_ = 0;
                return;
            }
        } else if (direction_y_ == 1) {
            for (int i = y_ + 1; i < height_; ++i) {
                const char symbol = diagram_[i][x_];
                if (symbol == '/') direction_x_ = -1;
                else if (symbol == '\\') direction_x_ = 1;
                else if (symbol != 'x') continue;

                y_ = i;
                direction_y_ = 0;
                return;
            }
        } else if (direction_y_ == -1) {
            for (int i = y_ - 1; i >= 0; --i) {
                const char symbol = diagram_[i][x_];
                if (symbol == '/') direction_x_ = 1;
                else if (symbol == '\\') direction_x_ = -1;
                else if (symbol != 'x') continue;

                y_ = i;
                direction_y_ = 0;
                return;
            }
        }
    }

    void locate_entrance() {
        for (int i = 0; i < width_; ++i) {
            if (diagram_[0][i] == '*') {
                x_ = i;
                y_ = 0;
                direction_y_ = 1;
            }
        }

        for (int i = 1; i < height_ - 1; ++i) {
            if (diagram_[i][0] == '*') {
                x_ = 0;
                y_ = i;
                direction_x_ = 1;
            } else if (diagram_[i][width_ - 1] == '*') {
                x_ = width_ - 1;
                y_ = i;
                direction_x_ = -1;
            }
        }

        for (int i = 0; i < width_; ++i) {
            if (diagram_[height_ - 1][i] == '*') {
                x_ = i;
                y_ = height_ - 1;
                direction_y_ = -1;
            }
        }
    }
};

int main() {
    int width;
    int length;
    std::cin >> width >> length;

    int index = 0;
    while (width != 0 && length != 0) {
        auto house = diagram{};
        house.construct(width, length);
        house.mark_exit();
        std::cout << "HOUSE " << ++index << '\n';
        house.display();

        std::cin >> width >> length;
    }

    return 0;
}
