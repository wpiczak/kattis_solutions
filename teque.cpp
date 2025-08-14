#include <deque>
#include <iostream>

void balance(std::deque<int>& left, std::deque<int>& right) {
    if (left.size() > right.size() + 1) {
        right.push_front(left.back());
        left.pop_back();
    } else if (left.size() < right.size()) {
        left.push_back(right.front());
        right.pop_front();
    }
}

int get(const std::deque<int>& left, const std::deque<int>& right, const int index) {
    if (index < left.size()) return left.at(index);
    return right.at(index - left.size());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int operation_count;
    std::cin >> operation_count;

    std::deque<int> left;
    std::deque<int> right;

    for (int i = 0; i < operation_count; ++i) {
        std::string operation;
        std::cin >> operation;

        int parameter;
        std::cin >> parameter;

        if (operation == "get") std::cout << get(left, right, parameter) << '\n';
        else if (operation == "push_back") right.push_back(parameter);
        else if (operation == "push_front") left.push_front(parameter);
        else if (operation == "push_middle") left.push_back(parameter);

        balance(left, right);
    }

    return 0;
}
