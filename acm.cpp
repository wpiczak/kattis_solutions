#include <bits/stdc++.h>

int main() {
  int correctCount = 0, wrongCount = 0;
  int scorePerQuestion[26];
  bool solved[26];
  
  std::fill(scorePerQuestion, scorePerQuestion + 26, 0);
  std::fill(solved, solved + 26, false);
  
  int time;
  char question, verdict[6];
  while (scanf("%d %c %s\n", &time, &question, verdict) == 3) {
    if (verdict[0] == 'r') {
      correctCount++;
      scorePerQuestion[question - 'A'] += time;
      solved[question - 'A'] = true;
    } else if (verdict[0] == 'w') {
      wrongCount++;
      scorePerQuestion[question - 'A'] += 20;
    }
  }
  
  int score = 0;
  for (int i = 0; i < 26; i++)
    if (solved[i]) score += scorePerQuestion[i];
  printf("%d %d", correctCount, score);
  
  return 0;
}
