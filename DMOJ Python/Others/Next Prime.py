from math import sqrt
n = int(input())
prime = True
while True:
    if n == 1:
        n += 1
    for i in range (2,round(sqrt(n))+1):
        if n%i != 0:
            prime = True
        else:
            prime = False
            break

    if prime == False:
        n += 1
    else:
        print(n)
        break