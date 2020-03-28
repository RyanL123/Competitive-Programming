digitOne = int(input())
digitTwo = int(input())
digitThree = int(input())
digitFour = int(input())

if digitOne == 8 or digitOne == 9:
    if digitFour == 8 or digitFour == 9:
        if digitTwo == digitThree:
            print("ignore")
        else:
            print("answer")
    else:
        print("answer")
else:
    print("answer")