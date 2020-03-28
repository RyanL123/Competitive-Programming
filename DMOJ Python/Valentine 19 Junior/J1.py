n = int(input())

ratings = []
for i in range(n):
    ratings.append(int(input()))

for i in ratings:
    if i < 1000:
        print("Newbie")
    elif 1000 <= i <= 1199:
        print("Amateur")
    elif 1200 <= i <= 1499:
        print("Expert")
    elif 1500 <= i <= 1799:
        print("Candidate Master")
    elif 1800 <= i <= 2199:
        print("Master")
    elif 2200 <= i <= 2999:
        print("Grandmaster")
    elif 3000 <= i <= 3999:
        print("Target")
    else:
        print("Rainbow Master")

