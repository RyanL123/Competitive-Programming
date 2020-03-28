quarters = int(input())
slot1 = int(input())
slot2 = int(input())
slot3 = int(input())
times_played = 0
slots = [slot1, slot2, slot3]

while quarters != 0:

    if quarters == 0:
        break
    else:
        quarters -= 1
        times_played += 1
        slots[0] += 1
        if slots[0] == 35:
            slots[0] = 0
            quarters += 30

    if quarters == 0:
        break
    else:
        quarters -= 1
        times_played += 1
        slots[1] += 1
        if slots[1] == 100:
            slots[1] = 0
            quarters += 60

    if quarters == 0:
        break
    else:
        quarters -= 1
        times_played += 1
        slots[2] += 1
        if slots[2] == 10:
            slots[2] = 0
            quarters += 9
    if quarters == 0:
        break


print("Martha plays " + str(times_played) + " times before going broke.")