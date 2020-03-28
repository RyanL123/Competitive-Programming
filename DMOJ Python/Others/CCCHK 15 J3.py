# gets N and M
a = list(input().split())
n = int(a[0])
m = int(a[1])

count = 0

# gets every queen's positions
queen_position = []
for i in range(m):
    queen_position.append(list(input().split()))

checked = []
for i in range(n*n):
    checked.append([False, False])

# loops through every tile and checks if it's within the path of the queen
for i in range(0, m):
    for x in range(1, n+1):
        for y in range(1, n+1):

            if int(queen_position[i][0]) != x and int(queen_position[i][1]) != y and\
                    abs(int(queen_position[i][0]) - x) != abs(int(queen_position[i][1]) - y) and checked[x][y]  :
                count += 1
                queen




print(count)
