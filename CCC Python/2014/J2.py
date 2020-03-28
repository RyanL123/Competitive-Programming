vote_count = int(input())
votes = list(input())

A = votes.count("A")
B = votes.count("B")

if A > B:
    print("A")
elif B > A:
    print("B")
else:
    print("Tie")
