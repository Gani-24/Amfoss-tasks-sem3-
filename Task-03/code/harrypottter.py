answords = []
reqspell, wordsinspell = map(int, input().split())

spellpairs = []
for i in range(wordsinspell):
    spellpairs.append(tuple(input().split()))


input_words = input().split()


for word in input_words:
    found_match = False
    for pair in spellpairs:
        if word in pair:
            sameword = pair[0] if word == pair[1] else pair[1]
            answords.append(word if len(word) <= len(sameword) else sameword)
            found_match = True
            break
    if not found_match:
        answords.append(word)


print(*answords)
