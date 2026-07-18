total_width = int(input())
piece_count = int(input())

area = 0
for i in range(piece_count):
    width, length = map(int, input().split())
    area += length * width

print(area // total_width)
