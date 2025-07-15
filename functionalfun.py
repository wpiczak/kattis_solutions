import sys


def parse(lines: list[str], start: int) -> tuple[str, int]:
    domain = lines[start].split(' ')[1:]
    codomain = lines[start + 1].split(' ')[1:]
    value_set = set()
    function = dict()

    is_injective = True

    mapping_count = int(lines[start + 2])
    for i in range(start + 3, start + 3 + mapping_count):
        x, y = lines[i].split(" -> ")

        if y in value_set:
            is_injective = False
        else:
            value_set.add(y)

        if x not in function:
            function[x] = y
        else:
            return "not a function", start + 3 + mapping_count

    is_surjective = (len(value_set) == len(codomain))

    if is_surjective and is_injective:
        return "bijective", start + 3 + mapping_count
    if is_surjective:
        return "surjective", start + 3 + mapping_count
    if is_injective:
        return "injective", start + 3 + mapping_count
    return "neither injective nor surjective", start + 3 + mapping_count


lines = sys.stdin.readlines()

index = 0
while index < len(lines):
    result, index = parse(lines, index)
    print(result)
