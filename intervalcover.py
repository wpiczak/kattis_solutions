import sys

lines = [line.strip() for line in sys.stdin.readlines()]
lines.reverse()

while len(lines) > 0:
    start, end = map(float, lines[-1].split())
    lines.pop()

    n = int(lines[-1])
    lines.pop()

    intervals: list[tuple[int, tuple[float, float]]] = []
    for i in range(n):
        a, b = map(float, lines[-1].split())
        lines.pop()

        intervals.append((i, (a, b)))

    intervals.sort(key=lambda entry: (entry[1][0], -entry[1][1]))

    used_indices: list[int] = []

    i = 0
    covered = False
    current_end = start
    while i < len(intervals):
        a, b = intervals[i][1]

        if a <= current_end <= b:
            max_end = b

            j = i + 1
            while j < len(intervals):
                c, d = intervals[j][1]

                if c > current_end:
                    break
                if d > max_end:
                    max_end = d
                    i = j

                j += 1

            used_indices.append(intervals[i][0])
            current_end = max_end

        if (start < end <= current_end) or (start == end and len(used_indices) > 0):
            covered = True
            break

        i += 1

    if covered:
        print(len(used_indices))
        print(' '.join(map(str, used_indices)))
    else:
        print('impossible')
