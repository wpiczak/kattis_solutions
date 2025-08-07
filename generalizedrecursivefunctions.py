def f(x, y, a, b, c, d, lookup_table):
    if x <= 0 or y <= 0:
        return d
    if lookup_table[x][y] != -1:
        return lookup_table[x][y]

    result = c
    for i in range(len(a)):
        temp = f(x - a[i], y - b[i], a, b, c, d, lookup_table)
        if x - a[i] > 0 and y - b[i] > 0:
            lookup_table[x - a[i]][y - b[i]] = temp
        result += temp

    return result


case_count = int(input())

for i in range(case_count):
    if i != 0:
        print()

    parameters = input().split()
    c = int(parameters[-2])
    d = int(parameters[-1])

    n = len(parameters) // 2 - 1
    a = [int(parameters[2 * j]) for j in range(n)]
    b = [int(parameters[2 * j + 1]) for j in range(n)]

    lookup_table = [[-1] * 100 for _ in range(100)]

    inputs = input().split()
    x_inputs = [int(inputs[2 * j]) for j in range(len(inputs) // 2)]
    y_inputs = [int(inputs[2 * j + 1]) for j in range(len(inputs) // 2)]

    for x, y in zip(x_inputs, y_inputs):
        print(f(x, y, a, b, c, d, lookup_table))
