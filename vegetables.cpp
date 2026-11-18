#include <iostream>
#include <queue>

namespace {
    struct piece_group {
        int weight;
        int size;

        [[nodiscard]] double individual_weight() const {
            return static_cast<double>(weight) / size;
        }

        auto operator<=>(const piece_group &other) const {
            return individual_weight() <=> other.individual_weight();
        }
    };

    std::ostream &operator<<(std::ostream &stream, const piece_group piece) {
        stream << piece.weight << ':' << piece.size << '=' << piece.individual_weight() << '\n';
        return stream;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double ratio;
    int count;
    std::cin >> ratio >> count;

    double minimum_weight = 1'000'000;
    std::priority_queue<piece_group> queue;
    for (int i = 0; i < count; ++i) {
        int weight;
        std::cin >> weight;

        minimum_weight = std::min(static_cast<double>(weight), minimum_weight);
        queue.emplace(weight, 1);
    }

    int cut_count = 0;
    while (true) {
        auto current = queue.top();
        queue.pop();

        if (minimum_weight / current.individual_weight() > ratio)
            break;

        ++current.size;
        ++cut_count;
        minimum_weight = std::min(current.individual_weight(), minimum_weight);
        queue.push(current);
    }

    std::cout << cut_count;

    return 0;
}
