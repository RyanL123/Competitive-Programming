# gets user input
y = int(input())


# keeps increasing year until all digits are distinct
while True:

    # adds 1 to y
    y += 1

    y_set = set(str(y))

    if len(y_set) != len(str(y)):
        continue
    else:
        break


print(y)


