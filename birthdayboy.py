month_start_indices = [
    0,
    31,
    59,
    90,
    120,
    151,
    181,
    212,
    243,
    273,
    304,
    334
]


def date_to_index(month: int, day: int) -> int:
    return month_start_indices[month - 1] + day - 1


def index_to_date(index: int) -> tuple[int, int]:
    for i in range(11):
        if month_start_indices[i + 1] > index:
            return i + 1, index - month_start_indices[i] + 1
    return 12, index - month_start_indices[-1] + 1


colleague_count = int(input())
birthdays = []
for i in range(colleague_count):
    line = input()
    month, day = map(int, line.split()[1].split("-"))
    birthdays.append((month, day))

birthday_indices = sorted([date_to_index(*birthday) for birthday in birthdays])

result = birthday_indices[0] - 1
largest_gap = birthday_indices[0] + 365 - birthday_indices[-1]

for i in range(1, len(birthday_indices)):
    if birthday_indices[i] - birthday_indices[i - 1] > largest_gap:
        result = birthday_indices[i] - 1
        largest_gap = birthday_indices[i] - birthday_indices[i - 1]
    elif birthday_indices[i] - birthday_indices[i - 1] == largest_gap:
        if (birthday_indices[i] - 1 - date_to_index(10, 28)) % 365 < (result - date_to_index(10, 28)) % 365:
            result = birthday_indices[i] - 1
            largest_gap = birthday_indices[i] - birthday_indices[i - 1]

month, day = index_to_date(result % 365)
print(f"{month:02d}-{day:02d}")
