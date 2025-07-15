def time_to_seconds(time: str) -> int:
    hour, minute, second = map(int, time.split(":"))
    return 3600 * hour + 60 * minute + second


def seconds_to_time(seconds: int) -> str:
    hour = seconds // 3600
    minute = seconds // 60 - hour * 60
    second = seconds - minute * 60 - hour * 3600
    return f'{hour:02d}:{minute:02d}:{second:02d}'


current_time = input()
explosion_time = input()

seconds_until_explosion = (time_to_seconds(explosion_time) - time_to_seconds(current_time)) % (24 * 60 * 60)

if seconds_until_explosion == 0:
    print("24:00:00")
else:
    print(seconds_to_time(seconds_until_explosion))
