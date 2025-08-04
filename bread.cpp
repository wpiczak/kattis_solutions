#include <iostream>
#include <vector>

std::size_t merge_and_count_inversions(
    const std::vector<int>& source,
    std::vector<int>& destination,
    const std::size_t start,
    const std::size_t middle,
    const std::size_t end
) {
    std::size_t i = start;
    std::size_t j = start;
    std::size_t k = middle;

    std::size_t result = 0;
    while (j < middle && k < end) {
        if (source[j] > source[k]) {
            destination[i++] = source[k++];
            result += middle - j;
        } else destination[i++] = source[j++];
    }

    while (j < middle) destination[i++] = source[j++];
    while (k < end) destination[i++] = source[k++];

    return result;
}

std::size_t inversion_count(std::vector<int>& numbers) {
    const std::size_t n = numbers.size();
    std::vector<int> auxiliary(numbers.size());
    std::size_t result = 0;

    for (std::size_t i = 1; i < numbers.size(); i *= 2) {
        for (std::size_t j = 0; j < numbers.size(); j += 2 * i) {
            result += merge_and_count_inversions(
                numbers, auxiliary,
                j, std::min(j + i, n), std::min(j + 2 * i, n)
            );
        }
        std::swap(auxiliary, numbers);
    }

    return result;
}

int main() {
    int bread_count;
    std::cin >> bread_count;

    std::vector<int> current_order(bread_count);
    std::vector<int> desired_order(bread_count);

    for (int i = 0; i < bread_count; ++i)
        std::cin >> current_order[i];
    for (int i = 0; i < bread_count; ++i)
        std::cin >> desired_order[i];

    const bool is_impossible = (inversion_count(current_order) - inversion_count(desired_order)) % 2;
    if (is_impossible) std::cout << "Impossible";
    else std::cout << "Possible";

    return 0;
}
