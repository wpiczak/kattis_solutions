import sys

lines = [line.strip() for line in sys.stdin.readlines()]
line_count = int(lines[0])
lines = lines[1:][:line_count]

abbreviations = {
    "at": "@",
    "and": "&",
    "one": "1",
    "won": "1",
    "to": "2",
    "too": "2",
    "two": "2",
    "for": "4",
    "four": "4",
    "bea": "b",
    "be": "b",
    "bee": "b",
    "sea": "c",
    "see": "c",
    "eye": "i",
    "oh": "o",
    "owe": "o",
    "are": "r",
    "you": "u",
    "why": "y"
}

results = []
for line in lines:
    result = ""
    i = 0
    while i < len(line):
        for j in range(4, 1, -1):
            if i + j <= len(line):
                sequence = line[i:i + j].lower()
                if sequence in abbreviations:
                    if line[i].isupper():
                        result += abbreviations[sequence].upper()
                    else:
                        result += abbreviations[sequence]

                    i += j
                    break
        else:
            result += line[i]
            i += 1

    results.append(result)

for result in results:
    print(result)
