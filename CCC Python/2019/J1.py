apple = 0
bananas = 0
apple1 = int(input())
apple2 = int(input())
apple3 = int(input())
apple += apple1*3
apple += apple2*2
apple += apple3

bananas1 = int(input())
bananas2 = int(input())
bananas3 = int(input())
bananas += bananas1*3
bananas += bananas2*2
bananas += bananas3

if apple > bananas:
    print("A")
elif apple < bananas:
    print("B")
else:
    print("T")
