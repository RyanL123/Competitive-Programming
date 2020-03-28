valid = ["I", "O", "S", "H", "Z", "X", "N"]

word = input()

valid_word = True

for i in range(0, len(word)):
    if word[i] not in valid:
        valid_word = False
    else:
        continue

if valid_word:
    print("YES")

else:
    print("NO")
