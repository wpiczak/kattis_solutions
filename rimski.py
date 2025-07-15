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


def to_roman_numeral(decimal_numeral: int) -> str:
    if not 1 <= decimal_numeral <= 99:
        return "?"

    return tens[decimal_numeral // 10 * 10] + ones[decimal_numeral % 10]


input_roman_numeral = input()

target = sorted(input_roman_numeral)
for i in range(1, 100):
    if sorted(to_roman_numeral(i)) == target:
        print(to_roman_numeral(i))
        break
