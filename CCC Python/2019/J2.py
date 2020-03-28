l = int(input())
code = []
for i in range(l):
    code.append(list(input().split(" ")))


for i in range(len(code)):
    for j in range(int(code[i][0])):
        print(code[i][1], end="")
    print("")
