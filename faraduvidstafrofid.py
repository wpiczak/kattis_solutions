def is_vowel(char: str):
    return char.lower() in ['a', 'e', 'i', 'o', 'u']


letters = list(input())

vowels = [letter for letter in letters if is_vowel(letter)]

vowel_index = 0
for i in range(len(letters)):
    if is_vowel(letters[i]):
        vowel_index += 1
        letters[i] = vowels[-vowel_index]

print(''.join(letters))
