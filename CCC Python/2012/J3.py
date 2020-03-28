k = int(input())

text = [["*","x","*"], [" ", "x", "x"], ["*", " ", "*"]]

# prints the scaled version of a line
def print_scaled_line(line_nubmer):

    for i in range(3):

        for j in range(k):
            print(text[line_nubmer][i], end="")

    print("")

# prints the scaled line k times
for i in range(3):

    for j in range(k):

        print_scaled_line(i)
