#include <array>
#include <iostream>
#include <unordered_set>

struct hash_pair {
    template<typename S, typename T>
    std::size_t operator()(const std::pair<S, T>& pair) const {
        const std::size_t hash1 = std::hash<S>{}(pair.first);
        const std::size_t hash2 = std::hash<S>{}(pair.second);

        return hash1 ^ hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2);
    }
};

std::pair<long long, long long> operator+(
    const std::pair<long long, long long>& first,
    const std::pair<long long, long long>& second
) {
    return {first.first + second.first, first.second + second.second};
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<std::pair<long long, long long>, 12> delta = {
        {
            {0, 2018},
            {2018, 0},
            {0, -2018},
            {-2018, 0},
            {1118, 1680},
            {1680, 1118},
            {1118, -1680},
            {1680, -1118},
            {-1118, 1680},
            {-1680, 1118},
            {-1118, -1680},
            {-1680, -1118},
        }
    };

    int n;
    std::cin >> n;

    std::unordered_set<std::pair<long long, long long>, hash_pair> coordinates;

    for (int i = 0; i < n; ++i) {
        long long x;
        long long y;
        std::cin >> x >> y;
        coordinates.insert({x, y});
    }

    std::size_t pair_count = 0;
    for (const auto& coordinate : coordinates)
        for (int i = 0; i < 12; ++i)
            if (coordinates.count(coordinate + delta[i]) == 1)
                ++pair_count;

    std::cout << pair_count / 2;

    return 0;
}
