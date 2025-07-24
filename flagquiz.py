import sys


def calculate_rating(answer, other):
    return sum([answer[i] != other[i] for i in range(len(answer))])


def calculate_total_rating(answer):
    global answers
    return max([calculate_rating(answer, other) for other in answers])


lines = sys.stdin.readlines()
answers = [line.strip().split(', ') for line in lines[2:]]
ratings = [calculate_total_rating(answer) for answer in answers]
lowest_rating = min(ratings)

for i in range(len(answers)):
    if ratings[i] == lowest_rating:
        print(', '.join(answers[i]))
