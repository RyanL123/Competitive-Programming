n = int(input())

colors = []

pink = 0
for i in range(n):
    colors.append(list(input().split()))

for i in range(n):
    if 240 <= int(colors[i][0]) <= 255 and 0 <= int(colors[i][1]) <= 200 and 95 <= int(colors[i][2]) <= 220:
        pink += 1

print(pink)
