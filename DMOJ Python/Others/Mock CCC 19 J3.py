# gets the amount of restaurants
t = int(input())

# creates prices list
prices = []

# creates list to store answers
answer = []

# initializes exactly_equal variable to False
exactly_equal = False

# stores every input into a 2D array
for i in range(t):
    prices.append(list(input().split()))

# loops through the 2D array
for i in range(t):

    # if both the prices add up to the budget, or one of the prices is the same as the budget the answer is YES
    if int(prices[i][2]) == int(prices[i][0]) + int(prices[i][1]) or int(prices[i][2]) == int(prices[i][0]) \
            or int(prices[i][2]) == int(prices[i][1]):
        answer.append("YES")

    # if not, check every combination of the 2 orders. If 1 of the combinations add up exactly to her budget,
    # the answer is YES
    else:
        for j in range(1, int(prices[i][2])+1):
            # if some combination of the two adds up exactly to the budget, the answer is YES and break
            if exactly_equal:
                answer.append("YES")
                break
            for k in range(1, int(prices[i][2])+1):

                # if the combination does not add up to the budget, continue the loop
                if int(prices[i][0])*j + int(prices[i][1])*k != int(prices[i][2]):
                    continue

                # else the combination does add up exactly equal to the budget, set exactly_equal to True and break
                else:
                    exactly_equal = True
                    break
        if not exactly_equal:
            answer.append("NO")

        # resets exactly_equal back to False
        exactly_equal = False

for i in range(len(answer)):
    print(answer[i])
