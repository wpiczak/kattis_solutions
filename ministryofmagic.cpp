#include <iostream>
#include <limits>
#include <vector>

struct election {
    int candidate_count;
    int party_count;
    int total_vote_count = 0;

    std::vector<std::vector<int>> candidate_rankings;
    std::vector<int> vote_counts;

    std::vector<bool> is_eliminated;
    std::vector<int> preference_indices;
    int eliminated_count = 0;

    election(const int candidate_count, const int party_count) : candidate_count{candidate_count},
                                                                 party_count{party_count} {
        candidate_rankings.resize(party_count, std::vector<int>(candidate_count));
        vote_counts.resize(party_count, 0);
        is_eliminated.resize(candidate_count, false);
        preference_indices.resize(party_count, 0);
    }

    int next_round() {
        const auto result = count_votes();

        const int winner = get_winner(result);
        if (winner != -1) return winner;

        const int loser = get_loser(result);
        eliminate(loser);

        return -1;
    }

    std::vector<int> count_votes() const {
        std::vector<int> result(candidate_count, 0);
        for (int i = 0; i < party_count; ++i)
            result[candidate_rankings[i][preference_indices[i]]] += vote_counts[i];

        return result;
    }

    int get_winner(const std::vector<int>& result) const {
        int winner = -1;
        int score = -1;
        for (int i = 0; i < candidate_count; ++i) {
            if (result[i] > score) {
                winner = i;
                score = result[i];
            }
        }

        if (2 * score > total_vote_count)
            return winner;
        return -1;
    }

    int get_loser(const std::vector<int>& result) const {
        int loser = -1;
        int score = std::numeric_limits<int>::max();
        for (int i = 0; i < candidate_count; ++i) {
            if (is_eliminated[i]) continue;

            if (result[i] < score) {
                loser = i;
                score = result[i];
            }
        }

        return loser;
    }

    void eliminate(const int candidate_index) {
        if (eliminated_count >= candidate_count - 1)
            throw std::logic_error("only one candidate remaining");

        is_eliminated[candidate_index] = true;
        for (int i = 0; i < party_count; ++i) {
            int& j = preference_indices[i];
            while (is_eliminated[candidate_rankings[i][j]]) ++j;
        }

        ++eliminated_count;
    }
};

election initialize() {
    int candidate_count;
    int party_count;
    std::cin >> candidate_count >> party_count;

    auto result = election{candidate_count, party_count};
    for (int i = 0; i < party_count; ++i) {
        int input;
        std::cin >> input;
        result.vote_counts[i] = input;
        result.total_vote_count += input;

        for (int j = 0; j < candidate_count; ++j) {
            std::cin >> input;
            result.candidate_rankings[i][j] = input - 1;
        }
    }

    return result;
}

int main() {
    std::iostream::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto magical_election = initialize();

    int winner;
    do { winner = magical_election.next_round(); } while (winner == -1);

    std::cout << winner + 1 << '\n';

    return 0;
}
