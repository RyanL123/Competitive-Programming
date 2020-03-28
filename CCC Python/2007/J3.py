n = int(input())
opened = []

for i in range(n):
    opened.append(int(input()))

bank_offer = int(input())

total = 1691600
for i in range(len(opened)):
    if opened[i] == 1:
        total -= 100
    elif opened[i] == 2:
        total -= 500
    elif opened[i] == 3:
        total -= 1000
    elif opened[i] == 4:
        total -= 5000
    elif opened[i] == 5:
        total -= 10000
    elif opened[i] == 6:
        total -= 25000
    elif opened[i] == 7:
        total -= 50000
    elif opened[i] == 8:
        total -= 100000
    elif opened[i] == 9:
        total -= 500000
    elif opened[i] == 10:
        total -= 1000000

total /= 10-n

if bank_offer > total:
    print("deal")
else:
    print("no deal")
