# gets starting time
input = input().split(":")
input = [int(i) for i in input]

# converts starting time into an integer
time = input[0]*60
time += input[1]

distance = 240

# while there is still distance left, decrease the time left and add time elapsed
while distance > 0:
    if 420 <= time < 600 or 15*60 <= time < 19*60:
        time += 1
        distance -= 1
    else:
        time += 1
        distance -= 2

# if the time gets past 12am reset it back to 1
if time > 2400:
    time -= 2400

# prints arrival time
print('%02d:%02d' % (time/60 % 24, time % 60))
