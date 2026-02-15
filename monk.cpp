#include <algorithm>
#include <iostream>
#include <vector>

double height(
    const double time,
    const std::vector<int>& distances,
    const std::vector<int>& durations,
    const std::vector<double>& speeds
) {
    const auto i = std::ranges::lower_bound(durations, time) - durations.begin() - 1;
    return distances[i] + speeds[i] * (time - durations[i]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ascent_segment_count;
    int descent_segment_count;
    std::cin >> ascent_segment_count >> descent_segment_count;

    std::vector<int> ascent_distances(ascent_segment_count);
    std::vector<int> ascent_durations(ascent_segment_count);
    std::vector<double> ascent_speeds(ascent_segment_count);

    std::vector<int> descent_distances(descent_segment_count);
    std::vector<int> descent_durations(descent_segment_count);
    std::vector<double> descent_speeds(descent_segment_count);

    int ascent_distance = 0;
    int ascent_duration = 0;
    for (int i = 0; i < ascent_segment_count; ++i) {
        ascent_distances[i] = ascent_distance;
        ascent_durations[i] = ascent_duration;

        int distance;
        int duration;
        std::cin >> distance >> duration;

        ascent_distance += distance;
        ascent_duration += duration;
        ascent_speeds[i] = static_cast<double>(distance) / duration;
    }

    int descent_distance = 0;
    int descent_duration = 0;
    for (int i = 0; i < descent_segment_count; ++i) {
        descent_distances[i] = descent_distance;
        descent_durations[i] = descent_duration;

        int distance;
        int duration;
        std::cin >> distance >> duration;

        descent_distance += distance;
        descent_duration += duration;
        descent_speeds[i] = static_cast<double>(distance) / duration;
    }

    double start = 0;
    double end = std::min(ascent_duration, descent_duration);
    for (int i = 0; i < 128; ++i) {
        const double center = (start + end) / 2;
        const double ascent_delta = height(center, ascent_distances, ascent_durations, ascent_speeds);
        const double descent_delta = height(center, descent_distances, descent_durations, descent_speeds);
        if (descent_distance - descent_delta - ascent_delta > 0) start = center;
        else end = center;
    }

    std::cout << (start + end) / 2;

    return 0;
}
