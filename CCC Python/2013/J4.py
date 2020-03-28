# total amount of minutes
minutes = int(input())

# gets the total number of chores
number_of_chores = int(input())

# creates list to store all the chores
chores = []
for i in range (number_of_chores):
    chores.append(int(input()))

# sorts chores in increasing order
chores.sort()

# if it takes less than the required time to do all of the chores, print the amount of chores that were given
if sum(chores) <= minutes:
    print(len(chores))

# else keep adding up chores until they exceed the time limit
else:
    count = 0
    total = 0

    while total < minutes:
        total += chores[count]
        count += 1

    if total > minutes:
        print(count-1)
    else:
        print(count)
