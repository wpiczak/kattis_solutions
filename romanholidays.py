ones = {
    0: "",
    1: "I",
    2: "II",
    3: "III",
    4: "IV",
    5: "V",
    6: "VI",
    7: "VII",
    8: "VIII",
    9: "IX"
}

tens = {
    0: "",
    10: "X",
    20: "XX",
    30: "XXX",
    40: "XL",
    50: "L",
    60: "LX",
    70: "LXX",
    80: "LXXX",
    90: "XC"
}

hundreds = {
    0: "",
    100: "C",
    200: "CC",
    300: "CCC",
    400: "CD",
    500: "D",
    600: "DC",
    700: "DCC",
    800: "DCCC",
    900: "CM",
}


def to_roman_numeral(decimal_numeral: int) -> str:
    if decimal_numeral < 1:
        return ""

    thousands_digit = decimal_numeral // 1000
    hundreds_digit = decimal_numeral // 100
    tens_digit = decimal_numeral // 10

    ones_digit = decimal_numeral - tens_digit * 10
    tens_digit = tens_digit - hundreds_digit * 10
    hundreds_digit = hundreds_digit - thousands_digit * 10

    return "M" * thousands_digit + hundreds[hundreds_digit * 100] + tens[tens_digit * 10] + ones[ones_digit]


roman_numerals = [to_roman_numeral(i) for i in range(1, 1000 + 1)]
roman_numerals.sort()

input_count = int(input())
for i in range(input_count):
    numeral = int(input())

    thousands_count = numeral // 1000
    remainder = to_roman_numeral(numeral - thousands_count * 1000)

    if not remainder:
        result = 946 * thousands_count
    else:
        remainder_index = roman_numerals.index(remainder)

        if remainder_index < 945:
            result = 946 * thousands_count + remainder_index + 1
        else:
            result = -54 * thousands_count + remainder_index - 1000

    print(result)
