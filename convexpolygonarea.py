polygon_count = int(input())

for _ in range(polygon_count):
    tokens = input().split()
    n = int(tokens[0])

    coordinates = []
    for i in range(n):
        coordinates.append((
            int(tokens[2 * i + 1]),
            int(tokens[2 * i + 2])
        ))
    coordinates.append(coordinates[0])

    area = 0
    for i in range(n):
        a, b = coordinates[i]
        c, d = coordinates[i + 1]
        area += (a * d - b * c) / 2

    print(area)
