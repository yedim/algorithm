N = int(input())

for i in range(N):
    word = input()
    lst = []
    tmp = ''
    
    for j in word:
        if j == tmp:
            continue

        if j in lst:
            N -= 1
            break

        lst.append(j)
        tmp = j
            
print(N)