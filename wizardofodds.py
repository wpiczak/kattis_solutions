n, k = input().split()
n = int(n)
k = int(k)

if k > 350 or 2 ** k >= n:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
