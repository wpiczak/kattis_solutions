task_count, interval_count = map(int, input().split())
task_durations = sorted(map(int, input().split()))
interval_durations = sorted(map(int, input().split()))

result = 0

i, j = 0, 0
while i < task_count and j < interval_count:
    if task_durations[i] <= interval_durations[j]:
        i += 1
        result += 1

    j += 1

print(result)
