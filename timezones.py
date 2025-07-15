from __future__ import annotations

zones = {
    "UTC": 0,
    "GMT": 0,
    "BST": 1,
    "IST": 1,
    "WET": 0,
    "WEST": 1,
    "CET": 1,
    "CEST": 2,
    "EET": 2,
    "EEST": 3,
    "MSK": 3,
    "MSD": 4,
    "AST": -4,
    "ADT": -3,
    "NST": -3.5,
    "NDT": -2.5,
    "EST": -5,
    "EDT": -4,
    "CST": -6,
    "CDT": -5,
    "MST": -7,
    "MDT": -6,
    "PST": -8,
    "PDT": -7,
    "HST": -10,
    "AKST": -9,
    "AKDT": -8,
    "AEST": 10,
    "AEDT": 11,
    "ACST": 9.5,
    "ACDT": 10.5,
    "AWST": 8
}


class Time:
    def __init__(self, hour: int, minute: int):
        total_minutes = hour * 60 + minute
        total_minutes = total_minutes % 1440

        self.hour: int = int(total_minutes // 60)
        self.minute: int = int(total_minutes % 60)

    def advance(self, minutes: int) -> Time:
        return Time(self.hour, self.minute + minutes)

    def __str__(self) -> str:
        if self.hour == 0 and self.minute == 0:
            return "midnight"
        if self.hour == 12 and self.minute == 0:
            return "noon"

        if self.hour == 0:
            return f"12:{self.minute:02d} a.m."
        if self.hour == 12:
            return f"12:{self.minute:02d} p.m."

        if self.hour < 12:
            return f"{self.hour}:{self.minute:02d} a.m."
        return f"{self.hour - 12}:{self.minute:02d} p.m."

    @classmethod
    def from_string(cls, string: str) -> Time:
        if string == "midnight":
            return Time(0, 0)
        if string == "noon":
            return Time(12, 0)

        string, day_part = string.split(" ")
        hour = int(string.split(":")[0])
        minute = int(string.split(":")[1])

        if hour == 12:
            if day_part == "p.m.":
                return Time(12, minute)
            return Time(0, minute)

        if day_part == "p.m.":
            return Time(hour + 12, minute)
        return Time(hour, minute)


case_count = int(input())
for i in range(case_count):
    line = input()
    time, current_zone, target_zone = line.rsplit(" ", 2)
    zone_difference = zones[target_zone] - zones[current_zone]
    print(Time.from_string(time).advance(zone_difference * 60))
