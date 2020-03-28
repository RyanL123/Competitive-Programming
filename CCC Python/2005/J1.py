daytime = float(input())
evening = float(input())
weekend = float(input())

planA = 0
planB = 0

if daytime <= 100:
    planA = round(100*(evening*0.15 + weekend*0.2))
    planA /=100
else:
    planA = round(100*((daytime - 100)*0.25 + evening*0.15 + weekend*0.2))
    planA /= 100

if daytime <= 250:
    planB = round(100*(evening*0.35 + weekend*0.25))
    planB /= 100
else:
    planB = round(100*((daytime - 250)*0.45 + evening*0.35 + weekend*0.25))
    planB /= 100

print("Plan A costs " + str(planA))
print("Plan B costs " + str(planB))
if planA < planB:
    print("Plan A is cheapest.")
elif planA > planB:
    print("Plan B is cheapest.")
else:
    print("Plan A and B are the same price.")
