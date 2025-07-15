#include <bits/stdc++.h>

int main() {
  int caseCount;
  scanf("%d", &caseCount);
  
  for (int i = 0; i < caseCount; i++) {
    int candidateCount;
    scanf("%d", &candidateCount);
    
    int totalVotes = 0, winner = 1, winnerVotes = 0;
    bool winnerExists = false;
    for (int candidate = 1; candidate <= candidateCount; candidate++) {
      int votes;
      scanf("%d", &votes);
      totalVotes += votes;
      if (votes > winnerVotes) {
        winnerVotes = votes;
        winner = candidate;
        winnerExists = true;
      } else if (votes == winnerVotes) winnerExists = false;
    }
    
    if (!winnerExists) printf("no winner\n");
    else if (2 * winnerVotes <= totalVotes) printf("minority winner %d\n", winner);
    else if (2 * winnerVotes > totalVotes) printf("majority winner %d\n", winner);
  }
  
  return 0;
}
