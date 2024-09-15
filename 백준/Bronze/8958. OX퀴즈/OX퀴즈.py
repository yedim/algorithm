N = int(input())

for i in range(N):
    score = 0
    k = 0
    lst = list(input())

    for i in range(len(lst)):
        if lst[i] == 'O':
            k += 1
            score += k
        elif lst[i] == 'X':
            k = 0

    print(score)