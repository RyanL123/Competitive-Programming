# gets user input
starting_day, total_days = input().split()

# new variable storing same value as starting day - 1. Month starts on day 0
day = int(starting_day) - 1

# prints out calender headers
print("Sun Mon Tue Wed Thr Fri Sat")

# prints out initial spaces before day 1
for i in range(2 + 4 * (int(starting_day)-1)):
    print(" ", end="")

# loops through every single day
for i in range(1, int(total_days)+1):

    # prints the day number
    print(i, end="")

    # add 1 to the day counter
    day += 1

    # if the day is a saturday
    if day % 7 == 0:

        # print linebreak
        print("")

        # if the date is single digit
        if i < 9:

            # print 2 spaces
            print("  ", end="")

        # if the date is double digit
        else:
            # print 1 space
            print(" ", end="")

    # if the date is single digit, and it is not the last day of the week, and is not the last day
    if i < 9 and day % 7 != 0 and day - int(starting_day) + 1 != int(total_days):
        # print 3 spaces
        print("   ", end="")

    # if the date is double digit, and it is not the last day of the week, and is not the last day
    elif day % 7 != 0 and day - int(starting_day) + 1 != int(total_days):
        # print 2 spaces
        print("  ", end="")

print("")
