
# gets the string
string = input()

love_count = []

love = "love"

love_counter = 0

count = 0
# deletes all unnecessary characters
for i in string:
    if i in love:
        love_count.append(i)

if "l" not in love_count or "o" not in love_count or "v" not in love_count or "e" not in love_count:
    print("0")
    love_count = []

# gets rid of all characters before the first L
while True:
    if love_count[0] != "l":
        love_count.pop(0)
    else:
        break

love_count.reverse()

# gets rid of all characters after the last E
while True:
    if love_count[0] != "e":
        love_count.pop(0)
    else:
        break

# gets rid of all characters between the last E and the last V
i = 0
while True:
    if love_count[i] != "e" and love_count[i] != "v":
        love_count.pop(i)
        i -= 1
    elif love_count[i] == "v":
        break
    i += 1

# gets rid of all characters between the last V and the last O
while True:
    if love_count[i] != "v" and love_count[i] != "o":
        love_count.pop(i)
        i -= 1
    elif love_count[i] == "o":
        break
    i += 1

# gets rid of all characters between the last O and the last L
while True:
    if love_count[i] != "o" and love_count[i] != "l":
        love_count.pop(i)
        i -= 1
    elif love_count[i] == "l":
        break
    i += 1

love_count.reverse()
