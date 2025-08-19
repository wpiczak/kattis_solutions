#include <iomanip>
#include <iostream>
#include <queue>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int case_count;
    std::cin >> case_count;

    using offer = std::pair<int, int>; // (price, count)

    for (int i = 0; i < case_count; ++i) {
        int stock_price = -1;

        std::priority_queue<offer, std::vector<offer>, std::greater<>> ask_prices;
        std::priority_queue<offer, std::vector<offer>, std::less<>> bid_prices;

        int n;
        std::cin >> n;

        for (int j = 0; j < n; ++j) {
            std::string transaction;
            std::cin >> transaction;

            int count;
            int price;

            std::cin >> count;
            std::cin.ignore(11);
            std::cin >> price;

            if (transaction == "sell") ask_prices.emplace(price, count);
            if (transaction == "buy") bid_prices.emplace(price, count);

            while (!ask_prices.empty() && !bid_prices.empty()) {
                if (ask_prices.top().first > bid_prices.top().first) break;

                auto ask_price = ask_prices.top();
                auto bid_price = bid_prices.top();
                ask_prices.pop();
                bid_prices.pop();

                const int common_count = std::min(ask_price.second, bid_price.second);
                ask_price.second -= common_count;
                bid_price.second -= common_count;
                stock_price = ask_price.first;

                if (ask_price.second > 0) ask_prices.push(ask_price);
                if (bid_price.second > 0) bid_prices.push(bid_price);
            }

            if (!ask_prices.empty()) std::cout << ask_prices.top().first;
            else std::cout << '-';

            std::cout << ' ';
            if (!bid_prices.empty()) std::cout << bid_prices.top().first;
            else std::cout << '-';

            std::cout << ' ';
            if (stock_price != -1) std::cout << stock_price;
            else std::cout << '-';

            std::cout << '\n';
        }
    }

    return 0;
}
