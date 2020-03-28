n = int(input())
points = []

A = 100
D = 100
for i in range(n):
    points.append(input().split())

for i in range(0, len(points)):
    if int(points[i][0]) > int(points[i][1]):
        D -= int(points[i][0])
    elif int(points[i][0]) < int(points[i][1]):
        A -= int(points[i][1])

print(A)
print(D)
