instructions = []
while True:
    commands = input()
    if commands[0] == "7":
        break
    else:
        instructions.append(list(commands.split()))

A = 0
B = 0
for i in range(len(instructions)):
    if instructions[i][0] == "1":
        if instructions[i][1] == "A":
            A = int(instructions[i][2])
        else:
            B = int(instructions[i][2])
    elif instructions[i][0] == "2":
        if instructions[i][1] == "A":
            print(A)
        else:
            print(B)
    elif instructions[i][0] == "3":
        if instructions[i][1] == "A" and instructions[i][2] == "B":
            A += B
        elif instructions[i][1] == "B" and instructions[i][2] == "A":
            B += A
        elif instructions[i][1] == "B" and instructions[i][2] == "B":
            B += B
        else:
            A += A
    elif instructions[i][0] == "4":
        if instructions[i][1] == "A" and instructions[i][2] == "B":
            A *= B
        elif instructions[i][1] == "B" and instructions[i][2] == "A":
            B *= A
        elif instructions[i][1] == "B" and instructions[i][2] == "B":
            B *= B
        else:
            A *= A
    elif instructions[i][0] == "5":
        if instructions[i][1] == "A" and instructions[i][2] == "B":
            A -= B
        elif instructions[i][1] == "B" and instructions[i][2] == "A":
            B -= A
        elif instructions[i][1] == "B" and instructions[i][2] == "B":
            B = 0
        else:
            A = 0
    elif instructions[i][0] == "6":
        if instructions[i][1] == "A" and instructions[i][2] == "B" :
            A = A//B
        elif instructions[i][1] == "B" and instructions[i][2] == "A" :
            B = B//A
        elif instructions[i][1] == "B" and instructions[i][2] == "B":
            B = B//B
        else:
            A = A//A
