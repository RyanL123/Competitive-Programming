a, b = input().split()
c, d = input().split()
fuel = int(input())

a = int(a)
b = int(b)
c = int(c)
d = int(d)

y_diff = abs(d - b)
x_diff = abs(c - a)

if x_diff + y_diff == fuel:
    print("Y")
elif x_diff + y_diff < fuel:
    if (x_diff + y_diff - fuel)%2 == 0:
        print("Y")
    else:
        print("N")
else:
    print("N")