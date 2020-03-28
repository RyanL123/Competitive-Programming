query = input().split()

query = [int(i) for i in query]

if query.count(0) == 3:
    print("YES")
elif query.count(0) == 2:
    print("YES")
elif query.count(0) == 1:
    if query[0] == 0:
        if query[1] == 3:
            print("NO")
        else:
            print("YES")
    elif query[1] == 0:
        if query[0] == 3:
            print("NO")
        else:
            print("YES")
    elif query[2] == 0:
        if query[0] == 2:
            print("NO")
        else:
            print("YES")

elif query.count(0) == 0:
    print("NO")
