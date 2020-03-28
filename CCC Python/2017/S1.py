n = int(input())

swifts = input().split(" ")
swifts = [int(i) for i in swifts]

semaphores = input().split(" ")
semaphores = [int(i) for i in semaphores]

semaphores_runs = 0
swifts_runs = 0

longest = 0
for i in range(1, n+1):
    swifts_runs += swifts[i-1]
    semaphores_runs += semaphores[i-1]

    if swifts_runs == semaphores_runs:
        longest = i


print(longest)
