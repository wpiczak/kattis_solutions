#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

namespace {
    unsigned long long choose(const int n, const int k) {
        if (k < 0 || k > n) return 0;
        if (k == 0 || k == n) return 1;
        return n * choose(n - 1, k - 1) / k;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<double> probabilities(4);
    for (int i = 0; i < 4; ++i)
        std::cin >> probabilities[i];

    std::priority_queue<
        std::pair<long double, unsigned long long>,
        std::vector<std::pair<long double, unsigned long long>>,
        std::greater<>
    > queue;

    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n - a; ++b) {
            for (int c = 0; c <= n - a - b; ++c) {
                const int d = n - a - b - c;

                double probability = 1;
                probability *= std::pow(probabilities[0], a);
                probability *= std::pow(probabilities[1], b);
                probability *= std::pow(probabilities[2], c);
                probability *= std::pow(probabilities[3], d);

                auto count = choose(n, a) * choose(n - a, b) * choose(n - a - b, c);

                queue.emplace(probability, count);
            }
        }
    }

    long double result = 0;
    while (!queue.empty()) {
        auto [first_probability, first_count] = queue.top();
        queue.pop();

        if (first_count == 1) {
            auto [second_probability, second_count] = queue.top();
            queue.pop();

            result += first_probability + second_probability;

            if (second_count != 1) {
                queue.emplace(second_probability, second_count - 1);
                queue.emplace(first_probability + second_probability, 1);
            } else {
                if (queue.empty()) break;
                queue.emplace(first_probability + second_probability, 1);
            }

            continue;
        }

        if (first_count == 2 && queue.empty()) {
            result += first_probability * 2;
            break;
        }

        queue.emplace(first_probability * 2, first_count / 2);

        if (first_count & 1) {
            result += first_probability * (first_count - 1);
            queue.emplace(first_probability, 1);
        } else result += first_probability * first_count;
    }

    std::cout << std::setprecision(16) << result << '\n';

    return 0;
}
