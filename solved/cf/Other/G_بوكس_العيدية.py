import random

N = int(input())
SIM = 1000000

total = 0

for _ in range(SIM):
    collected = set()
    draws = 0

    while len(collected) < N:
        x = random.randint(1, N)
        collected.add(x)
        draws += 1

    total += draws

print(total / SIM)