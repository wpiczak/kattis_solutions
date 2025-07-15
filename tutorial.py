import math

m, n, t = [int(value) for value in input().split()]

calculation_count = 0
MAX = 10 ** 9 + 1
if t == 1:
    if n >= 13:
        calculation_count = MAX
    else:
        calculation_count = math.factorial(n)
elif t == 2:
    if n >= 30:
        calculation_count = MAX
    else:
        calculation_count = 2 ** n
elif t == 3:
    calculation_count = n ** 4
elif t == 4:
    calculation_count = n ** 3
elif t == 5:
    calculation_count = n ** 2
elif t == 6:
    calculation_count = n * math.log2(n)
elif t == 7:
    calculation_count = n

if calculation_count <= m:
    print("AC")
else:
    print("TLE")
