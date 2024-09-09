C = int(input())

for i in range(C):
    N = list(map(int, input().split()))

    sum = 0
    cnt = 0
    
    for i in range(N[0]):
        sum += N[i+1]

    avg = sum/N[0]

    for i in range(N[0]):
        if N[i+1] > avg:
            cnt += 1

    print(f'{cnt/N[0]*100:.3f}%')