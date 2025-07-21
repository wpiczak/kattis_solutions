#include <iostream>

std::string remove_trailing_zeros(std::string number) {
    const std::size_t pos = number.find_last_not_of('0');
    return number.erase(pos + 1, std::string::npos);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string dividend;
    std::string divisor;
    std::cin >> dividend >> divisor;

    const std::size_t log10 = divisor.length() - 1;
    if (log10 >= dividend.length())
        dividend.insert(0, log10 - dividend.size() + 1, '0');

    const std::size_t dot_index = dividend.size() - log10;
    const std::string integer_part = dividend.substr(0, dot_index);
    const std::string fractional_part = remove_trailing_zeros(dividend.substr(dot_index, std::string::npos));

    std::cout << integer_part;
    if (!fractional_part.empty()) std::cout << '.' << fractional_part;

    return 0;
}
