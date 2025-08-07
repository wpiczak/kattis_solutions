import sys

lines = sys.stdin.readlines()

for line in lines[:-1]:
    n = int(line) - 1
    elements = []

    i = 0
    while n != 0:
        if n % 2 == 1:
            elements.append(str(3 ** i))
        n = n // 2
        i += 1

    print("{ " + ", ".join(elements) + " }")
