word = input()

steps = [["A"], ["G", "B"], ["M", "H", "C"], ["S", "N", "I", "D"], ["Y", "T", "O", "J", "E"], ["Z", "U", "P", "K", "F"]
         , [" ", "V", "Q", "L"], ["-", "W", "R"], [".", "X"]]

count = 0
previousJ = 0
for i in range(len(word)):
    for j in range(len(steps)):
        if word[i] in steps[j]:
            count += abs(j-previousJ)
            previousJ = j
            break

count += 9-previousJ
print(count)
