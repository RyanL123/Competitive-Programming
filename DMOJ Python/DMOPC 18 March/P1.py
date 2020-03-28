n = int(input())
molecules = ["A", "C", "G", "T", "U"]
bases = input()

DNA = False
RNA = False
neither = False

for i in range(n):
    if bases[i] == "T":
        DNA = True
    elif bases[i] == "U":
        RNA = True
    elif bases[i] not in molecules:
        neither = True
        break

if neither:
    print("neither")
elif DNA and RNA:
    print("neither")
elif not DNA and not RNA:
    print("both")
elif DNA:
    print("DNA")
elif RNA:
    print("RNA")
