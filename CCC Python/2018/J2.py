parkingSpaces = int(input())
yesterday = str(input())
today = str(input())
occupied = 0
for i in range (parkingSpaces):
    if yesterday[i - 1] == today[i - 1] == 'C':
        occupied += 1
print(occupied)
