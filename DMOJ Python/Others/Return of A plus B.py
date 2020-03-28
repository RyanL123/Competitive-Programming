n = int(input())

addition = []

for i in range(n):
    a = input().split()
    addition.append(int(a[0])+int(a[1]))

for i in range(n):
    print(addition[i])
