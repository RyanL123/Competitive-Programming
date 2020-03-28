# time starts at 1200
time = 1200

# how many minutes we are watching for
d = int(input())

counter = 0

if d >= 720:

    counter += (d//720)*31
    d %= 720


# keeps adding 1 minute and tests if the current time is an arithmetic sequence
for i in range(d):

    valid_time = False

    time += 1

    # if the there is 60 minutes on the minutes, convert it into an hour. If it is past 12 o' clock, set the time to 1
    if time % 100 == 60:

        time -= 60

        time += 100

        if time >= 1300:

            time -= 1200

    # Assumes that this is the difference of the arithmetic sequence
    sequence = int(str(time)[0]) - int(str(time)[1])

    for j in range(len(str(time))-1):

        #Checks if the rest of the string has this difference. If not, this is not a valid time
        if int(str(time)[j]) - int(str(time)[j+1]) != sequence:
            valid_time = False
            break
        else:
            valid_time = True

    if valid_time:
        counter += 1

print(counter)
