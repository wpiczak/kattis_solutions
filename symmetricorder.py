n = int(input())

index = 1
while n != 0:
    lines = [input() for _ in range(n)]

    print(f'SET {index}')
    print('\n'.join(lines[::2]))
    print('\n'.join(reversed(lines[1::2])))

    index += 1
    n = int(input())
