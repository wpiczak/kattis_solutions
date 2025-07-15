from itertools import permutations

days_in_month = {
    1: 31,
    2: 28,
    3: 31,
    4: 30,
    5: 31,
    6: 30,
    7: 31,
    8: 31,
    9: 30,
    10: 31,
    11: 30,
    12: 31
}


def is_valid_date(year: int, month: int, day: int) -> bool:
    global days_in_month

    if month == 2 and year % 4 == 0 and (year % 100 != 0 or year % 400 == 0):
        return 1 <= day <= 29

    return 1 <= month <= 12 and 1 <= day <= days_in_month[month]


ambiguous_date = input()
numbers = list(map(lambda number: int(number), ambiguous_date.split('/')))

possible_dates = [(year + (2000 if year < 100 else 0), month, day) for year, month, day in permutations(numbers)]
valid_dates = sorted([date for date in possible_dates if is_valid_date(*date)])

if len(valid_dates) == 0:
    print(ambiguous_date, "is illegal")
else:
    year, month, day = valid_dates[0]
    print(f"{year}-{month:02d}-{day:02d}")
