import sys

vowels = {'a', 'e', 'i', 'o', 'u', 'y'}


def find_first_vowel(string: str) -> int:
    for i in range(len(string)):
        if string[i] in vowels:
            return i
    return -1


def translate(word):
    if word[0] in vowels:
        return word + "yay"
    else:
        first_vowel_index = find_first_vowel(word)
        return word[first_vowel_index:] + word[:first_vowel_index] + "ay"


messages = sys.stdin.readlines()
for message in messages:
    print(' '.join([translate(word) for word in message.strip().split(' ')]))
