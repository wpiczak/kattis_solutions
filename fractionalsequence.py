import math

n = int(input())

whole = 0
while whole * (whole + 1) // 2 < n:
    whole += 1

a, b = n - (whole - 1) * whole // 2 - 1, whole
gcd = math.gcd(a, b)
a, b = a // gcd, b // gcd

if a != 0:
    print(f'{whole} {a}/{b}')
else:
    print(whole)
