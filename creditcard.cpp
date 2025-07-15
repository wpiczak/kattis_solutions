#include <cmath>
#include <iostream>

long long calculate_interest(const long long scaled_rate, const long long balance_in_cents) {
    long long result = scaled_rate * balance_in_cents;
    if (result % 10000 < 5000) result = result / 10000;
    else result = result / 10000 + 1;
    return result;
}

int calculate_repayment_time(const double rate, const double balance, const double payment) {
    auto balance_in_cents = static_cast<long long>(std::round(balance * 100));
    const auto payment_in_cents = static_cast<long long>(std::round(payment * 100));
    const auto scaled_rate = static_cast<long long>(std::round(rate * 100));

    for (int i = 0; i < 1200; ++i) {
        const long long interest = calculate_interest(scaled_rate, balance_in_cents);
        balance_in_cents += interest;
        balance_in_cents -= payment_in_cents;

        if (balance_in_cents <= 0) return i + 1;

        if (payment_in_cents <= interest)
            return -1;
    }

    return -1;
}

int main() {
    int case_count;
    std::cin >> case_count;
    
    for (int i = 0; i < case_count; ++i) {
        double rate;
        double balance;
        double payment;
    
        std::cin >> rate >> balance >> payment;
    
        int repayment_time = calculate_repayment_time(rate, balance, payment);
        if (repayment_time == -1) std::cout << "impossible\n";
        else std::cout << repayment_time << '\n';
    }
    
    return 0;
}
