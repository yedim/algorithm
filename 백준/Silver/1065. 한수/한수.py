N = int(input())
cnt = 0

for i in range(1, N+1):
    X = list(map(int, str(i)))

    if len(X) == 1 or len(X) == 2:
        cnt += 1
    else:
        sub = X[1] - X[0]
        hansu = True
        
        for i in range(len(X)-1):
            if X[i+1] - X[i] != sub:
                hansu = False

        if hansu:
            cnt += 1
            
print(cnt)