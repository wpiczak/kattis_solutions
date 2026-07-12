k = int(input()) - 1

length = 1
while k >= 2 ** length:
    k -= 2 ** length
    length += 1

result = bin(k)[2:].rjust(length, '0')
result = result.replace('0', '4').replace('1', '7')
print(result)
