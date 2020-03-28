instructions = []

while True:
    instructions.append(input())
    if instructions[-1] == "SCHOOL":
        break

instructions.pop()
instructions.reverse()

for i in range(len(instructions)):
    if instructions[i] == "L":
        instructions[i] = "RIGHT"
    elif instructions[i] == "R":
        instructions[i] = "LEFT"

second_last = instructions[-1]

instructions.pop()
for i in range(0, len(instructions), 2):
    print("Turn " + instructions[i] + " onto " + instructions[i+1] + " street.")

print("Turn " + second_last + " into your HOME.")
