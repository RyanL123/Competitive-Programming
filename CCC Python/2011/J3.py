sumac = []

sumac.append(int(input()))

sumac.append(int(input()))

# continues adding to the sumac list until the second last term is greater than the last
while sumac[len(sumac)-2] >= sumac[len(sumac)-1]:
    next_term = abs(sumac[len(sumac)-1] - sumac[len(sumac)-2])
    sumac.append(next_term)

# prints the length of the list
print(len(sumac))
