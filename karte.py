labels = input()
deck = {
    'P': [False] * 13,
    'K': [False] * 13,
    'H': [False] * 13,
    'T': [False] * 13
}

error = False
for i in range(len(labels) // 3):
    label = labels[3 * i: 3 * i + 3]
    suit = label[0]
    index = int(label[1:]) - 1

    if deck[suit][index]:
        error = True
        break

    deck[suit][index] = True

if error:
    print('GRESKA')
else:
    result = []
    for suit in ['P', 'K', 'H', 'T']:
        result.append(13 - sum(deck[suit]))
    print(' '.join(map(str, result)))
