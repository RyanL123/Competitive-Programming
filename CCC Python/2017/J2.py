n = int(input())
k = int(input())
shifted_sum = 0
for i in range (1,k+1):
    shifted_sum += n*(10**i)
shifted_sum += n
print(shifted_sum)