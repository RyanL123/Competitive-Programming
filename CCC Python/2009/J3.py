time = int(input())

PST = time - 300
MST = time - 200
CST = time - 100
EST = time
AST = time + 100
NST = time + 130

timezones = [PST, MST, CST, EST, AST, NST]
for i in range(len(timezones)):
    if timezones[i] > 2400:
        timezones[i] -= 2400
    elif timezones[i] < 0:
        timezones[i] += 2400
    elif timezones[i] % 100 > 59:
        timezones[i] -= 60
        timezones[i] += 100

print(str(time) + " in Ottawa")
print(str(timezones[0]) + " in Victoria")
print(str(timezones[1]) + " in Edmonton")
print(str(timezones[2]) + " in Winnipeg")
print(str(timezones[3]) + " in Toronto")
print(str(timezones[4]) + " in Halifax")
print(str(timezones[5]) + " in St. John's")
