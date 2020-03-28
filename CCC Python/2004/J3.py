n = int(input())

m = int(input())

adjectives = []
nouns = []
for i in range(n):
    adjectives.append(input())

for i in range(m):
    nouns.append(input())

for i in adjectives:
    for j in nouns:
        print(i + " as " + j)
