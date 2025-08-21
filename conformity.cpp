#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int student_count;
    std::cin >> student_count;

    std::unordered_map<std::string, int> popularity;
    int highest_popularity = 0;
    for (int i = 0; i < student_count; ++i) {
        std::vector<int> courses(5);
        for (int j = 0; j < 5; ++j)
            std::cin >> courses[j];

        std::sort(courses.begin(), courses.end());

        std::string course_list;
        for (int j = 0; j < 5; ++j)
            course_list += std::to_string(courses[j]);

        const auto it = popularity.insert({course_list, 0}).first;
        ++it->second;

        highest_popularity = std::max(it->second, highest_popularity);
    }

    int conforming_student_count = 0;
    for (const auto& [_, count] : popularity)
        if (count == highest_popularity) conforming_student_count += count;

    std::cout << conforming_student_count;

    return 0;
}
