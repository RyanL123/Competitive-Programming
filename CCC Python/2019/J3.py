n = int(input())

characters = []

for i in range(n):
    characters.append(list(input()))

characters_count = []
for i in range(len(characters)):
    char_count = 1
    for j in range(len(characters[i])):
        if j != len(characters[i])-1:
            if characters[i][j] == characters[i][j+1]:
                char_count += 1

            else:
                characters_count.append(char_count)
                char_count = 1
        else:
            break

    characters_count.append(char_count)


for i in range(n):
    k = 0
    for j in range(len(characters[i])):
        if k != len(characters[i])-1:
            if characters[i][k] == characters[i][k+1]:
                characters[i].pop(k)
            else:
                k += 1
s = 0
for i in range(n):
    for j in range(len(characters[i])):
        print(str(characters_count[s]) + " " + str(characters[i][j]) + " ", end = "")
        s += 1
    print("")
