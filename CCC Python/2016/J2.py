row1 = list(input().split())
row2 = list(input().split())
row3 = list(input().split())
row4 = list(input().split())

row1 = [int(i) for i in row1]
row2 = [int(i) for i in row2]
row3 = [int(i) for i in row3]
row4 = [int(i) for i in row4]

total = sum(row1)

if total == sum(row2) == sum(row3) == sum(row4):
    for i in range (4):
        if total == row1[i] + row2[i] + row3[i] + row4[i]:
            continue
        else:
            print("not magic")
            exit()

    print("magic")
else:
    print("not magic")