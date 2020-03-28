s = input()

a = 1
b = 2
c = 3
d = 4
for i in range(len(s)):
    if s[i] == "H":
        a,c = c,a
        b,d = d,b
    else:
        a,b = b,a
        c,d = d,c

print(str(a) + " " + str(b))
print(str(c) + " " + str(d))
