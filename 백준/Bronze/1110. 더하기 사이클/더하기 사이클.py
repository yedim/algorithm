N = list(map(int, input()))
if len(N) < 2:
    N.insert(0, 0)

n = N
i = 1

while True:
    n = [n[1], n[0] + n[1]]
    if n[1] >= 10:
        n[1] %= 10

    if N == n:
        break

    i += 1

print(i)