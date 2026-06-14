n = int(input())
word = input()

if 'lv' in word:
    print(0)
elif 'l' in word or 'v' in word:
    print(1)
else:
    print(2)
