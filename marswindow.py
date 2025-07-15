year = int(input())
offset = 12 * year + 11 - (2018 * 12 + 3)
result = (offset - 26 * (offset // 26)) < 12
print("yes" if result else "no")
